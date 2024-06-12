#include "maindialog.h"
#include "ui_maindialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include<QProgressBar>
#include "mytablewidgetitem.h"
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

void MainDialog::slot_insertUploadFile(FileInfo &info)
{
    //表格插入信息
    qDebug()<<__func__;
    //列：文件 大小 时间 速率 进度 按钮
    //新增一行
    int rows = ui->table_upload->rowCount();
    ui->table_upload->setRowCount(rows+1);
    //为这一行添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_upload->setItem(rows,0,item0);

    QTableWidgetItem*item1 = new QTableWidgetItem(QString::number(info.size));
    ui->table_upload->setItem(rows,1,item1);

    QTableWidgetItem*item2 = new QTableWidgetItem(info.time);
    ui->table_upload->setItem(rows,2,item2);

    QTableWidgetItem*item3 = new QTableWidgetItem("0KB/s");   //todo
    ui->table_upload->setItem(rows,3,item3);
    //进度条：
    QProgressBar* progress = new QProgressBar ;
    progress->setMaximum(info.size);
    ui->table_upload->setCellWidget(rows,4,progress);


    QPushButton * button =new QPushButton;
    if(!info.isPause){
        button->setText("暂停");
    }else{
        button->setText("开始");
    }
    ui->table_upload->setCellWidget(rows,5,button);

}

void MainDialog::slot_insertUploadFileComplete(FileInfo &info)
{
    //列：文件 大小 时间 上传完成
    qDebug()<<__func__;
    //新增一行
    int rows = ui->table_complete->rowCount();
    ui->table_complete->setRowCount(rows+1);
    //为这一行添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_complete->setItem(rows,0,item0);

    QTableWidgetItem*item1 = new QTableWidgetItem(QString::number(info.size));
    ui->table_complete->setItem(rows,1,item1);

    QTableWidgetItem*item2 = new QTableWidgetItem(info.time);
    ui->table_complete->setItem(rows,2,item2);

    QTableWidgetItem*item3 = new QTableWidgetItem("上传完成");   //todo
    ui->table_complete->setItem(rows,3,item3);

}

void MainDialog::slot_updateUploadFileProgress(int timestamp, int pos)
{
    qDebug()<<__func__;

    //遍历所有项 第0列
    int row = ui->table_upload->rowCount();
    for(int i = 0;i < row ; i++){
        //取到每个文件信息的时间戳，看是否一致;
       MyTableWidgetItem*  item0 =(MyTableWidgetItem*) ui->table_upload->item(i ,0);
       if(item0->m_info.timestamp==timestamp){
           //一致：更新进度
           //看是否结束
           item0->m_info.pos=pos;
           QProgressBar*  item4 =(QProgressBar*) ui->table_upload->cellWidget(i,4);
           item4->setValue(pos);
           if(item4->value()>=item4->maximum()){
               //是删除这一项,添加到已完成
               slot_deleteUploadFileByRow(i);//删除该行
               slot_insertUploadFileComplete(item0->m_info);
               return;
           }
       }
    }
}
//todo
void MainDialog::slot_deleteUploadFileByRow(int row)
{

}

