#include "device_lamp.h"
#include "ui_device_lamp.h"

DeviceLamp::DeviceLamp(int room,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceLamp)
{
    ui->setupUi(this);

    room_name = room;
    my_serial=new serial(LIVINGROOM,this);

    //滑动按钮
    my_Slider_btn = new SliderButton(this);
    my_Slider_btn->set_button_color(QColor(36,110,202),QColor(188,188,188),QColor(255,255,255));
    my_Slider_btn->set_button_size(30,40);
    my_Slider_btn->move(170,15);
    connect(my_Slider_btn,SIGNAL(signal_button_off()),this,SLOT(slot_slider_OFF()));
    connect(my_Slider_btn,SIGNAL(signal_button_on()),this,SLOT(slot_slider_ON()));


    this->setStyleSheet("#frame_background{background-color:#f4fcff;border-radius:15px}");
    ui->label_lamp->setStyleSheet("border-image:url(:/png/light-close.png)");
    ui->label_lamp->setText("");
}

DeviceLamp::~DeviceLamp()
{
    delete ui;
}

/***********************************
 *slot_slider_ON
 *功能: 总开关-开
 *说明：无
***********************************/
void DeviceLamp::slot_slider_ON(void)
{
    qDebug() << "吊灯开";
    emit sig_sendData(g_socket_map.value(room_name),"<*06,100,01*>");
    QString data="00";
    my_serial->serialSend(data);

    ui->label_lamp->setStyleSheet("border-image:url(:/png/light-open.png)");
    ui->label_onoff->setStyleSheet("color:rgb(36,110,202)");
    ui->label_onoff->setText("ON");
}

/***********************************
 *名称：slot_slider_OFF
 *功能: 总开关-关
 *说明：无
***********************************/
void DeviceLamp::slot_slider_OFF(void)
{
    qDebug() << "吊灯关";
    emit sig_sendData(g_socket_map.value(room_name),"<*06,100,00*>");
    QString data="00";
    my_serial->serialSend(data);

    ui->label_lamp->setStyleSheet("border-image:url(:/png/light-close.png)");
    ui->label_onoff->setStyleSheet("color:rgb(40,40,40)");
    ui->label_onoff->setText("OFF");
}
