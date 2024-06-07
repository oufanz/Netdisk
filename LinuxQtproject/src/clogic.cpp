#include "clogic.h"
#define DEF_PATH "/home/oufan/Gitproject/Netdisk/"
void CLogic::setNetPackMap()
{
    NetPackMap(_DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(_DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
}

#define _DEF_COUT_FUNC_    cout << "clientfd:"<< clientfd << __func__ << endl;

//注册
void CLogic::RegisterRq(sock_fd clientfd,char* szbuf,int nlen)
{
    //cout << "clientfd:"<< clientfd << __func__ << endl;
    _DEF_COUT_FUNC_
    /* 1.拆包
     * 2.查数据库：查手机号和昵称是否存在
     * 3.写入数据库并且获取ID
     * 3.创建该人关于ID的目录
        */
    //拆包
    STRU_REGISTER_RQ *rq =(STRU_REGISTER_RQ*)szbuf;
    STRU_REGISTER_RS rs;//处理的回应
    bool res;
    //查手机
    char sqlstr[1000]="";
    sprintf(sqlstr,"select u_tel from t_user where u_tel = '%s';",rq->tel);
    list<string>lstRes;
    res = m_sql->SelectMysql(sqlstr,1,lstRes);//查询结果存到lstRes中，查询语句就一条
    if(!res){
        std::cout<<"error! : fail1:"<<sqlstr<<std::endl;
        return;
    }
    if(lstRes.size()!=0){
        //存在 返回
        rs.result = tel_is_exist;
        SendData(clientfd,(char*)&rs,sizeof(rs));
        return;
    }
    //查昵称是否存在
    sprintf(sqlstr,"select u_tel from t_user where u_name = '%s';",rq->name);
    res = m_sql->SelectMysql(sqlstr,1,lstRes);//查询结果存到lstRes中，查询语句就一条
    if(!res){
        std::cout<<"error! : fail2:"<<sqlstr<<std::endl;
    }
    if(lstRes.size()!=0){
        rs.result=name_is_exist;
        SendData(clientfd,(char*)&rs,sizeof(rs));
        return;
    }
    //插入到数据库中
    rs.result = register_success;
    sprintf(sqlstr,"insert into t_user(u_tel,u_password,u_name) values ('%s' , '%s' , '%s');",
            rq->tel,rq->password,rq->name);
    res = m_sql->UpdataMysql(sqlstr);
    if(!res){
        std::cout<<"error!select insert fail:"<<sqlstr<<std::endl;
        return;
    }
    //取出该人ID；
    sprintf(sqlstr,"select u_id from t_user where u_tel = '%s' and u_password = '%s';"
            ,rq->tel,rq->password);
    res = m_sql->SelectMysql(sqlstr,1,lstRes);
    if(!res) {
        std::cout<<"error!select select fail:"<<sqlstr<<std::endl;
        return;
    }
    int id = stoi(lstRes.front());
    lstRes.pop_front();

    char pathbuf[_MAX_PATH] = "";
    sprintf(pathbuf,"%s/userid/%d/",DEF_PATH,id);
    //创建路径
    umask(0);
    mkdir(pathbuf,0777);//创建目   录，并且设置权限0777
    SendData(clientfd,(char*)&rs,sizeof(rs));
}

//登录
void CLogic::LoginRq(sock_fd clientfd ,char* szbuf,int nlen)
{
    _DEF_COUT_FUNC_
    STRU_LOGIN_RQ *rq = (STRU_LOGIN_RQ*)szbuf;
    STRU_LOGIN_RS rs;
    char sqlstr[1000] ="";
    //根据手机号查其他数据;
    sprintf(sqlstr,"select u_id , u_password , u_name from t_user where u_tel = '%s' ",rq->tel);
    list<string>lstRes;
    bool res=m_sql->SelectMysql(sqlstr,3,lstRes);
    if(!res){
        std::cout<<"select fail:"<<sqlstr<<std::endl;
    }
    if(lstRes.size()==0){
        rs.result=tel_not_exist;
        SendData( clientfd , (char*)&rs , sizeof rs );
        return;
    }
    int id = stoi(lstRes.front());
    lstRes.pop_front();
    string strPassword = lstRes.front();
    lstRes.pop_front();
    string strName = lstRes.front();
    lstRes.pop_front();
    if(strcmp(rq->password,strPassword.c_str())!=0){
        rs.result=password_error;
        SendData( clientfd , (char*)&rs , sizeof rs );
        return;
    }
    rs.result=login_success;
    rs.userid=id;
    strcpy(rs.name,strName.c_str());
    //创建该用户
    UserInfo *info =nullptr;
    if(!m_mapIDToUserInfo.find(id,info)){
        info =new UserInfo;
    }else{
        //存在该用户，让其下线
    }
    //赋值
    info->name=strName;
    info->clientfd=clientfd;
    info->userid=id;
    //写入map
    m_mapIDToUserInfo.insert(id,info);
//    rs.m_lResult = password_error;
    SendData( clientfd , (char*)&rs , sizeof rs );
}
