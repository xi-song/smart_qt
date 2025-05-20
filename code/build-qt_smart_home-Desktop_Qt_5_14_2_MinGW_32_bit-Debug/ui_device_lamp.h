/********************************************************************************
** Form generated from reading UI file 'device_lamp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_LAMP_H
#define UI_DEVICE_LAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceLamp
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_background;
    QLabel *label_name_lamp;
    QLabel *label_lamp;
    QLabel *label_onoff;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *DeviceLamp)
    {
        if (DeviceLamp->objectName().isEmpty())
            DeviceLamp->setObjectName(QString::fromUtf8("DeviceLamp"));
        DeviceLamp->resize(282, 280);
        gridLayout = new QGridLayout(DeviceLamp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        frame_background = new QFrame(DeviceLamp);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        label_name_lamp = new QLabel(frame_background);
        label_name_lamp->setObjectName(QString::fromUtf8("label_name_lamp"));
        label_name_lamp->setGeometry(QRect(160, 130, 131, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\261\211\344\273\252\346\227\227\351\273\221-45S"));
        font.setPointSize(20);
        label_name_lamp->setFont(font);
        label_name_lamp->setAlignment(Qt::AlignCenter);
        label_lamp = new QLabel(frame_background);
        label_lamp->setObjectName(QString::fromUtf8("label_lamp"));
        label_lamp->setGeometry(QRect(0, 10, 175, 255));
        label_lamp->setStyleSheet(QString::fromUtf8("background-color: rgb(171, 171, 171);"));
        label_onoff = new QLabel(frame_background);
        label_onoff->setObjectName(QString::fromUtf8("label_onoff"));
        label_onoff->setGeometry(QRect(170, 200, 101, 51));
        QFont font1;
        font1.setPointSize(16);
        label_onoff->setFont(font1);
        label_onoff->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(frame_background);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 30, 61, 41));
        QFont font2;
        font2.setPointSize(14);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(frame_background);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 100, 61, 41));
        pushButton_2->setFont(font2);

        gridLayout->addWidget(frame_background, 0, 0, 1, 1);


        retranslateUi(DeviceLamp);

        QMetaObject::connectSlotsByName(DeviceLamp);
    } // setupUi

    void retranslateUi(QWidget *DeviceLamp)
    {
        DeviceLamp->setWindowTitle(QCoreApplication::translate("DeviceLamp", "Form", nullptr));
        label_name_lamp->setText(QCoreApplication::translate("DeviceLamp", "\345\220\212\347\201\257", nullptr));
        label_lamp->setText(QCoreApplication::translate("DeviceLamp", "\347\201\257\345\233\276\347\211\207", nullptr));
        label_onoff->setText(QCoreApplication::translate("DeviceLamp", "ON", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceLamp", "\345\274\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeviceLamp", "\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceLamp: public Ui_DeviceLamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_LAMP_H
