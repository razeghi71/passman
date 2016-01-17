#ifndef APICONNECTIONHANDLER_H
#define APICONNECTIONHANDLER_H

#include <connectionahandler.h>

class APIConnectionHandler : public ConnectionaHandler
{
    APIConnectionHandler();
    void handle(QLocalSocket *sock);
};

#endif // APICONNECTIONHANDLER_H
