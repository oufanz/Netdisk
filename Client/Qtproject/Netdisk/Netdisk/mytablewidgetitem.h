#ifndef MYTABLEWIDGETITEM_H
#define MYTABLEWIDGETITEM_H

#include <QTableWidgetItem>
#include "common.h"
class MainDialog;
class MyTableWidgetItem : public QTableWidgetItem
{
    //Q_OBJECT
public:
    MyTableWidgetItem();
    //槽函数和普通函数（槽函数机制：可以用来接受信号或者窗口发出的信号）
public slots:
    void slot_setInfo(FileInfo& info);
private:
    FileInfo m_info;
    friend class MainDialog;
};

#endif // MYTABLEWIDGETITEM_H
