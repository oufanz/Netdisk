#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "maindialog.h"
#include "INetMediator.h"//通过中介者使用
#include <packdef.h>
#include <logindialog.h>
#include <common.h>
class INetMediator;
//协议映射表
class CKernel;
//类成员函数指针
typedef void(CKernel::*PFUN) (unsigned int lSendIP, char *buf, int nlen);
//#define USE_SERVER //当前是服务端
//#define TEST
class CKernel : public QObject
{
    Q_OBJECT

private:
    explicit CKernel(QObject *parent = nullptr);
    explicit CKernel(const CKernel &kernel){};
    ~CKernel(){};
    LoginDialog* m_loginDialog;
    void loadIniFile();
    void setNetPackMap();
    void SendData(char *buf,int len);
signals:

public:
    //单例模式
    static CKernel *GetInstance(){
        static CKernel kernel;
        return &kernel;
    }


private slots:
    //界面槽函数
    void slot_registerCommit(QString tel,QString password,QString name);
    void slot_LoginCommit(QString tel,QString password);

    //普通槽函数
    void slot_destroy();
    void slot_uploadFile(QString path,QString dir);
    //网络响应槽函数
    void slot_dealClientData(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealLoginRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealRegisterRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealUploaFiledRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealFileContentRs(unsigned int lSendIP, char *buf, int nlen);
#ifdef USE_SERVER
    void slot_dealServerData(unsigned int lSendIP, char *buf, int nlen);
#endif
private:
    MainDialog *m_mainDialog;

    QString m_ip;
    QString m_port;
    int m_id;
    QString m_name;
    INetMediator *m_tcpClient;
    //协议映射表，key值（偏移量）找到对应的函数指针
    PFUN m_netPackMap[_DEF_PACK_COUNT];
    //key:时间戳 hhmmsszz
    std::map<int,FileInfo>m_mapTimestampToFileInfo;

#ifdef USE_SERVER
    INetMediator *m_tcpServer;
#endif
};
#endif // CKERNEL_H
