#ifndef OPENVTEXTERNALPROCESS_H
#define OPENVTEXTERNALPROCESS_H

#include "external_process.h"

class OpenvtExternalProcess : public ExternalProcess
{
public:
    OpenvtExternalProcess(ExternalProcess *process, int ttyNumber);
};

#endif // OPENVTEXTERNALPROCESS_H
