#ifndef APICONNECTIONAPPROVER_H
#define APICONNECTIONAPPROVER_H
#include "approver.h"
#include "db.h"
#include <QString>
#include "user.h"

class APIConnectionApprover : public Approver
{
    QString messageViewerPath;
    User normalUser;
public:
    APIConnectionApprover(QString messageViewerPath, User normalUser);
    void startMessageViewer();
    bool viewMessage(QString message);
    bool Approve(QLocalSocket *sock);
    void handleNewApp(QString execFileHash, QString execPath, auto_ptr<odb::database> db);
    void handleUpdatedApp(QString execFileHash, ApplicationResult appExecEqualQuery, QString execPath, auto_ptr<odb::database> db);
};

#endif // APICONNECTIONAPPROVER_H
