#ifndef APIMESSAGEVIEWERCONNECTIONHANDLER_H
#define APIMESSAGEVIEWERCONNECTIONHANDLER_H

#include <connectionahandler.h>

class APIMessageViewerConnectionHandler : public ConnectionaHandler
{
    QString device;
public:
    APIMessageViewerConnectionHandler(QString device);

    void handle(QLocalSocket *sock);
};

#endif // APIMESSAGEVIEWERCONNECTIONHANDLER_H
