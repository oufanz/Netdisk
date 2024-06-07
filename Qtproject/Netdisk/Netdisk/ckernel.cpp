#include "ckernel.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFileInfo>
#include <QSettings>//配置文件需要的类
#include "TcpClientMediator.h"
#include "TcpServerMediator.h"
#include <QMessageBox>
#include <QDebug>
#include "md5.h"
#define MD5_KEY "ou_fan"
#define NetMap( a ) m_netPackMap[ a - _DEF_PACK_BASE ]
CKernel::CKernel(QObject *parent) : QObject(parent)
{
    //建立协议表
    setNetPackMap();
    // 加载配置文件
    loadIniFile();
#ifdef USE_SERVER
    m_tcpServer = new TcpServerMediator;
    connect(m_tcpServer,SIGNAL(SIG_ReadyData(uint,char*,int)),this,
            SLOT(slot_dealServerData(uint,char*,int)));
    //开启服务器
    m_tcpServer->OpenNet();
#endif
    //绑定网络信号与槽
    m_tcpClient = new TcpClientMediator;
    connect(m_tcpClient,SIGNAL(SIG_ReadyData(uint,char*,int)),this,
            SLOT(slot_dealClientData(uint,char*,int)));
    //填入服务端的ip地址
    m_tcpClient->OpenNet(m_ip.toStdString().c_str(),m_port.toInt());

    m_loginDialog = new LoginDialog;//登录窗口创建
    connect(m_loginDialog,SIGNAL(SIG_registerCommit(QString,QString,QString)),
               this,SLOT(slot_registerCommit(QString,QString,QString)));
    connect(m_loginDialog,SIGNAL(SIG_LoginCommit(QString,QString)),
               this,SLOT(slot_LoginCommit(QString,QString)));
    m_loginDialog->show();
    m_mainDialog = new MainDialog;// 创建 MainDialog 实例
    // 连接信号和槽
    connect(m_mainDialog, SIGNAL(SIG_close()), this, SLOT(slot_destroy()));
    //m_mainDialog -> show();// 显示 MainDialog
#ifdef USE_SERVER
    //测试对服务器发送数据
//    char strBuf[100]= "hello server";
//    int len=strlen("hello server")+1;
//    m_tcpClient->SendData(0,strBuf,len);//客户端一定发给服务器，套接字参数随意.
    //sizeof +数组名 数组大小 ，strlen()遇到'\0'前的大小
    //STRU_LOGIN_RQ rq;
    //m_tcpClient->SendData(0,(char*)&rq,sizeof(rq));
#endif

}

//建立协议表
void CKernel::setNetPackMap()
{
    memset(m_netPackMap,0,sizeof(PFUN)*_DEF_PACK_COUNT);
    //key:协议头偏移量, value 函数指针
    //作用：通过来的协议头过来找到对应处理的函数指针
    NetMap(_DEF_PACK_LOGIN_RS) = &CKernel::slot_dealLoginRs;
    NetMap(_DEF_PACK_REGISTER_RS) = &CKernel::slot_dealRegisterRs;


}
//生成MD5函数：传入string，调用toString()得到MD5加密结果
static std::string getMD5(QString val){//static 仅当前文件可用
    QString str = QString ("%1_%2").arg(val).arg(MD5_KEY);
    MD5 md(str.toStdString());
    qDebug()<< str<<"md5:"<<md.toString().c_str();
    return md.toString();
}

void CKernel::SendData(char *buf, int len)
{
    m_tcpClient->SendData(0,buf,len);
}

void CKernel::slot_registerCommit(QString tel, QString password, QString name)
{
    STRU_REGISTER_RQ rq;
    strcpy(rq.tel,tel.toStdString().c_str());
    //strcpy(rq.password,password.toStdString().c_str());
    strcpy(rq.password,getMD5(password).c_str());
    //名字兼容中文
    std::string strName = name.toStdString();
    strcpy(rq.name,strName.c_str());
    SendData((char*)&rq,sizeof(rq));

}

void CKernel::slot_LoginCommit(QString tel, QString password)
{
    STRU_LOGIN_RQ rq;
    strcpy(rq.tel,tel.toStdString().c_str());
    strcpy(rq.password,getMD5(password).c_str());
    SendData((char*)&rq,sizeof(rq));
}

// 其他成员函数的实现应在此处添加


//配置文件 位置：exe同级目录:没有则自动创建
//文件名 .ini
//格式：
//[组名]:区分不同组
//key=value :键值对
/*
 * [net]
 * ip=192.168.3.1
 * port=8008
 */
void CKernel::loadIniFile()
{
    //默认值
    m_ip = "192.168.172.2";
    m_port = "8004";

    //获取exe目录
    QString path = QCoreApplication::applicationDirPath()+
            "/config.ini";
    //根据目录,看文件是否存在
    QFileInfo info(path);
    QSettings setting(path ,QSettings::IniFormat);
    if(info.exists()){
        setting.beginGroup("net");
        QVariant strIP = setting.value("ip","");
        QVariant strPort = setting.value("port","");
        if(!strIP.toString().isEmpty())
            m_ip= strIP.toString();
        if(!strPort.toString().isEmpty())
            m_port =strPort.toString();

    }else{
        //不存在
        //打开组：设置对应类容
        setting.beginGroup("net");
        setting.setValue("ip",m_ip);
        setting.setValue("port",m_port);
    }
    //关闭组
    setting.endGroup();
    qDebug()<<"ip:"<<m_ip<< "port:"<< m_port;
}


//回收函数
void CKernel:: slot_destroy(){
    qDebug()<< __func__;//测试是否回收
    m_tcpClient->CloseNet();
    delete m_tcpClient;
    delete m_mainDialog;
    delete m_loginDialog;
}
//客户端处理数据;
void CKernel::slot_dealClientData(unsigned int lSendIP, char *buf, int nlen)
{
    //接收到数据
   // QString str=QString("来自服务端:%1").arg(QString::fromStdString(buf));
    //QMessageBox::about(NULL ,"提示",str);//about阻塞：模态窗口：弹出后别的应用不能点击了。
    int type = *(int*)buf;
    qDebug()<< __func__;
    if( type >= _DEF_PACK_BASE && type < _DEF_PACK_BASE+_DEF_PACK_COUNT){
      PFUN pf =  NetMap(type);
      if( pf ) {
          //由于是类成员函数指针，所以需要this调用
          (this->*pf)(lSendIP,buf,nlen);

      }
    }
    //回收空间
    delete []buf;
}
void CKernel::slot_dealLoginRs(unsigned int lSendIP, char *buf, int nlen)
{

}

void CKernel::slot_dealRegisterRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_LOGIN_RS* rs=(STRU_LOGIN_RS*)buf;
    switch (rs->result) {
        case tel_is_exist:
            QMessageBox::about(m_loginDialog,"提示","用户已存在，注册失败");
        break;
    case name_is_exist:
            QMessageBox::about(m_loginDialog,"提示","昵称已存在，注册失败");
        case register_success:
            QMessageBox::about(m_loginDialog,"提示","注册成功!");
        break;
    }
}


#ifdef USE_SERVER
void CKernel::slot_dealServerData(unsigned int lSendIP, char *buf, int nlen)
{
    //接收到数据
    QString str=QString("来自客户端:%1").arg(QString::fromStdString(buf));
    QMessageBox::about(NULL ,"提示",str);//about阻塞：模态窗口：弹出后别的应用不能点击了。
    m_tcpServer->SendData(lSendIP,buf,nlen);//原路返回
    //回收空间
    delete []buf;
}
#endif
