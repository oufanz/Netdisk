#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::closeEvent(QCloseEvent *event){
    //弹出询问：参数1：父控件是什么？ 2：左上角标题，3：内容
    if(QMessageBox::question(this,"退出提示","是否退出？")==QMessageBox::Yes){
        //确认关闭
        event->accept();//同意当前事件退出
        Q_EMIT SIG_close();//发送信号

    }else{
        //否
        event->ignore();
    }
}
