#include "api_connection_approver.h"
#include "qlocal_socket_credential_extractor.h"
#include "sudo_external_process.h"
#include "openvt_external_process.h"
#include "simple_external_process.h"
#include "local_credential_socket.h"
#include "external_process.h"

APIConnectionApprover::APIConnectionApprover(QString messageViewerPath, User normalUser)
{
    this->messageViewerPath = messageViewerPath;
    this->normalUser = normalUser;
}

void APIConnectionApprover::startMessageViewer()
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

bool APIConnectionApprover::viewMessage(QString message)
{
    LocalCredentialSocket socket;
    socket.connectToServer();
    QByteArray bytedMessage = QVariant(message+"\n").toByteArray();
    socket.write(bytedMessage);
    socket.waitForReadyRead();
    return socket.readLine().trimmed().toInt() == 1;
}


void APIConnectionApprover::handleNewApp(QString execFileHash, QString execPath, auto_ptr<odb::database> db)
{
    startMessageViewer();
    bool shouldAdd = viewMessage("A new apps wants to connect. add it to list?");
    if ( shouldAdd )
    {
        Application app(execPath.toStdString(), execFileHash.toStdString());
        db->persist(app);
    }
}

void APIConnectionApprover::handleUpdatedApp(QString execFileHash, ApplicationResult appExecEqualQuery, QString execPath, auto_ptr<odb::database> db)
{
    startMessageViewer();
    bool shouldUpdate = viewMessage("An existing's app hash changed. Want to update?");
    if ( shouldUpdate  )
    {
        for ( ApplicationResult::iterator it (appExecEqualQuery.begin());
              it != appExecEqualQuery.end() ;
              it++ ) {
            Application& p(*it);
            p.setExecutablePath(execPath.toStdString());
            p.setExecutableHash(execFileHash.toStdString());
            db->update(p);
            break;
        }
    }
}

bool APIConnectionApprover::Approve(QLocalSocket *sock)
{
    QLocalSocketCredentialExtractor credentialExtractor(sock);
    QString execFileHash = credentialExtractor.getExecFileHash();
    QString execPath = credentialExtractor.getExecPath();

    auto_ptr<odb::database> db = DB::getDB();

    odb::transaction t (db->begin ());

    ApplicationResult appExecEqualQuery (db->query<Application> (ApplicationQuery::executable_path == execPath.toStdString()));
    ApplicationResult appHashExecEqualQuery (db->query<Application>(ApplicationQuery::executable_path == execPath.toStdString() &&
                                                                    ApplicationQuery::executable_hash == execFileHash.toStdString()));
    if ( appExecEqualQuery.size() == 0 )
        handleNewApp(execFileHash, execPath, db);
    else if ( appHashExecEqualQuery.size() == 0 )
        handleUpdatedApp(execFileHash, appExecEqualQuery, execPath, db);

    t.commit ();
    return true;
}

