#ifndef LOCALCLIENTSOCKET_H
#define LOCALCLIENTSOCKET_H

#include<qlocalsocket.h>
class LocalClientSocket: public QObject
{
    Q_OBJECT
public:
    LocalClientSocket();
    void connectToServer();
    Q_INVOKABLE QString getServerPath();
    void onNewConnection();

private:
    QLocalSocket * clientSocket;
};
#endif // LOCALCLIENTSOCKET_H
