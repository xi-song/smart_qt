#include "serial.h"
#include "ui_serial.h"

serial::serial(int room,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serial)
{
    ui->setupUi(this);
    room_name = room;
    Myserial = new QSerialPort(this); // 初始化串口对象


}

serial::~serial()
{
    delete ui;
}
//扫描串口
void serial::on_pushButton_clicked()
{
    ui->comboBox->clear();
    //获取所有串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort _com;
        _com.setPort(info);
         if(_com.portName()==Myserial->portName() or _com.open(QIODevice::ReadWrite)){
            ui->comboBox->addItem(info.portName());
            _com.close();//一定记得关闭，不然会一直开启
        }
    }
}

void serial::on_pushButton_2_clicked()
{

    //打开串口
    if(!Myserial->isOpen()){
        serialSet();//见下文的函数
        Myserial->open(QIODevice::ReadWrite);
        ui->radioButton->setChecked(true);
        ui->pushButton_2->setText("关闭串口");
        qDebug() << "串口已打开！";

    }else{
        Myserial->close();
        ui->radioButton->setChecked(false);
        ui->pushButton_2->setText("打开串口");
        qDebug() << "串口没打开！";
    }


}
void serial::serialSet(){

       Myserial->setPortName(ui->comboBox->currentText());//串口名
       Myserial->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);//设置波特率和读写方向
       Myserial->setDataBits(QSerialPort::Data8);		//数据位为8位
       Myserial->setFlowControl(QSerialPort::NoFlowControl);//无流控制
       Myserial->setParity(QSerialPort::NoParity);	//无校验位
       Myserial->setStopBits(QSerialPort::OneStop); //一位停止位

}



void serial::serialSend(QString &data){

    // 自动配置并打开串口（示例：COM3，波特率9600）
       Myserial->setPortName("COM10");  // 根据实际硬件修改
       Myserial->setBaudRate(QSerialPort::Baud9600);
       Myserial->setDataBits(QSerialPort::Data8);
       Myserial->setParity(QSerialPort::NoParity);
       Myserial->setStopBits(QSerialPort::OneStop);
       Myserial->open(QIODevice::ReadWrite);

       QStringList list=data.split("\n");//把string按回车分割

    // 要发送的数字（以字符串形式）


           if (Myserial->isOpen()) {
    //              serialSet();
               for(int i=0;i<list.size();i++){
                         // if(list[i]=="") continue;
                         // list[i]+="\r\n";
                          Myserial->write(list[i].toLocal8Bit());//转为数据流的形式
                      }
                Myserial->waitForBytesWritten(500);
             //      Myserial->write(data.toUtf8());
                   qDebug() << "已发送：" << data;
               } else {
                   qDebug() << "串口未打开！";
               }
        //   Myserial->waitForBytesWritten(200);


//       QString str=ui->textEdit->toPlainText();//把textedit里面的全部变成string
//       QStringList list=str.split("\n");//把string按回车分割
//       for(int i=0;i<list.size();i++){
//           if(list[i]=="") continue;
//           list[i]+="\r\n";
//           serial->write(list[i].toLocal8Bit());//转为数据流的形式
//       }

        Myserial->close();
}
