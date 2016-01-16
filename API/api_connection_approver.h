#ifndef APICONNECTIONAPPROVER_H
#define APICONNECTIONAPPROVER_H
#include "approver.h"
#include <db.h>

class APIConnectionApprover : public Approver
{
public:
    APIConnectionApprover();
    bool Approve(QLocalSocket *sock);
};

#endif // APICONNECTIONAPPROVER_H
