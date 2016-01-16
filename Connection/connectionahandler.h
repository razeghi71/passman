#ifndef CONNECTIONAHANDLER_H
#define CONNECTIONAHANDLER_H

#include <QLocalSocket>

class ConnectionaHandler
{
public:
    virtual void handle(QLocalSocket *sock) = 0;
};

#endif // CONNECTIONAHANDLER_H
