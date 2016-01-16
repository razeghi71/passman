#ifndef SUDOEXTERNALPROCESS_H
#define SUDOEXTERNALPROCESS_H

#include "external_process.h"
#include "group.h"
#include "user.h"

class SudoExternalProcess : public ExternalProcess
{
public:
    SudoExternalProcess(ExternalProcess *process);
    SudoExternalProcess(ExternalProcess *process, Group group);
    SudoExternalProcess(ExternalProcess *process, User user);
    SudoExternalProcess(ExternalProcess *process, User user, Group group);
};

#endif // SUDOEXTERNALPROCESS_H

