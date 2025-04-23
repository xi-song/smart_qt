#ifndef DeviceCurtain_H
#define DeviceCurtain_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QAbstractAnimation>
#include <QTimer>
#include <QDebug>
#include "tcp/tcpsocket.h"
#include "my_custom/global.h"

#include "my_custom/sliderbutton.h"

namespace Ui {
class device_curtain;
}

class DeviceCurtain : public QWidget
{
    Q_OBJECT
    
public:
    explicit DeviceCurtain(int room,QWidget *parent = 0);
    ~DeviceCurtain();


    SliderButton *my_Slider_btn;

    QPropertyAnimation* aniamtion_up;
    QPropertyAnimation* aniamtion_down;
    QTimer* data_timer;

    int room_name;
private slots:

    void on_btn_down_pressed();

    void on_btn_down_released();

    void on_btn_up_pressed();

    void on_btn_up_released();

    void slot_dataChanged();

    void slot_slider_OFF(void);
    void slot_slider_ON(void);

signals:
    void sig_sendData(int sockID,QString sendData);



private:
    Ui::device_curtain *ui;
};

#endif // DeviceCurtain_H
