#include "api_connection_approver.h"
#include "qlocal_socket_credential_extractor.h"


APIConnectionApprover::APIConnectionApprover()
{
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
                                                                    ApplicationQuery::executable_hash == execFileHash.toStdString()
                                       ));
    if ( appExecEqualQuery.size() == 0 ) {
        // new app connected
    } else if ( appHashExecEqualQuery.size() == 0 ) {
        // app hash updated
    }
    t.commit ();
    return true;
}

