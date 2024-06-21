/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *pb_icon;
    QTabWidget *tw_page;
    QWidget *tab_login;
    QPushButton *pb_login;
    QPushButton *pb_clear;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lb_phone;
    QLineEdit *le_phone;
    QLabel *lb_password;
    QLineEdit *le_password;
    QWidget *tab_2;
    QPushButton *pb_clear_register;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *lb_phone_register;
    QLabel *lb_password_confrim_register;
    QLineEdit *le_password_register;
    QLabel *lb_password_register;
    QLabel *lb_password_register_3;
    QLineEdit *le_phone_register;
    QLineEdit *le_password_confrim_register;
    QLineEdit *le_name_register;
    QPushButton *pb_login_register;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->setEnabled(true);
        LoginDialog->resize(834, 418);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        LoginDialog->setFont(font);
        pb_icon = new QLabel(LoginDialog);
        pb_icon->setObjectName(QString::fromUtf8("pb_icon"));
        pb_icon->setGeometry(QRect(13, 11, 401, 401));
        pb_icon->setPixmap(QPixmap(QString::fromUtf8(":/tb/baidu.png")));
        pb_icon->setScaledContents(true);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName(QString::fromUtf8("tw_page"));
        tw_page->setGeometry(QRect(420, 10, 411, 401));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setStrikeOut(false);
        tw_page->setFont(font1);
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        pb_login = new QPushButton(tab_login);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));
        pb_login->setGeometry(QRect(320, 290, 80, 50));
        pb_clear = new QPushButton(tab_login);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        pb_clear->setGeometry(QRect(230, 290, 80, 50));
        layoutWidget = new QWidget(tab_login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 311, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_phone = new QLabel(layoutWidget);
        lb_phone->setObjectName(QString::fromUtf8("lb_phone"));

        gridLayout->addWidget(lb_phone, 0, 0, 1, 1);

        le_phone = new QLineEdit(layoutWidget);
        le_phone->setObjectName(QString::fromUtf8("le_phone"));

        gridLayout->addWidget(le_phone, 0, 1, 1, 1);

        lb_password = new QLabel(layoutWidget);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));

        gridLayout->addWidget(lb_password, 1, 0, 1, 1);

        le_password = new QLineEdit(layoutWidget);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_password, 1, 1, 1, 1);

        tw_page->addTab(tab_login, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pb_clear_register = new QPushButton(tab_2);
        pb_clear_register->setObjectName(QString::fromUtf8("pb_clear_register"));
        pb_clear_register->setGeometry(QRect(230, 290, 80, 50));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 311, 171));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lb_phone_register = new QLabel(layoutWidget1);
        lb_phone_register->setObjectName(QString::fromUtf8("lb_phone_register"));

        gridLayout_2->addWidget(lb_phone_register, 0, 0, 1, 1);

        lb_password_confrim_register = new QLabel(layoutWidget1);
        lb_password_confrim_register->setObjectName(QString::fromUtf8("lb_password_confrim_register"));

        gridLayout_2->addWidget(lb_password_confrim_register, 2, 0, 1, 1);

        le_password_register = new QLineEdit(layoutWidget1);
        le_password_register->setObjectName(QString::fromUtf8("le_password_register"));
        le_password_register->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password_register, 1, 1, 1, 1);

        lb_password_register = new QLabel(layoutWidget1);
        lb_password_register->setObjectName(QString::fromUtf8("lb_password_register"));

        gridLayout_2->addWidget(lb_password_register, 1, 0, 1, 1);

        lb_password_register_3 = new QLabel(layoutWidget1);
        lb_password_register_3->setObjectName(QString::fromUtf8("lb_password_register_3"));

        gridLayout_2->addWidget(lb_password_register_3, 3, 0, 1, 1);

        le_phone_register = new QLineEdit(layoutWidget1);
        le_phone_register->setObjectName(QString::fromUtf8("le_phone_register"));

        gridLayout_2->addWidget(le_phone_register, 0, 1, 1, 1);

        le_password_confrim_register = new QLineEdit(layoutWidget1);
        le_password_confrim_register->setObjectName(QString::fromUtf8("le_password_confrim_register"));
        le_password_confrim_register->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password_confrim_register, 2, 1, 1, 1);

        le_name_register = new QLineEdit(layoutWidget1);
        le_name_register->setObjectName(QString::fromUtf8("le_name_register"));

        gridLayout_2->addWidget(le_name_register, 3, 1, 1, 1);

        pb_login_register = new QPushButton(tab_2);
        pb_login_register->setObjectName(QString::fromUtf8("pb_login_register"));
        pb_login_register->setGeometry(QRect(320, 290, 80, 50));
        tw_page->addTab(tab_2, QString());
        QWidget::setTabOrder(le_phone_register, le_password_register);
        QWidget::setTabOrder(le_password_register, le_password_confrim_register);
        QWidget::setTabOrder(le_password_confrim_register, le_name_register);
        QWidget::setTabOrder(le_name_register, pb_login_register);
        QWidget::setTabOrder(pb_login_register, pb_clear_register);
        QWidget::setTabOrder(pb_clear_register, le_phone);
        QWidget::setTabOrder(le_phone, le_password);
        QWidget::setTabOrder(le_password, pb_login);
        QWidget::setTabOrder(pb_login, pb_clear);
        QWidget::setTabOrder(pb_clear, tw_page);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", nullptr));
        pb_icon->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        tab_login->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        pb_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pb_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        lb_phone->setText(QApplication::translate("LoginDialog", "\350\264\246\345\217\267", nullptr));
        lb_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        le_password->setText(QString());
        tw_page->setTabText(tw_page->indexOf(tab_login), QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pb_clear_register->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        lb_phone_register->setText(QApplication::translate("LoginDialog", "\350\264\246\345\217\267", nullptr));
        lb_password_confrim_register->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244", nullptr));
        lb_password_register->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        lb_password_register_3->setText(QApplication::translate("LoginDialog", "\346\230\265\347\247\260", nullptr));
        pb_login_register->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
