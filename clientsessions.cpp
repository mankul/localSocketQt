#include "clientsessions.h"

ClientSessions::ClientSessions()
{
    qDebug()<<Q_FUNC_INFO;
    clientNumber = 0;
}

int ClientSessions::createNewClientSocket(){
    LocalClientSocket * newClient = new LocalClientSocket();
    clientNumber += 1;
    clientSessions[clientNumber] = newClient;
    return clientNumber;
}


void ClientSessions::connectClientToServer(int clientNumber){
    LocalClientSocket * client = clientSessions[clientNumber];
    qDebug()<<Q_FUNC_INFO<<"new client looking for connection to server";
    client->connectToServer();
}


LocalClientSocket * ClientSessions::getClientSession(int clientNumber){

    return clientSessions[clientNumber];
}

LocalClientSocket *ClientSessions::localClientSocket() const
{
    return m_localClientSocket;
}

void ClientSessions::setLocalClientSocket(LocalClientSocket *newLocalClientSocket)
{
    if (m_localClientSocket == newLocalClientSocket)
        return;
    m_localClientSocket = newLocalClientSocket;
    emit localClientSocketChanged();
}
