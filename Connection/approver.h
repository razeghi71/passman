#ifndef APPROVER_H
#define APPROVER_H

#include <QLocalSocket>

class Approver
{
public:
    virtual bool Approve(QLocalSocket *sock) = 0;
};

#endif // APPROVER_H
