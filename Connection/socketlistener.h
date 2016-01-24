#ifndef SOCKETLISTENER_H
#define SOCKETLISTENER_H

#include <QString>
#include <approver.h>
#include <connectionahandler.h>
#include <QLocalServer>
#include <QObject>

class SocketListener : public QObject
{
Q_OBJECT
    QLocalServer *sock;
    ConnectionaHandler *connHandler;
    Approver *approver;
    QString path;
public:
    SocketListener(QString path, Approver *approver, ConnectionaHandler *conn);
    void startListen();
private slots:
    void handle();

};

#endif // SOCKETLISTENER_H
