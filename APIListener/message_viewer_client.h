#ifndef MESSAGEVIEWERCLIENT_H
#define MESSAGEVIEWERCLIENT_H

#include <QString>
#include "user.h"

class MessageViewerClient
{
    QString messageViewerSocket;
    QString messageViewerPath;
    User normalUser;
    void startMessageViewer();
    bool getResultOfMessage(QString message);
public:
    MessageViewerClient(QString messageViewerSocket , QString messageViewerPath, User normalUser);


    bool startMessageViewerAndGetResult(QString message);
};

#endif // MESSAGEVIEWERCLIENT_H
