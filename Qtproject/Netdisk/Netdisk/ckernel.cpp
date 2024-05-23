#include "ckernel.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFileInfo>
#include <QSettings>//配置文件需要的类

CKernel::CKernel(QObject *parent) : QObject(parent)
{
    // 加载配置文件
    loadIniFile();

    // 创建 MainDialog 实例
    m_mainDialog = new MainDialog(this);

    // 连接信号和槽
    connect(m_mainDialog, SIGNAL(SIG_close()), this, SLOT(slot_destroy()));

    // 显示 MainDialog
    m_mainDialog->show();
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
void Ckernel::loadInifile()
{
    //默认值
    m_ip = "192.168.5.198";
    m_port = "8004";

    //获取exe目录
    QString path = QCoreApplication::applicationDirPath();
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
    qDebug()<<"ip:"<<m_ip<< "port:"<<m_port;
}

//回收函数
void Ckernel:: slot_destroyed(){
    qDebug()<< __func__;//测试是否回收
    delete m_mainDialog;
}
