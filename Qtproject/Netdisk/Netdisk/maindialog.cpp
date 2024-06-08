#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    //进行一次默认文件分页
    //文件分页
    ui->sw_page->setCurrentIndex(0);
    //传输页面默认分页
    ui->tw_transmit->setCurrentIndex(2);
    //设置标题
    this->setWindowTitle("欧凡网盘");
    //设置最小最大化
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
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
void MainDialog::on_pb_file_clicked()
{
    ui->sw_page->setCurrentIndex(0);
}
void MainDialog::on_pb_transmit_clicked()
{
    ui->sw_page->setCurrentIndex(1);
}
void MainDialog::on_pb_share_clicked()
{
    ui->sw_page->setCurrentIndex(2);
}






