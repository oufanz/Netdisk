#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include <QMenu>
#include "common.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainDialog; }
QT_END_NAMESPACE
class CKernel;
class MainDialog : public QDialog
{
    Q_OBJECT
    friend class CKernel;

signals:
    void SIG_close(); // 声明关闭信号
    void SIG_uploadFile(QString path,QString dir);

public:
    MainDialog(QWidget *parent = nullptr); // 构造函数
    ~MainDialog(); // 析构函数
protected:
    void closeEvent(QCloseEvent *event); // 重写关闭事件处理函数

//public slots:
private slots:
    void on_pb_share_clicked();

    void on_pb_file_clicked();

    void on_pb_transmit_clicked();

    void on_pb_addfile_clicked();
    void slot_addFolder(bool flag);
    void slot_uploadFile(bool flag);
    void slot_uploadFolder(bool flag);

    void slot_insertUploadFile(FileInfo& info);
    void slot_insertUploadFileComplete(FileInfo& info);
    void slot_updateUploadFileProgress(int timestamp,int pos);
    void slot_deleteUploadFileByRow(int row);
private:
    Ui::MainDialog *ui; // 指向界面设计的指针
    QMenu *m_menuAddFile;
};

#endif // MAINDIALOG_H
//点击 X -->执行关闭事件--〉弹窗询问--〉发送关闭信号核心类接收然后回收资源
