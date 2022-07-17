#ifndef CLIENTSESSIONS_H
#define CLIENTSESSIONS_H

#include<qobject.h>
#include<qlocalsocket.h>
#include<localclientsocket.h>

class ClientSessions: public QObject
{
    Q_OBJECT

public:

    Q_PROPERTY(LocalClientSocket * localClientSocket READ localClientSocket WRITE setLocalClientSocket NOTIFY localClientSocketChanged)
    ClientSessions();
    Q_INVOKABLE int createNewClientSocket();
    Q_INVOKABLE LocalClientSocket * getClientSession(int);
    Q_INVOKABLE void connectClientToServer(int);

    LocalClientSocket *localClientSocket() const;
    void setLocalClientSocket(LocalClientSocket *newLocalClientSocket);

signals:
    void localClientSocketChanged();

private:
    QMap<int, LocalClientSocket *> clientSessions;
    int clientNumber;
    LocalClientSocket *m_localClientSocket;
};


#endif // CLIENTSESSIONS_H
