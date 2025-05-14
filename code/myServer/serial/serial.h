#ifndef SERIAL_H
#define SERIAL_H

#include<QDebug>
#include<QPushButton>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMainWindow>
namespace Ui {
class serial;
}

class serial : public QMainWindow
{
    Q_OBJECT

public:
    explicit serial(int room,QWidget *parent = nullptr);
    ~serial();

    void serialSet();
    int room_name;
    void serialSend(QString &data);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::serial *ui;
    QSerialPort *Myserial;
};

#endif // SERIAL_H
