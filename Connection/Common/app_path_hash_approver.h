#ifndef PASSWORDCHECKERCONNECTIONAPPROVER_H
#define PASSWORDCHECKERCONNECTIONAPPROVER_H

#include "approver.h"

class AppPathHashApprover : public Approver
{
    QString validPath;
    QString validHash;
public:
    AppPathHashApprover(QString path, QString hash);
    bool Approve(QLocalSocket *sock);

};

#endif // PASSWORDCHECKERCONNECTIONAPPROVER_H
