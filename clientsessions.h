#ifndef CLIENTSESSIONS_H
#define CLIENTSESSIONS_H

#include<qobject.h>
#include<qlocalsocket.h>
#include<localclientsocket.h>

class ClientSessions: public QObject
{
    Q_OBJECT
public:
    ClientSessions();
    Q_INVOKABLE int createNewClientSocket();
    Q_INVOKABLE QLocalSocket * getClientSession(int);
    Q_INVOKABLE void connectClientToServer(int);

private:
    QMap<int, QLocalSocket *> clientSessions;
    int clientNumber;

};


#endif // CLIENTSESSIONS_H
