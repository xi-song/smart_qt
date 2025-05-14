#ifndef SERIAL1_H
#define SERIAL1_H


#include<QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>



class serial1 : public QSerialPort
{
    Q_OBJECT
public:
    explicit serial1(QObject *parent = 0);
    ~serial1();
    void serialSet();
    void serialSend(QString &data);

private:




};

#endif
