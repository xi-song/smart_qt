#ifndef Tcpserver_H
#define Tcpserver_H

#include "tcp/tcpserver_thread.h"
#include <QDebug>

//#include <Qt/qtcpserver.h>
#include <qtcpserver.h>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>


class Tcpserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Tcpserver(QObject *parent = 0);
    ~Tcpserver();

private:
    void incomingConnection(int sockDesc);

private slots:
    void slot_client_disconnected(int sockDesc);
    void slot_deviceSendData(int sockID,QString sendData);

signals:
    void sig_sendToClinet(int sockID,QString sendData);

private:
    QList<int> lst_scoket;
    
};

#endif // Tcpserver_H
