#include "tcpserver.h"

Tcpserver::Tcpserver(QObject *parent) :
    QTcpServer(parent)
{

}

Tcpserver::~Tcpserver()
{

}

/*实时监控客户端连接*/
void Tcpserver::incomingConnection(int sockID)
{

    Tcpserver_Thread * my_tcpserver_thread = new Tcpserver_Thread(sockID);
    connect(this,SIGNAL(sig_sendToClinet(int,QString)),my_tcpserver_thread,SLOT(slot_sendToClientData(int,QString)));

    my_tcpserver_thread->start();

}

void Tcpserver::slot_client_disconnected(int sockID)
{

}

void Tcpserver::slot_deviceSendData(int sockID,QString sendData)
{
    //将数据发送给对应的客户端
    emit sig_sendToClinet(sockID,sendData);
}

