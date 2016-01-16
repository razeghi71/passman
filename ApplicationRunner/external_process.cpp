#include "external_process.h"

void ExternalProcess::run()
{
    process.start(command);
}

QString ExternalProcess::getCommand()
{
    return command;
}
