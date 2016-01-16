#include "socketlistener.h"
#include <QFile>
#include <iostream>
using namespace std;

SocketListener::SocketListener(QString path, Approver *approver, ConnectionaHandler *conn)
{
    QLocalServer::removeServer(path);
    this->path = path;
    this->connHandler = conn;
    this->approver =  approver;
    sock = new QLocalServer(this);
    sock->setSocketOptions(QLocalServer::WorldAccessOption);
}

void SocketListener::startListen()
{
    if ( sock->listen(path) )
    {
        qDebug() << "Listening On" << sock->serverName();
        connect(sock,SIGNAL(newConnection()),this,SLOT(handle()));
    }
    else
        cerr << "Error Listening On " << path.toStdString() << endl;
}

void SocketListener::handle()
{
    QLocalSocket *client = sock->nextPendingConnection();
    if ( approver->Approve(client) )
        connHandler->handle(client);
    else
        cerr << "Invalid App Connected" << endl;
}
