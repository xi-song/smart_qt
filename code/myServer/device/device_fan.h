#ifndef DEVICE_FAN_H
#define DEVICE_FAN_H

#include <QWidget>
#include "my_custom/global.h"
#include "my_custom/sliderbutton.h"

namespace Ui {
class DeviceFan;
}

class DeviceFan : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceFan(int room,QWidget *parent = 0);
    ~DeviceFan();

    SliderButton* my_Slider_btn;

    int room_name;
private:
    Ui::DeviceFan *ui;


public slots:
    void slot_slider_OFF(void);
    void slot_slider_ON(void);

signals:
    void sig_sendData(int sockID,QString sendData);
};

#endif // DEVICE_FAN_H
