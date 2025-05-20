#include "device_ac.h"
#include "ui_device_ac.h"



DeviceAC::DeviceAC(int room,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::device_ac)
{
    ui->setupUi(this);

    room_name = room;
    my_serial=new serial(LIVINGROOM,this);


    //数字滚动器
    my_digitalScroller = new DigitalScroller(this);
    connect(my_digitalScroller,SIGNAL(currentValueChanged(int)),this,SLOT(slot_temp_value_channged(int)));
    my_digitalScroller->move(275,100);
    my_digitalScroller->hide();

    //滑动按钮
    my_Slider_btn = new SliderButton(this);

    my_Slider_btn->set_button_color(QColor(36,110,202),QColor(188,188,188),QColor(255,255,255));
    my_Slider_btn->set_button_size(30,40);
    my_Slider_btn->move(230,15);
    connect(my_Slider_btn,SIGNAL(signal_button_off()),this,SLOT(slot_slider_OFF()));
    connect(my_Slider_btn,SIGNAL(signal_button_on()),this,SLOT(slot_slider_ON()));



    connect(ui->btn_mode,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_wind,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_auto,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_high,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_low,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_mid,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_speed,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_cold,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_dry,SIGNAL(clicked()),this,SLOT(slot_btn_click()));
    connect(ui->btn_xiao,SIGNAL(clicked()),this,SLOT(slot_btn_click()));






    this->setStyleSheet("#frame_background{background-color:#f4fcff;border-radius:15px}");
    ui->label_ac->setStyleSheet("border-image:url(:/png/kongtiao-close.png)");
    ui->label_ac->setText("");

    ui->label_fenge->setFixedHeight(2);
    ui->label_fenge->setStyleSheet("border-image:url(:/png/kongtiao-fenge-close.png)");
    ui->label_fenge->setText("");



    ui->btn_mode->setStyleSheet("border-image:url(:/png/kongtiao-mode-close.png)");
    ui->btn_speed->setStyleSheet("QPushButton{border-image:url(:/png/kongtiaofengli-close.png)}");


    ui->btn_auto->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-auto-select.png)}"
                                "QPushButton:!checked{border-image:url(:/png/zi-auto-none.png)}");
    ui->btn_dry->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-chushi-select.png)}"
                               "QPushButton:!checked{border-image:url(:/png/zi-chushi-none.png)}");
    ui->btn_cold->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-zhileng-select.png)}"
                                "QPushButton:!checked{border-image:url(:/png/zi-zhileng-none.png)}");
    ui->btn_wind->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-songfeng-select.png)}"
                                "QPushButton:!checked{border-image:url(:/png/zi-songfeng-none.png)}");

    ui->btn_xiao->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-xiaofeng-select.png)}"
                                "QPushButton:!checked{border-image:url(:/png/zi-xiaofeng-none.png)}");
    ui->btn_low->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-xx-select.png)}"
                               "QPushButton:!checked{border-image:url(:/png/zi-xx-none.png)}");//微风 未选择
    ui->btn_mid->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-dafeng-select.png)}"
                               "QPushButton:!checked{border-image:url(:/png/zi-dafeng-none.png)}");
    ui->btn_high->setStyleSheet("QPushButton:checked{border-image:url(:/png/zi-dada-select.png)}"
                                "QPushButton:!checked{border-image:url(:/png/zi-dada-none.png)}");

}

DeviceAC::~DeviceAC()
{
    delete ui;
}

/***********************************
 *名称：slot_temp_value_channged
 *功能：发送温度数据给客户端
 *说明：无
***********************************/
void DeviceAC::slot_temp_value_channged(int value)
{
    qDebug() << "当前数值：" << value;
    QString sendData = "<*06,103," + QString::number(value) + "*>";
    emit sig_sendData(g_socket_map.value(room_name),sendData);

//    QString data = "9412" + QString::number(value);
//    my_serial->serialSend(data);

}


/***********************************
 *名称：on_btn_mode_clicked
 *功能：模式选择
 *说明：无
***********************************/
void DeviceAC::on_btn_mode_clicked()
{


}
/***********************************
 *名称：on_btn_wind_clicked
 *功能：风力选择
 *说明：无
***********************************/
void DeviceAC::on_btn_wind_clicked()
{

}
/***********************************
 *名称：on_btn_wind_back_clicked
 *功能：关闭风力页面
 *说明：无
***********************************/
void DeviceAC::on_btn_wind_back_clicked()
{

}
/***********************************
 *名称：on_btn_mode_back_clicked
 *功能：关闭模式页面
 *说明：无
***********************************/
void DeviceAC::on_btn_mode_back_clicked()
{

}
/***********************************
 *名称：slot_btn_click
 *功能：所有按钮的点击槽函数
 *说明：无
***********************************/

