/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_music
{
public:
    QWidget *centralwidget;
    QListWidget *musicList;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevBtn;
    QPushButton *playBtn;
    QPushButton *nextBtn;
    QPushButton *modeBtn;
    QPushButton *listBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentTime;
    QSlider *progressBar;
    QLabel *totalTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *music)
    {
        if (music->objectName().isEmpty())
            music->setObjectName(QString::fromUtf8("music"));
        music->resize(853, 552);
        centralwidget = new QWidget(music);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        musicList = new QListWidget(centralwidget);
        musicList->setObjectName(QString::fromUtf8("musicList"));
        musicList->setGeometry(QRect(570, 10, 281, 451));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 360, 511, 121));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prevBtn = new QPushButton(widget);
        prevBtn->setObjectName(QString::fromUtf8("prevBtn"));

        horizontalLayout->addWidget(prevBtn);

        playBtn = new QPushButton(widget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QPushButton(widget);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));

        horizontalLayout->addWidget(nextBtn);

        modeBtn = new QPushButton(widget);
        modeBtn->setObjectName(QString::fromUtf8("modeBtn"));

        horizontalLayout->addWidget(modeBtn);

        listBtn = new QPushButton(widget);
        listBtn->setObjectName(QString::fromUtf8("listBtn"));

        horizontalLayout->addWidget(listBtn);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 320, 561, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        currentTime = new QLabel(layoutWidget);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));

        horizontalLayout_2->addWidget(currentTime);

        progressBar = new QSlider(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("\n"
"QSlider::groove:horizontal{ \n"
"		height: 12px; \n"
"		left: 0px; \n"
"		right: 0px; \n"
"		border:0px;    \n"
"	    border-radius:6px;    \n"
"		background:rgba(0,0,0,50);\n"
" } \n"
"\n"
" QSlider::handle:horizontal{ \n"
"		width:  50px; \n"
"		height: 50px; \n"
"		margin-top: -20px; \n"
"		margin-left: 0px; \n"
"		margin-bottom: -20px; \n"
"		margin-right: 0px; \n"
" 		border-image:url(:/res/images/setting_slider_handle.png);\n"
"} \n"
"\n"
"QSlider::sub-page:horizontal{\n"
"	   background:rgba(80,166,234,1);\n"
"}\n"
"\n"
""));
        progressBar->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(progressBar);

        totalTime = new QLabel(layoutWidget);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));

        horizontalLayout_2->addWidget(totalTime);

        music->setCentralWidget(centralwidget);
        menubar = new QMenuBar(music);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 21));
        music->setMenuBar(menubar);
        statusbar = new QStatusBar(music);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        music->setStatusBar(statusbar);

        retranslateUi(music);

        QMetaObject::connectSlotsByName(music);
    } // setupUi

    void retranslateUi(QMainWindow *music)
    {
        music->setWindowTitle(QCoreApplication::translate("music", "MainWindow", nullptr));
        prevBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        modeBtn->setText(QString());
        listBtn->setText(QString());
        currentTime->setText(QCoreApplication::translate("music", "0:0:0", nullptr));
        totalTime->setText(QCoreApplication::translate("music", "0:0:0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class music: public Ui_music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
