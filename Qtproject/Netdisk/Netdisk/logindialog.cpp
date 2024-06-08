#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QRegExp>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("登录&注册");
    //窗口默认在登录页面
    ui->tw_page->setCurrentIndex(0);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//判断数据是合法
/* 信息采集
 * 密码合法
 * 账号合法
 * 名称合法
 * 发信号
*/
//登录信息获取
void LoginDialog::on_pb_login_clicked()
{
    QString tel =ui->le_phone->text();
    QString password =ui->le_password->text();
    if(tel.isEmpty()||password.isEmpty()){
        QMessageBox::about(this,"提示","输入内容，不可为空");
        return;
    }
    //判断密码是否合法_正则表达式
    QRegExp exp("^1[3-9][0-9]{9}$");
    if( !exp.exactMatch(tel)){
        QMessageBox::about(this,"提示","手机号非法");
        return;
    }
    if(password.size()>20){
        QMessageBox::about(this,"提示","密码过长");
        return;
    }

    //发送信号
    Q_EMIT SIG_LoginCommit(tel,password);
}
//注册信息获取
void LoginDialog::on_pb_login_register_clicked()
{
    QString tel =ui->le_phone_register->text();
    QString password =ui->le_password_register->text();
    QString comfirm =ui->le_password_confrim_register->text();
    QString name =ui->le_name_register->text();
    QString tmpName =name;
    if(tel.isEmpty()||password.isEmpty()||comfirm.isEmpty()
            ||name.isEmpty()||tmpName.remove(" ").isEmpty()){
        QMessageBox::about(this,"提示","输入内容，不可为空");
        return;
    }
    //判断密码是否合法_正则表达式
    QRegExp exp("^1[3-9][0-9]{9}$");
    if( !exp.exactMatch(tel)){
        QMessageBox::about(this,"提示","手机号非法");
        return;
    }
    if(password.size()>20){
        QMessageBox::about(this,"提示","密码过长");
        return;
    }
    if(comfirm!=password){
        QMessageBox::about(this,"提示","两次输入不一致");
        return;
    }
    if(name.size()>10){
        QMessageBox::about(this,"提示","昵称太长");
        return;
    }
    //发送信号
    Q_EMIT SIG_registerCommit(tel,password,name);

}

//清空注册页面
void LoginDialog::on_pb_clear_register_clicked()
{
    ui->le_phone_register->setText("");
    ui->le_name_register->setText("");
    ui->le_password_register->setText("");
    ui->le_password_confrim_register->setText("");

}
//清空登录页面
void LoginDialog::on_pb_clear_clicked()
{
    ui->le_password->setText("");
    ui->le_phone->setText("");
}

