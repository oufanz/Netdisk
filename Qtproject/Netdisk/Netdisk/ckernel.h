#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "maindialog.h"
#include "INetMediator.h"//通过中介者使用
#include <packdef.h>
class INetMediator;
//协议映射表
class CKernel;
//类成员函数指针
typedef void(CKernel::*PFUN) (unsigned int lSendIP, char *buf, int nlen);
#define USE_SERVER 0 //当前是服务端

class CKernel : public QObject
{
    Q_OBJECT

private:
    explicit CKernel(QObject *parent = nullptr);
    explicit CKernel(const CKernel &kernel){};
    ~CKernel(){};

    void loadIniFile();
    void setNetPackMap();
signals:

public:
    //单例模式
    static CKernel *GetInstance(){
        static CKernel kernel;
        return &kernel;
    }

private slots:
    //普通槽函数
    void slot_destroy();
    //网络响应槽函数
    void slot_dealClientData(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealServerData(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealLoginRs(unsigned int lSendIP, char *buf, int nlen);
private:
    MainDialog *m_mainDialog;

    QString m_ip;
    QString m_port;

    INetMediator *m_tcpClient;
    //协议映射表，key值（偏移量）找到对应的函数指针
    PFUN m_netPackMap[_DEF_PACK_COUNT];

#ifdef USE_SERVER
    INetMediator *m_tcpServer;
#endif
};
#endif // CKERNEL_H
