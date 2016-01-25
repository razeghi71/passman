#include "api_connection_approver.h"
#include "qlocal_socket_credential_extractor.h"
#include "sudo_external_process.h"
#include "openvt_external_process.h"
#include "simple_external_process.h"
#include "local_credential_socket.h"
#include "external_process.h"
#include <QThread>

APIConnectionApprover::APIConnectionApprover(QString messageViewerSocket, QString messageViewerPath, User normalUser)
    : MessageViewerClient(messageViewerSocket, messageViewerPath, normalUser)
{
}

void APIConnectionApprover::handleNewApp(QLocalSocket *sock)
{
    QLocalSocketCredentialExtractor credentialExtractor(sock);
    QString execFileHash = credentialExtractor.getExecFileHash();
    QString execPath = credentialExtractor.getExecPath();

    odb::database *db = DB::getDB();

    bool shouldAdd = startMessageViewerAndGetResult("A new apps wants to connect. add it to list?");
    if ( shouldAdd )
    {
        Application app(execPath.toStdString(), execFileHash.toStdString());
        db->persist(app);
    }
}

void APIConnectionApprover::handleUpdatedApp(QLocalSocket *sock, Application& app)
{
    QLocalSocketCredentialExtractor credentialExtractor(sock);
    QString execFileHash = credentialExtractor.getExecFileHash();
    QString execPath = credentialExtractor.getExecPath();

    odb::database *db = DB::getDB();

    bool shouldUpdate = startMessageViewerAndGetResult("An existing's app hash changed. Want to update?");
    if ( shouldUpdate  )
    {
        app.setExecutablePath(execPath.toStdString());
        app.setExecutableHash(execFileHash.toStdString());
        db->update(app);
    }
}

bool APIConnectionApprover::Approve(QLocalSocket *sock)
{
    QLocalSocketCredentialExtractor credentialExtractor(sock);
    QString execFileHash = credentialExtractor.getExecFileHash();
    QString execPath = credentialExtractor.getExecPath();

    odb::database *db = DB::getDB();

    odb::transaction t (db->begin ());

    ApplicationResult appExecEqualQuery (db->query<Application> (ApplicationQuery::executablePath == execPath.toStdString()));
    ApplicationResult appHashExecEqualQuery (db->query<Application>(ApplicationQuery::executablePath == execPath.toStdString() &&
                                                                    ApplicationQuery::executableHash == execFileHash.toStdString()));

    if ( appExecEqualQuery.size() == 0 )
        handleNewApp(sock);

    else if ( appHashExecEqualQuery.size() == 0 )
    {
        Application& app(*appExecEqualQuery.begin());
        handleUpdatedApp(sock, app);
    }

    t.commit ();
    return true;
}

