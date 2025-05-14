/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *serial)
    {
        if (serial->objectName().isEmpty())
            serial->setObjectName(QString::fromUtf8("serial"));
        serial->resize(634, 416);
        label = new QLabel(serial);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 211, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(serial);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 50, 141, 71));
        QFont font1;
        font1.setPointSize(15);
        comboBox->setFont(font1);
        pushButton = new QPushButton(serial);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 150, 191, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        radioButton = new QRadioButton(serial);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(170, 280, 31, 41));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton::Indicator{\n"
"width:30px; \n"
"height:30px\n"
"\n"
"}"));
        pushButton_2 = new QPushButton(serial);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 250, 191, 81));
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(serial);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 190, 191, 81));
        pushButton_3->setFont(font2);

        retranslateUi(serial);

        QMetaObject::connectSlotsByName(serial);
    } // setupUi

    void retranslateUi(QWidget *serial)
    {
        serial->setWindowTitle(QCoreApplication::translate("serial", "Form", nullptr));
        label->setText(QCoreApplication::translate("serial", "\344\270\262\345\217\243\345\220\215\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("serial", "\346\211\253\346\217\217\344\270\262\345\217\243", nullptr));
        radioButton->setText(QCoreApplication::translate("serial", "RadioButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("serial", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton_3->setText(QCoreApplication::translate("serial", "\346\211\253\346\217\217\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial: public Ui_serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
