#include "app_path_hash_approver.h"
#include <sys/socket.h>
#include <iostream>
#include <qlocal_socket_credential_extractor.h>

using namespace std;

AppPathHashApprover::AppPathHashApprover(QString path, QString hash)
{
    this->validPath = path;
    this->validHash = hash;
}



bool AppPathHashApprover::Approve(QLocalSocket *sock)
{
    return true; //for test
    QLocalSocketCredentialExtractor credentialExtractor (sock);

    QString execPath = credentialExtractor.getExecPath();
    QString execHash = credentialExtractor.getExecFileHash();

    if ( execHash == validHash && execPath == validHash)
        return true;
    return false;
}

