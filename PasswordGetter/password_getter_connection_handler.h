#ifndef PASSWORDGETTERCONNECTIONHANDLER_H
#define PASSWORDGETTERCONNECTIONHANDLER_H

#include "connectionahandler.h"
#include <QObject>

class PasswordGetterConnectionHandler : public ConnectionaHandler
{
private:
    QString keyboardDevice;
    QString getSecretCode(QLocalSocket *sock);
    bool checkPassword(QLocalSocket *sock,QString enteredMasterPassword);
public:
    PasswordGetterConnectionHandler(QString keyboardDevice);
    void handle(QLocalSocket *sock);
};

#endif // PASSWORDGETTERCONNECTIONHANDLER_H
