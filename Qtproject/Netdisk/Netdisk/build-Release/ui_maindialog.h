/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_file;
    QPushButton *pb_transmit;
    QPushButton *pb_share;
    QPushButton *pb_store;
    QPushButton *pb_rubbish;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_user;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *sw_page;
    QWidget *page_file;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_right_top;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_pre;
    QPushButton *pb_next;
    QLabel *lb_path;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_serch;
    QPushButton *pb_addfile;
    QWidget *wdg_righ_bottom;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table_file;
    QWidget *page_transmit;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tw_transmit;
    QWidget *tab_upload;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *table_upload;
    QWidget *tab_download;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *table_download;
    QWidget *tab_complete;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *table_complete;
    QWidget *page_share;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tw_share;
    QWidget *tab_myshare;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *table_share;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
        MainDialog->resize(925, 626);
        horizontalLayout = new QHBoxLayout(MainDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(MainDialog);
        wdg_left->setObjectName(QString::fromUtf8("wdg_left"));
        wdg_left->setMinimumSize(QSize(211, 0));
        wdg_left->setMaximumSize(QSize(211, 16777215));
        wdg_left->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));
        verticalLayout = new QVBoxLayout(wdg_left);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pb_file = new QPushButton(wdg_left);
        pb_file->setObjectName(QString::fromUtf8("pb_file"));
        pb_file->setMinimumSize(QSize(0, 70));
        pb_file->setMaximumSize(QSize(10000, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(10);
        pb_file->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_file->setIcon(icon);
        pb_file->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pb_file);

        pb_transmit = new QPushButton(wdg_left);
        pb_transmit->setObjectName(QString::fromUtf8("pb_transmit"));
        pb_transmit->setMinimumSize(QSize(0, 70));
        pb_transmit->setMaximumSize(QSize(10000, 70));
        pb_transmit->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/transmit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_transmit->setIcon(icon1);
        pb_transmit->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pb_transmit);

        pb_share = new QPushButton(wdg_left);
        pb_share->setObjectName(QString::fromUtf8("pb_share"));
        pb_share->setMinimumSize(QSize(0, 70));
        pb_share->setMaximumSize(QSize(10000, 70));
        pb_share->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/share.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_share->setIcon(icon2);
        pb_share->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pb_share);

        pb_store = new QPushButton(wdg_left);
        pb_store->setObjectName(QString::fromUtf8("pb_store"));
        pb_store->setMinimumSize(QSize(0, 70));
        pb_store->setMaximumSize(QSize(10000, 70));
        pb_store->setFont(font);

        verticalLayout->addWidget(pb_store);

        pb_rubbish = new QPushButton(wdg_left);
        pb_rubbish->setObjectName(QString::fromUtf8("pb_rubbish"));
        pb_rubbish->setMinimumSize(QSize(0, 70));
        pb_rubbish->setMaximumSize(QSize(10000, 70));
        pb_rubbish->setFont(font);

        verticalLayout->addWidget(pb_rubbish);

        verticalSpacer = new QSpacerItem(20, 269, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_user = new QPushButton(wdg_left);
        pb_user->setObjectName(QString::fromUtf8("pb_user"));
        pb_user->setMinimumSize(QSize(0, 50));
        pb_user->setMaximumSize(QSize(10000, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/face/btn_avatar_a0.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_user->setIcon(icon3);
        pb_user->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pb_user);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(MainDialog);
        wdg_right->setObjectName(QString::fromUtf8("wdg_right"));
        wdg_right->setMinimumSize(QSize(0, 0));
        wdg_right->setMaximumSize(QSize(10000, 16777215));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        sw_page = new QStackedWidget(wdg_right);
        sw_page->setObjectName(QString::fromUtf8("sw_page"));
        page_file = new QWidget();
        page_file->setObjectName(QString::fromUtf8("page_file"));
        verticalLayout_3 = new QVBoxLayout(page_file);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wdg_right_top = new QWidget(page_file);
        wdg_right_top->setObjectName(QString::fromUtf8("wdg_right_top"));
        wdg_right_top->setMinimumSize(QSize(0, 50));
        wdg_right_top->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(wdg_right_top);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_pre = new QPushButton(wdg_right_top);
        pb_pre->setObjectName(QString::fromUtf8("pb_pre"));
        pb_pre->setMinimumSize(QSize(50, 50));
        pb_pre->setMaximumSize(QSize(50, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        pb_pre->setFont(font1);
        pb_pre->setIconSize(QSize(50, 50));
        pb_pre->setFlat(true);

        horizontalLayout_2->addWidget(pb_pre);

        pb_next = new QPushButton(wdg_right_top);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));
        pb_next->setMinimumSize(QSize(50, 50));
        pb_next->setMaximumSize(QSize(50, 50));
        pb_next->setFont(font1);
        pb_next->setFlat(true);

        horizontalLayout_2->addWidget(pb_next);

        lb_path = new QLabel(wdg_right_top);
        lb_path->setObjectName(QString::fromUtf8("lb_path"));
        lb_path->setMinimumSize(QSize(50, 50));
        lb_path->setMaximumSize(QSize(50, 50));
        lb_path->setFont(font1);

        horizontalLayout_2->addWidget(lb_path);

        horizontalSpacer = new QSpacerItem(472, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_serch = new QPushButton(wdg_right_top);
        pb_serch->setObjectName(QString::fromUtf8("pb_serch"));
        pb_serch->setMinimumSize(QSize(50, 50));
        pb_serch->setMaximumSize(QSize(50, 50));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_serch->setIcon(icon4);
        pb_serch->setIconSize(QSize(50, 50));
        pb_serch->setFlat(true);

        horizontalLayout_2->addWidget(pb_serch);

        pb_addfile = new QPushButton(wdg_right_top);
        pb_addfile->setObjectName(QString::fromUtf8("pb_addfile"));
        pb_addfile->setMinimumSize(QSize(50, 50));
        pb_addfile->setMaximumSize(QSize(50, 50));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/addFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_addfile->setIcon(icon5);
        pb_addfile->setIconSize(QSize(40, 40));
        pb_addfile->setFlat(true);

        horizontalLayout_2->addWidget(pb_addfile);


        verticalLayout_3->addWidget(wdg_right_top);

        wdg_righ_bottom = new QWidget(page_file);
        wdg_righ_bottom->setObjectName(QString::fromUtf8("wdg_righ_bottom"));
        verticalLayout_4 = new QVBoxLayout(wdg_righ_bottom);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        table_file = new QTableWidget(wdg_righ_bottom);
        if (table_file->columnCount() < 3)
            table_file->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_file->setObjectName(QString::fromUtf8("table_file"));
        table_file->horizontalHeader()->setDefaultSectionSize(180);
        table_file->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_file->horizontalHeader()->setStretchLastSection(true);
        table_file->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(table_file);


        verticalLayout_3->addWidget(wdg_righ_bottom);

        sw_page->addWidget(page_file);
        page_transmit = new QWidget();
        page_transmit->setObjectName(QString::fromUtf8("page_transmit"));
        page_transmit->setFont(font);
        verticalLayout_5 = new QVBoxLayout(page_transmit);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tw_transmit = new QTabWidget(page_transmit);
        tw_transmit->setObjectName(QString::fromUtf8("tw_transmit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        tw_transmit->setFont(font2);
        tab_upload = new QWidget();
        tab_upload->setObjectName(QString::fromUtf8("tab_upload"));
        tab_upload->setFont(font2);
        verticalLayout_6 = new QVBoxLayout(tab_upload);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        table_upload = new QTableWidget(tab_upload);
        if (table_upload->columnCount() < 3)
            table_upload->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        table_upload->setObjectName(QString::fromUtf8("table_upload"));
        table_upload->horizontalHeader()->setDefaultSectionSize(180);
        table_upload->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_upload->horizontalHeader()->setStretchLastSection(true);
        table_upload->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(table_upload);

        tw_transmit->addTab(tab_upload, QString());
        tab_download = new QWidget();
        tab_download->setObjectName(QString::fromUtf8("tab_download"));
        tab_download->setFont(font2);
        verticalLayout_7 = new QVBoxLayout(tab_download);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        table_download = new QTableWidget(tab_download);
        if (table_download->columnCount() < 3)
            table_download->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        table_download->setObjectName(QString::fromUtf8("table_download"));
        table_download->horizontalHeader()->setDefaultSectionSize(180);
        table_download->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_download->horizontalHeader()->setStretchLastSection(true);
        table_download->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(table_download);

        tw_transmit->addTab(tab_download, QString());
        tab_complete = new QWidget();
        tab_complete->setObjectName(QString::fromUtf8("tab_complete"));
        tab_complete->setFont(font2);
        verticalLayout_8 = new QVBoxLayout(tab_complete);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        table_complete = new QTableWidget(tab_complete);
        if (table_complete->columnCount() < 3)
            table_complete->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        table_complete->setObjectName(QString::fromUtf8("table_complete"));
        table_complete->horizontalHeader()->setDefaultSectionSize(180);
        table_complete->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_complete->horizontalHeader()->setStretchLastSection(true);
        table_complete->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(table_complete);

        tw_transmit->addTab(tab_complete, QString());

        verticalLayout_5->addWidget(tw_transmit);

        sw_page->addWidget(page_transmit);
        page_share = new QWidget();
        page_share->setObjectName(QString::fromUtf8("page_share"));
        verticalLayout_9 = new QVBoxLayout(page_share);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        tw_share = new QTabWidget(page_share);
        tw_share->setObjectName(QString::fromUtf8("tw_share"));
        tw_share->setFont(font2);
        tab_myshare = new QWidget();
        tab_myshare->setObjectName(QString::fromUtf8("tab_myshare"));
        tab_myshare->setFont(font1);
        verticalLayout_10 = new QVBoxLayout(tab_myshare);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        table_share = new QTableWidget(tab_myshare);
        if (table_share->columnCount() < 3)
            table_share->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        table_share->setObjectName(QString::fromUtf8("table_share"));
        table_share->setFont(font2);
        table_share->horizontalHeader()->setDefaultSectionSize(180);
        table_share->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_share->horizontalHeader()->setStretchLastSection(true);
        table_share->verticalHeader()->setVisible(false);

        verticalLayout_10->addWidget(table_share);

        tw_share->addTab(tab_myshare, QString());

        verticalLayout_9->addWidget(tw_share);

        sw_page->addWidget(page_share);

        verticalLayout_2->addWidget(sw_page);


        horizontalLayout->addWidget(wdg_right);


        retranslateUi(MainDialog);

        sw_page->setCurrentIndex(0);
        tw_transmit->setCurrentIndex(0);
        tw_share->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "MainDialog", nullptr));
        pb_file->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        pb_transmit->setText(QApplication::translate("MainDialog", "\344\274\240\350\276\223", nullptr));
        pb_share->setText(QApplication::translate("MainDialog", "\345\210\206\344\272\253", nullptr));
        pb_store->setText(QApplication::translate("MainDialog", "\346\224\266\350\227\217", nullptr));
        pb_rubbish->setText(QApplication::translate("MainDialog", "\345\233\236\346\224\266\347\253\231", nullptr));
        pb_user->setText(QApplication::translate("MainDialog", "\347\224\250\346\210\267", nullptr));
        pb_pre->setText(QApplication::translate("MainDialog", "<", nullptr));
        pb_next->setText(QApplication::translate("MainDialog", ">", nullptr));
        lb_path->setText(QApplication::translate("MainDialog", "/", nullptr));
        pb_serch->setText(QString());
        pb_addfile->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_file->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_file->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainDialog", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_file->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_upload->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_upload->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainDialog", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_upload->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_upload), QApplication::translate("MainDialog", "\344\270\212\344\274\240\344\270\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_download->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_download->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainDialog", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_download->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_download), QApplication::translate("MainDialog", "\344\270\213\350\275\275\344\270\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_complete->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_complete->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainDialog", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_complete->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_complete), QApplication::translate("MainDialog", "\345\267\262\345\256\214\346\210\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_share->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_share->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainDialog", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_share->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        tw_share->setTabText(tw_share->indexOf(tab_myshare), QApplication::translate("MainDialog", "\346\210\221\347\232\204\345\210\206\344\272\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
