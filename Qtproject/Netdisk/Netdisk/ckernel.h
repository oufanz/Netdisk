#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "maindialog.h"

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
    void slot_destroy();

private:
    MainDialog *m_mainDialog;

    QString m_ip;
    QString m_port;
};
#endif // CKERNEL_H
