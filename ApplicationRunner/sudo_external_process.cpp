#include "sudo_external_process.h"

SudoExternalProcess::SudoExternalProcess(ExternalProcess *process)
{
    this->command = QString("sudo %1").arg(process->getCommand());
}

SudoExternalProcess::SudoExternalProcess(ExternalProcess *process, Group group)
{
    this->command = QString("sudo -g %1 %2").arg(group.getGroupName(), process->getCommand());
}

SudoExternalProcess::SudoExternalProcess(ExternalProcess *process, User user)
{
    this->command = QString("sudo -u %1 %2").arg(user.getUserName(), process->getCommand());
}

SudoExternalProcess::SudoExternalProcess(ExternalProcess *process, User user, Group group)
{
    this->command = QString("sudo -u %1 -g %2 %3").arg(user.getUserName(), group.getGroupName(), process->getCommand());
}

