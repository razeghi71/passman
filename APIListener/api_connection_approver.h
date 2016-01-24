#ifndef APICONNECTIONAPPROVER_H
#define APICONNECTIONAPPROVER_H
#include "approver.h"
#include "db.h"
#include <QString>
#include "user.h"

class APIConnectionApprover : public Approver
{
    QString messageViewerSocket;
    QString messageViewerPath;
    User normalUser;
public:
    APIConnectionApprover(QString messageViewerSocket , QString messageViewerPath, User normalUser);
    void startMessageViewer();
    bool viewMessage(QString message);
    bool Approve(QLocalSocket *sock);
    void handleNewApp(QLocalSocket *sock);
    void handleUpdatedApp(QLocalSocket *sock, Application& app);
};

#endif // APICONNECTIONAPPROVER_H
