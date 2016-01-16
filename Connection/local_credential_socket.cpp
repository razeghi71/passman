#include "local_credential_socket.h"
#include <sys/socket.h>

LocalCredentialSocket::LocalCredentialSocket() : QLocalSocket()
{
    int sockDesc = socketDescriptor();
    int optval = 1;
    setsockopt(sockDesc,SOL_SOCKET,SO_PASSCRED,&optval,sizeof(optval));
}
