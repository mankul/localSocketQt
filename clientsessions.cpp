#include "clientsessions.h"

ClientSessions::ClientSessions()
{
    qDebug()<<Q_FUNC_INFO;
    clientNumber = 0;
}

int ClientSessions::createNewClientSocket(){
    QLocalSocket * newClient = new QLocalSocket();
    clientNumber += 1;
    clientSessions[clientNumber] = newClient;
    return clientNumber;
}


void ClientSessions::connectClientToServer(int clientNumber){
    QLocalSocket * client = clientSessions[clientNumber];
    qDebug()<<Q_FUNC_INFO<<"new client looking for connection to server";
    client->connectToServer();
}


QLocalSocket * ClientSessions::getClientSession(int clientNumber){

    return clientSessions[clientNumber];
}
