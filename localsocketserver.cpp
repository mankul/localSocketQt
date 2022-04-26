#include "localsocketserver.h"

LocalSocketServer::LocalSocketServer()
{
    clientCount = 0;
    localServer = new QLocalServer();
    if(!localServer->listen("localServer")){
        qDebug()<<Q_FUNC_INFO<<"Unable to start server"<<localServer->errorString();
    }
    qDebug()<<Q_FUNC_INFO<<"server started";
    connect(localServer, &QLocalServer::newConnection, this, &LocalSocketServer::getClient);
}

QString LocalSocketServer::getServerName(){
    return localServer->serverName();
}

void LocalSocketServer::getSocketDescriptor(){
    qDebug()<<Q_FUNC_INFO<<localServer->socketDescriptor();
    serverSocketDescriptor =  localServer->socketDescriptor();

}

void LocalSocketServer::getClient(){
    qDebug()<<Q_FUNC_INFO<<"new client connected to server";
    QLocalSocket * newClient = localServer->nextPendingConnection();
    clientCount +=1;
    clientSocketsMap[clientCount] = newClient;
}
