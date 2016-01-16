#include "openvt_external_process.h"

OpenvtExternalProcess::OpenvtExternalProcess(ExternalProcess *process, int ttyNumber)
{
    command =  QString("openvt -f -w -s -c %1 -- %2").arg(QString::number(ttyNumber), process->getCommand());
}
