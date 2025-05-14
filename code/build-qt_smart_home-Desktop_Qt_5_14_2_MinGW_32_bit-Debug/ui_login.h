/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *btn_log;
    QGroupBox *groupBox;
    QLabel *label_name;
    QLineEdit *edit_name;
    QLabel *label_pw;
    QLineEdit *edit_pw;
    QLabel *label_title;
    QCheckBox *check_name;
    QPushButton *btn_clear;
    QCheckBox *check_pw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(616, 997);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_log = new QPushButton(centralwidget);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(130, 490, 101, 51));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        btn_log->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(80, 260, 391, 161));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 30, 131, 41));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label_name->setFont(font1);
        edit_name = new QLineEdit(groupBox);
        edit_name->setObjectName(QString::fromUtf8("edit_name"));
        edit_name->setGeometry(QRect(130, 30, 211, 41));
        label_pw = new QLabel(groupBox);
        label_pw->setObjectName(QString::fromUtf8("label_pw"));
        label_pw->setGeometry(QRect(10, 80, 111, 51));
        label_pw->setFont(font1);
        edit_pw = new QLineEdit(groupBox);
        edit_pw->setObjectName(QString::fromUtf8("edit_pw"));
        edit_pw->setGeometry(QRect(130, 90, 211, 41));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(210, 170, 151, 71));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);
        check_name = new QCheckBox(centralwidget);
        check_name->setObjectName(QString::fromUtf8("check_name"));
        check_name->setGeometry(QRect(80, 430, 261, 41));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        check_name->setFont(font3);
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(300, 490, 111, 51));
        btn_clear->setFont(font);
        check_pw = new QCheckBox(centralwidget);
        check_pw->setObjectName(QString::fromUtf8("check_pw"));
        check_pw->setGeometry(QRect(320, 430, 271, 41));
        check_pw->setFont(font3);
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 616, 21));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "MainWindow", nullptr));
        btn_log->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        groupBox->setTitle(QString());
        label_name->setText(QCoreApplication::translate("login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_pw->setText(QCoreApplication::translate("login", "\345\257\206 \347\240\201\357\274\232", nullptr));
        label_title->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        check_name->setText(QCoreApplication::translate("login", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        btn_clear->setText(QCoreApplication::translate("login", "\351\207\215\347\275\256", nullptr));
        check_pw->setText(QCoreApplication::translate("login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
