#ifndef QLOCALSOCKETCREDENTIALEXTRACTOR_H
#define QLOCALSOCKETCREDENTIALEXTRACTOR_H

#include <QString>
#include <QLocalSocket>

class QLocalSocketCredentialExtractor
{
    QLocalSocket* sock;
public:
    QLocalSocketCredentialExtractor(QLocalSocket* sock);
    QString getExecPath();
    QString getExecFileHash();
    int getConnectedProcessPid();

};

#endif // QLOCALSOCKETCREDENTIALEXTRACTOR_H
