#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "maindialog.h"
#include "INetMediator.h"//通过中介者使用
//class INetMediator;
#define USE_SERVER 1 //当前是服务端
class CKernel : public QObject
{
    Q_OBJECT

private:
    explicit CKernel(QObject *parent = nullptr);
    explicit CKernel(const CKernel &kernel){};
    ~CKernel(){};

    void loadIniFile();
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
private:
    MainDialog *m_mainDialog;

    QString m_ip;
    QString m_port;

    INetMediator *m_tcpClient;
#ifdef USE_SERVER
    INetMediator *m_tcpServer;
#endif
};
#endif // CKERNEL_H
