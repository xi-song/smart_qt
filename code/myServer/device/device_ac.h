#ifndef DeviceAC_H
#define DeviceAC_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include "my_custom/digital_scroller.h"
#include "my_custom/sliderbutton.h"
#include "tcp/tcpsocket.h"

#include "my_custom/global.h"

namespace Ui {
class device_ac;
}

class DeviceAC : public QWidget
{
    Q_OBJECT
    
public:
    explicit DeviceAC(int room,QWidget *parent = 0);
    ~DeviceAC();

    DigitalScroller* my_digitalScroller;
    SliderButton* my_Slider_btn;

    int room_name;


private slots:

    void slot_temp_value_channged(int currentValue);

    void on_btn_mode_clicked();

    void on_btn_wind_clicked();

    void on_btn_wind_back_clicked();

    void on_btn_mode_back_clicked();

    void slot_btn_click(void);

    void slot_slider_OFF(void);
    void slot_slider_ON(void);

signals:
    void sig_sendData(int sockID,QString sendData);

private:
    Ui::device_ac *ui;
};

#endif // DeviceAC_H
