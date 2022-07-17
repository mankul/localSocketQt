#include "localclientsocket.h"

LocalClientSocket::LocalClientSocket()
{
    clientSocket = new QLocalSocket();
    qDebug()<<"new client socket created";
    connect(clientSocket, &QLocalSocket::connected, this, & LocalClientSocket::onNewConnection);
}

void LocalClientSocket::connectToServer(){
    clientSocket->connectToServer("localServer", QIODevice::ReadWrite);
    qDebug()<<Q_FUNC_INFO<<"connected to client";
}

void LocalClientSocket::onNewConnection(){
    qDebug()<<Q_FUNC_INFO<<"on new connection";
}


QString LocalClientSocket::getServerPath(){
    return clientSocket->fullServerName();
}
