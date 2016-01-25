#ifndef APICONNECTIONAPPROVER_H
#define APICONNECTIONAPPROVER_H
#include "approver.h"
#include "db.h"
#include <QString>
#include "user.h"
#include "message_viewer_client.h"

class APIConnectionApprover : public Approver, MessageViewerClient
{
public:
    APIConnectionApprover(QString messageViewerSocket , QString messageViewerPath, User normalUser);
    bool Approve(QLocalSocket *sock);
    void handleNewApp(QLocalSocket *sock);
    void handleUpdatedApp(QLocalSocket *sock, Application& app);
};

#endif // APICONNECTIONAPPROVER_H
