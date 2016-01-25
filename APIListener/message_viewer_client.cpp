#include "message_viewer_client.h"
#include "local_credential_socket.h"
#include "sudo_external_process.h"
#include "openvt_external_process.h"
#include "simple_external_process.h"
#include <QThread>

MessageViewerClient::MessageViewerClient(QString messageViewerSocket, QString messageViewerPath, User normalUser)
{
    this->messageViewerSocket = messageViewerSocket;
    this->messageViewerPath = messageViewerPath;
    this->normalUser = normalUser;
}

bool MessageViewerClient::startMessageViewerAndGetResult(QString message)
{
    startMessageViewer();
    QThread::sleep(2);
    return getResultOfMessage(message);
}

void MessageViewerClient::startMessageViewer()
{
    ExternalProcess *messageViewer
            = new SudoExternalProcess(
                new OpenvtExternalProcess(
                    new SudoExternalProcess(
                        new SimpleExternalProcess(messageViewerPath), normalUser
                    )
                , 23) // openvt terminal number
              );
    messageViewer->run();
}

bool MessageViewerClient::getResultOfMessage(QString message)
{
    LocalCredentialSocket socket;
    socket.connectToServer(messageViewerSocket);
    QByteArray bytedMessage = QVariant(message+"\n").toByteArray();
    socket.write(bytedMessage);
    socket.flush();
    socket.waitForReadyRead();
    return socket.readLine().trimmed().toInt() == 1;
}

