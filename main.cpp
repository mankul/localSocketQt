#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <localsocketserver.h>
#include <localclientsocket.h>
#include <clientsessions.h>
#include <QQuickView>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<LocalSocketServer>("server", 1,0, "LocalSocketServer");
    qmlRegisterType<LocalClientSocket>("client", 1,0, "LocalSocketClient");

//    ClientSessions * clientSession = new ClientSessions();

    qmlRegisterType<ClientSessions>("session", 1, 0, "ClientSessions");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
