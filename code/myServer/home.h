#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QTimer>

#include "tcp/tcpserver.h"
#include "device/device_ac.h"
#include "device/device_curtain.h"
#include "device/device_lamp.h"
#include "device/device_fan.h"
#include "my_custom/global.h"
namespace Ui {
class home;
}

class Home : public QWidget
{
    Q_OBJECT
    
public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    

public:
    Tcpserver* my_tcpServer;

    DeviceAC* wid_DeviceAC;
    DeviceCurtain *wid_DeviceCurtain;
    DeviceLamp * wid_DeviceLamp;
    DeviceFan * wid_DeviceFan;

    QTimer* my_timer;

public slots:
    void slot_timeout(void);

private:
    Ui::home *ui;
};

#endif // HOME_H