void DeviceAC::slot_btn_click(void)
{


    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    qDebug() << "按钮= " <<  btn->objectName();
    QString btn_name = btn->objectName();

    /*设置按钮的选中状态*/
    if(btn_name == "btn_auto" || btn_name == "btn_dry"|| btn_name == "btn_cold"|| btn_name == "btn_wind")
    {
        ui->btn_auto->setChecked(false);
        ui->btn_cold->setChecked(false);
        ui->btn_dry->setChecked(false);
        ui->btn_wind->setChecked(false);

    }else if(btn_name == "btn_xiao" || btn_name == "btn_low"|| btn_name == "btn_mid"|| btn_name == "btn_high")
    {
        ui->btn_xiao->setChecked(false);
        ui->btn_low->setChecked(false);
        ui->btn_mid->setChecked(false);
        ui->btn_high->setChecked(false);

    }
    btn->setChecked(true);


    if(btn_name == "btn_auto")//自动
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,104,00*>");

    }else if(btn_name == "btn_dry")//除湿
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,104,01*>");
    }else if(btn_name == "btn_cold")//制冷
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,104,02*>");
    }else if(btn_name == "btn_wind")//送风
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,104,03*>");
    }else if(btn_name == "btn_xiao")//小风
    {

        emit sig_sendData(g_socket_map.value(room_name),"<*06,105,00*>");
    }else if(btn_name == "btn_low")//微风
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,105,01*>");
    }else if(btn_name == "btn_mid")//大风
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,105,02*>");
    }else if(btn_name == "btn_high")//猛风
    {
        emit sig_sendData(g_socket_map.value(room_name),"<*06,105,03*>");
    }


    // 根据按钮名称发送对应的指令
       QHash<QString, QString> commandMap = {
           {"btn_auto", "941300"},
           {"btn_dry",  "941301"},
           {"btn_cold", "941302"},
           {"btn_wind", "941303"},
           {"btn_xiao", "941400"},
           {"btn_low",  "941401"},
           {"btn_mid",  "941402"},
           {"btn_high", "941403"}
       };

       if (commandMap.contains(btn_name)) {
              // 直接调用串口对象的发送函数

               qDebug()<<commandMap[btn_name];
                my_serial->serialSend(commandMap[btn_name]);
          }

}
/***********************************
 *slot_slider_ON
 *功能: 总开关-开
 *说明：无
***********************************/
void DeviceAC::slot_slider_ON(void)
{
    qDebug() << "空调开";

    emit sig_sendData(g_socket_map.value(room_name),"<*06,102,01*>");
    QString data="941100";
    my_serial->serialSend(data);

    ui->btn_auto->setCheckable(true);
    ui->btn_dry->setCheckable(true);
    ui->btn_cold->setCheckable(true);
    ui->btn_wind->setCheckable(true);
    ui->btn_xiao->setCheckable(true);
    ui->btn_low->setCheckable(true);
    ui->btn_mid->setCheckable(true);
    ui->btn_high->setCheckable(true);

    ui->btn_auto->setEnabled(true);
    ui->btn_dry->setEnabled(true);
    ui->btn_cold->setEnabled(true);
    ui->btn_wind->setEnabled(true);
    ui->btn_xiao->setEnabled(true);
    ui->btn_low->setEnabled(true);
    ui->btn_mid->setEnabled(true);
    ui->btn_high->setEnabled(true);

    ui->btn_auto->setChecked(true);
    ui->btn_xiao->setChecked(true);

    ui->label_ac->setStyleSheet("border-image:url(:/png/kongtiao-open.png)");
    ui->label_fenge->setStyleSheet("border-image:url(:/png/kongtiao-fenge-open.png)");

    ui->btn_mode->setStyleSheet("border-image:url(:/png/kongtiao-mode-open.png)");
    ui->btn_speed->setStyleSheet("QPushButton{border-image:url(:/png/kongtiaofengli-open.png)}");

    ui->label_onoff->setStyleSheet("color:rgb(36,110,202)");
    ui->label_onoff->setText("ON");

    my_digitalScroller->show();


}

/***********************************
 *名称：slot_slider_OFF
 *功能: 总开关-关
 *说明：无
***********************************/
void DeviceAC::slot_slider_OFF(void)
{
    qDebug() << "空调关";
    emit sig_sendData(g_socket_map.value(room_name),"<*06,102,00*>");
    QString data="940100";

        my_serial->serialSend(data);




    ui->btn_auto->setChecked(false);
    ui->btn_dry->setChecked(false);
    ui->btn_cold->setChecked(false);
    ui->btn_wind->setChecked(false);
    ui->btn_xiao->setChecked(false);
    ui->btn_low->setChecked(false);
    ui->btn_mid->setChecked(false);
    ui->btn_high->setChecked(false);

    ui->btn_auto->setEnabled(false);
    ui->btn_dry->setEnabled(false);
    ui->btn_cold->setEnabled(false);
    ui->btn_wind->setEnabled(false);
    ui->btn_xiao->setEnabled(false);
    ui->btn_low->setEnabled(false);
    ui->btn_mid->setEnabled(false);
    ui->btn_high->setEnabled(false);

    ui->label_ac->setStyleSheet("border-image:url(:/png/kongtiao-close.png)");
    ui->label_fenge->setStyleSheet("border-image:url(:/png/kongtiao-fenge-close.png)");

    ui->btn_mode->setStyleSheet("border-image:url(:/png/kongtiao-mode-close.png)");
    ui->btn_speed->setStyleSheet("QPushButton{border-image:url(:/png/kongtiaofengli-close.png)}");

    ui->label_onoff->setStyleSheet("color:rgb(40,40,40)");
    ui->label_onoff->setText("OFF");

    my_digitalScroller->hide();

}



