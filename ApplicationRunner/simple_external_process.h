#ifndef SIMPLEEXTERNALPROCESS_H
#define SIMPLEEXTERNALPROCESS_H

#include "external_process.h"

class SimpleExternalProcess : public ExternalProcess
{
public:
    SimpleExternalProcess(QString command);
};

#endif // SIMPLEEXTERNALPROCESS_H
