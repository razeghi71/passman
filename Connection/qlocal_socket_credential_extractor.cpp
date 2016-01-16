#include "qlocal_socket_credential_extractor.h"
#include <unistd.h>
#include <climits>
#include <QCryptographicHash>
#include <QFile>
#include <sys/socket.h>


QString QLocalSocketCredentialExtractor::getExecPath()
{
    int connectedProcessPid = getConnectedProcessPid();
    if (connectedProcessPid == -1 )
        return "";
    QString linkPath = "/proc/" + QString:: number(connectedProcessPid) + "/exe";
    char execPath[PATH_MAX] = {0};
    readlink(linkPath.toStdString().c_str(), execPath, sizeof(execPath));
    return QString(execPath);
}

QString QLocalSocketCredentialExtractor::getExecFileHash()
{
    QFile file(getExecPath());
    file.open(QFile::ReadOnly);
    QCryptographicHash hash(QCryptographicHash::Sha512);
    if ( hash.addData(&file) )
        return hash.result().toHex();
    return "";
}

int QLocalSocketCredentialExtractor::getConnectedProcessPid()
{
    int sockfd = sock->socketDescriptor();
    struct ucred *ucredp = new struct ucred;
    unsigned int len = sizeof(struct ucred);
    if ( getsockopt(sockfd,SOL_SOCKET,SO_PEERCRED,ucredp,&len) != -1 )
    {
        int pid = ucredp->pid;
        return pid;
    }
    return -1;
}


QLocalSocketCredentialExtractor::QLocalSocketCredentialExtractor(QLocalSocket *sock)
{
    this->sock = sock;
}
