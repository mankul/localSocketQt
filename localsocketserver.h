#ifndef LOCALSOCKETSERVER_H
#define LOCALSOCKETSERVER_H

#include<QLocalServer>
#include<QLocalSocket>

class LocalSocketServer: public QObject
{
    Q_OBJECT
public:
    LocalSocketServer();
    Q_INVOKABLE QString getServerName();
    Q_INVOKABLE void getSocketDescriptor();
    void getClient();
private:
    QLocalServer * localServer;
    qintptr serverSocketDescriptor;
    QMap<int, QLocalSocket *> clientSocketsMap;
    int clientCount;
};

#endif // LOCALSOCKETSERVER_H
