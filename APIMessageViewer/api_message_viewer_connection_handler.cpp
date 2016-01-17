#include "api_message_viewer_connection_handler.h"
#include <QCoreApplication>
#include "qlocal_socket_credential_extractor.h"
#include "api_message_viewer.h"

APIMessageViewerConnectionHandler::APIMessageViewerConnectionHandler(QString device)
{
    this->device = device;
}

void APIMessageViewerConnectionHandler::handle(QLocalSocket *sock)
{
    QLocalSocketCredentialExtractor *credentialExtractor = new QLocalSocketCredentialExtractor(sock);
    QString execFileHash = credentialExtractor->getExecFileHash();
    QString execPath = credentialExtractor->getExecPath();
    APIMessageViewer *messageViewer = new APIMessageViewer(execFileHash, execPath, device);

    while(true)
    {
        sock->waitForReadyRead();
        QList<QByteArray> command = sock->readLine(1024).trimmed().split(' ');

        if(command[0] == "end" || command[0] == "")
        {
            break;
        }
        if(command[0] == "view")
        {
            QString message;
            for (int i = 1 ; i < command.length(); i++ )
            {
                message += command[i] + " ";
            }
            bool allowed = messageViewer->Ask(message.trimmed());
            if (allowed)
                sock->write("1\n");
            else
                sock->write("0\n");
        }
    }
    sock->flush();
    sock->close();
    QCoreApplication::quit();
}
