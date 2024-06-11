#include "clogic.h"
#define DEF_PATH "/home/oufan/Gitproject/Netdisk/userid/"
void CLogic::setNetPackMap()
{
    NetPackMap(_DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(_DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
    NetPackMap(_DEF_PACK_UPLOAD_FILE_RQ)  = &CLogic::UploadFileRq;
    NetPackMap(_DEF_PACK_FILE_CONTENT_RQ)  = &CLogic::FileContentRq;
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

    char pathbuf[_MAX_PATH_SIZE] = "";
    sprintf(pathbuf,"%s%d/",DEF_PATH,id);
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
        //存在该用户，让其下线 todo
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

void CLogic::UploadFileRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_;
    //拆包
    STRU_UPLOAD_FILE_RQ *rq=(STRU_UPLOAD_FILE_RQ *)szbuf;
    std::cout<<rq->fileName<<endl;

    //查看是否妙传 todo
    //不是秒传

    //文件信息创建，打开文件
    FileInfo* info =new FileInfo;
    char strpath[1000]="";
    sprintf(strpath,"%s%d%s%s",DEF_PATH,rq->userid,rq->dir,rq->md5);//+userid+dir+name-md5;
    //printf("%s",strpath);
    //通过绝对路径打开文件，文件名字是MD5（防止文件被覆盖）
    info->absolutePath=strpath;
    info->dir=rq->dir;
    info->md5=rq->md5;
    info->size=rq->size;
    info->time=rq->time;
    info->type=rq->type;
    //info->fid=
    //使用Linux文件io操作;
    //绝对路径 +  方式：创建+权限
    info->fileFd=open(strpath,O_CREAT|O_WRONLY|O_TRUNC,00777);
    if(info->fileFd<0){
        std::cout<<"file open fail"<<std::endl;
        return;
    }
    int64_t user_time=rq->userid*getNumber()+rq->timestamp;
    m_mapTimestampToFileInfo.insert(user_time,info);
    //map存储文件信息
    //*************************************数据库************************************//
    //数据库记录：插入文件信息（引用计数），插入用户文件关系，查文件id'
    char sqlbuf[1000] = "";
    sprintf(sqlbuf,"insert into t_file ( f_size , f_path , f_MD5 , f_count , f_state , f_type ) values ( %d , '%s' , '%s' ,0 , 0 , 'file');",rq->size,strpath,rq->md5);
     bool res=m_sql->UpdataMysql(sqlbuf);
     if(!res){
         printf("insert fail: %s\n",sqlbuf);
     }
     sprintf(sqlbuf,"select f_id from t_file where f_path = '%s' and f_MD5='%s' ",strpath,rq->md5);
     list<string>lstRes;
     res = m_sql->SelectMysql(sqlbuf,1,lstRes);
     if(!res){
         printf("Select fail:%s\n",sqlbuf);
     }
     if(lstRes.size()>0){
         info->fid = stoi(lstRes.front());
     }
     lstRes.clear();
     //插入用户文件关系表
      sprintf(sqlbuf,"insert into t_user_file ( u_id , f_id , f_dir , f_name , f_uploadtime ) values( %d , %d , '%s' , '%s' , '%s' ); "
            ,rq->userid,info->fid,rq->dir,rq->fileName,rq->time);
      res=m_sql->UpdataMysql(sqlbuf);
      if(!res){
          printf("update fail:%s\n",sqlbuf);
      }
    //写回复包
    STRU_UPLOAD_FILE_RS rs;
    rs.fileid=info->fid;
    rs.result=1;
    rs.timestamp=rq->timestamp;
    rs.userid=rq->userid;
    SendData(clientfd,(char*)&rs,sizeof(rs));
}
/*
 * 拆包->文件信息提取到Info存储到Map,读取ID->
 */
void CLogic::FileContentRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_;
    //拆包
    STRU_FILE_CONTENT_RQ* rq = (STRU_FILE_CONTENT_RQ*)szbuf;
    //获取文件信息
    int64_t user_time = rq->userid*getNumber()+rq->timestamp;
    FileInfo* info = nullptr;
    //找到就赋值给info
    if(!m_mapTimestampToFileInfo.find(user_time,info)){
        std::cout<<"file not found"<<endl;
        return;
    }
    STRU_FILE_CONTENT_RS rs;
    //写入到文件中
     int len = write(info->fileFd,rq->content,rq->len);
     if(len!=rq->len){
         //失败 跳回到读取之前
         rs.result = 0;
         //文件描述符跳回去
         lseek(info->fileFd,-1*len,SEEK_CUR);
     }else{
         rs.result=1;
         info->pos+=len;
         //看是否到达末尾
         if(info->pos>=info->size){
             //是：关闭文件，回收Map结点
             close(info->fileFd);
             m_mapTimestampToFileInfo.erase(user_time);
             delete info;
             info=nullptr;
             //更新数据库，表示文件上传完成，可以使用;
             char sqlbuf[1000]="";
             sprintf(sqlbuf,"update t_file set f_state = 1 where f_id = %d ;",rq->fileid);
             bool res = m_sql->UpdataMysql(sqlbuf);
            if(!res){
                std::cout<<__func__<<"update fail:"<<sqlbuf<<endl;
            }
         }
     }
     rs.fileid=rq->fileid;
     rs.len=rq->len;
     rs.timestamp=rq->timestamp;
     rs.userid=rq->userid;
     //返回结果
     SendData(clientfd,(char*)&rs,sizeof rs);

}

