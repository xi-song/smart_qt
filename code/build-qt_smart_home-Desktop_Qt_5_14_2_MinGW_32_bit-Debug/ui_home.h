/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QFrame *frame_left;
    QLabel *label_headpic;
    QLabel *label_status;
    QLabel *label_info;
    QLabel *label_time_1;
    QLabel *label_time_2;
    QLabel *label_fenge;
    QLabel *label_keting;

    void setupUi(QWidget *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QString::fromUtf8("home"));
        home->resize(1440, 844);
        frame_left = new QFrame(home);
        frame_left->setObjectName(QString::fromUtf8("frame_left"));
        frame_left->setGeometry(QRect(0, 0, 265, 840));
        frame_left->setFrameShape(QFrame::StyledPanel);
        frame_left->setFrameShadow(QFrame::Raised);
        label_headpic = new QLabel(frame_left);
        label_headpic->setObjectName(QString::fromUtf8("label_headpic"));
        label_headpic->setGeometry(QRect(80, 20, 110, 110));
        label_status = new QLabel(frame_left);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(0, 150, 261, 51));
        QFont font;
        font.setPointSize(15);
        label_status->setFont(font);
        label_status->setAlignment(Qt::AlignCenter);
        label_info = new QLabel(frame_left);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(30, 660, 261, 171));
        QFont font1;
        font1.setPointSize(12);
        label_info->setFont(font1);
        label_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_time_1 = new QLabel(home);
        label_time_1->setObjectName(QString::fromUtf8("label_time_1"));
        label_time_1->setGeometry(QRect(1030, 30, 401, 101));
        QFont font2;
        font2.setPointSize(55);
        label_time_1->setFont(font2);
        label_time_1->setAlignment(Qt::AlignCenter);
        label_time_2 = new QLabel(home);
        label_time_2->setObjectName(QString::fromUtf8("label_time_2"));
        label_time_2->setGeometry(QRect(1050, 130, 341, 71));
        QFont font3;
        font3.setPointSize(16);
        label_time_2->setFont(font3);
        label_time_2->setAlignment(Qt::AlignCenter);
        label_fenge = new QLabel(home);
        label_fenge->setObjectName(QString::fromUtf8("label_fenge"));
        label_fenge->setGeometry(QRect(940, 20, 21, 131));
        label_keting = new QLabel(home);
        label_keting->setObjectName(QString::fromUtf8("label_keting"));
        label_keting->setGeometry(QRect(620, 30, 291, 131));
        QFont font4;
        font4.setPointSize(50);
        label_keting->setFont(font4);
        label_keting->setAlignment(Qt::AlignCenter);

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QWidget *home)
    {
        home->setWindowTitle(QCoreApplication::translate("home", "\346\270\251\351\246\250\345\260\217\345\256\266", nullptr));
        label_headpic->setText(QCoreApplication::translate("home", "\345\244\264\345\203\217\345\233\276\347\211\207", nullptr));
        label_status->setText(QCoreApplication::translate("home", "\347\212\266\346\200\201\357\274\232\347\246\273\347\272\277", nullptr));
        label_info->setText(QCoreApplication::translate("home", "<html><head/><body><p><span style=\" font-weight:600;\">Hi~ \346\254\242\350\277\216\345\233\236\345\256\266</span></p><p><span style=\" font-weight:600;\">\347\264\257\344\272\206\344\270\200\345\244\251</span></p><p><span style=\" font-weight:600;\">\344\274\221\346\201\257\344\270\200\344\270\213\345\220\247~</span></p></body></html>", nullptr));
        label_time_1->setText(QCoreApplication::translate("home", "01:01", nullptr));
        label_time_2->setText(QCoreApplication::translate("home", "2023-01-01 \346\230\237\346\234\237\344\270\200", nullptr));
        label_fenge->setText(QCoreApplication::translate("home", "TextLabel", nullptr));
        label_keting->setText(QCoreApplication::translate("home", "\345\256\242\345\216\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
