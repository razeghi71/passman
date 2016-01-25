#ifndef APICONNECTIONHANDLER_H
#define APICONNECTIONHANDLER_H

#include <connectionahandler.h>
#include "Application.h"
#include "ApplicationPassword.h"
#include "encryption.h"
#include "message_viewer_client.h"

class APIConnectionHandler : public ConnectionaHandler, MessageViewerClient
{
    Encryption *enc;
public:
    APIConnectionHandler(Encryption *enc, QString messageViewerSocket , QString messageViewerPath, User normalUser);
    void handle(QLocalSocket *sock);
    void handleGetCommand(QLocalSocket *sock);
    void handleSetCommand(QLocalSocket *sock);
    void handleUpdateCommand(QLocalSocket *sock);
    void handleDeleteCommand(QLocalSocket *sock);
    Application getConnectedApp(QLocalSocket *sock);
};

#endif // APICONNECTIONHANDLER_H
