#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include <QDialog>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainDialog; }
QT_END_NAMESPACE

class MainDialog : public QDialog
{
    Q_OBJECT

signals:
    void SIG_close(); // 声明关闭信号

public:
    MainDialog(QWidget *parent = nullptr); // 构造函数
    ~MainDialog(); // 析构函数

protected:
    void closeEvent(QCloseEvent *event); // 重写关闭事件处理函数

private:
    Ui::MainDialog *ui; // 指向界面设计的指针
};

#endif // MAINDIALOG_H
//点击 X -->执行关闭事件--〉弹窗询问--〉发送关闭信号核心类接收然后回收资源
