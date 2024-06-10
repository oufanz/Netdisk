#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
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
    //初始化菜单，添加菜单项
    //定义菜单项
    QAction *action_addFolder = new QAction( QIcon(":/images/folder.png"),"新建文件夹");
    QAction *action_uploadFile = new QAction("上传文件");
    QAction *action_uploadFolder = new QAction("上传文件夹");
    //添加菜单项
    m_menuAddFile = new QMenu();
    m_menuAddFile->addAction(action_addFolder);
    m_menuAddFile->addSeparator();
    m_menuAddFile->addAction(action_uploadFile);
    m_menuAddFile->addAction(action_uploadFolder);
    connect(action_addFolder,SIGNAL(triggered(bool)),this,
            SLOT(slot_addFolder(bool)));
    connect(action_uploadFile,SIGNAL(triggered(bool)),this,
            SLOT(slot_uploadFile(bool)));
    connect(action_uploadFolder,SIGNAL(triggered(bool)),this,
            SLOT(slot_uploadFolder(bool)));

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
//点击添加文件，弹出菜单
void MainDialog::on_pb_addfile_clicked()
{
    //弹出菜单
    m_menuAddFile->exec(QCursor::pos());//鼠标坐标在该点显示

}

void MainDialog::slot_addFolder(bool flag)
{
    qDebug() << __func__;
}

void MainDialog::slot_uploadFile(bool flag)
{
    qDebug() <<"maindialog:"<< __func__;

    QString path = QFileDialog::getOpenFileName(this,"选择文件",",/");
    if(path.isEmpty()) return;
    //目前是否有一样的文件，如果有则取消;
    //发送信号
    QString dir = ui->lb_path->text();
    //从path，上传到dir
    Q_EMIT SIG_uploadFile(path,dir);
}


void MainDialog::slot_uploadFolder(bool flag)
{
    qDebug() << __func__;
}

