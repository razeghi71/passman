#ifndef PASSWORDCHECKERCONNECTIONHANDLER_H
#define PASSWORDCHECKERCONNECTIONHANDLER_H

#include "connectionahandler.h"
#include<QObject>

class PasswordCheckerConnectionHandler : public ConnectionaHandler
{
private:
    QString settingsFile;
public:
    PasswordCheckerConnectionHandler(QString settingsFile);
    void handle(QLocalSocket *sock);
};

#endif // PASSWORDCHECKERCONNECTIONHANDLER_H
