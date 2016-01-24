#include "api_connection_handler.h"
#include "qlocal_socket_credential_extractor.h"
#include "db.h"


APIConnectionHandler::APIConnectionHandler(Encryption *enc)
{
    this->enc = enc;
}

void APIConnectionHandler::handleGetCommand(QLocalSocket *sock)
{
    odb::database *db = DB::getDB();
    Application connectedApp = getConnectedApp(sock);
    sock->waitForReadyRead();
    int passwordId = sock->readLine().trimmed().toInt();
    ApplicationPasswordResult passwordResult (db->query<ApplicationPassword>
                                              (ApplicationPasswordQuery::app == connectedApp.getAppId() &&
                                               ApplicationPasswordQuery::passwordID == passwordId));

    if ( passwordResult.size() != 0 )
    {
        ApplicationPassword applicationPassword(*passwordResult.begin());

        sock->write(QVariant(applicationPassword.getUsername().get().c_str()).toByteArray());
        sock->write("\n");
        std::vector<unsigned char> dbEncryptedPassword = applicationPassword.getPassword();
        string encryptedPassword(dbEncryptedPassword.begin(),  dbEncryptedPassword.end());
        string decryptedPassword = enc->decrypt(encryptedPassword);
        sock->write(QVariant(decryptedPassword.c_str()).toByteArray());
        sock->write("\n");
    } else {
        sock->write("\n\n");
    }


    sock->close();
}

void APIConnectionHandler::handleSetCommand(QLocalSocket *sock)
{
    odb::database *db = DB::getDB();
    Application connectedApp = getConnectedApp(sock);

    sock->waitForReadyRead();
    QByteArray username = sock->readLine().trimmed();

    sock->waitForReadyRead();
    string encryptedPassword = enc->encrypt(sock->readLine().trimmed().toStdString());
    vector<unsigned char> dbEncryptedPassword (encryptedPassword.begin(), encryptedPassword.end());

    ApplicationPassword appPass(&connectedApp, username.toStdString(), dbEncryptedPassword);

    int passwordId = db->persist(appPass);

    sock->write(QVariant(passwordId).toByteArray());

    sock->write("\n");
    sock->close();
}

void APIConnectionHandler::handleUpdateCommand(QLocalSocket *sock)
{
    // Not Implemented
}

void APIConnectionHandler::handleDeleteCommand(QLocalSocket *sock)
{

}

Application APIConnectionHandler::getConnectedApp(QLocalSocket *sock)
{
    odb::database *db = DB::getDB();

    QLocalSocketCredentialExtractor credentialExtractor = QLocalSocketCredentialExtractor(sock);
    QString execPath     = credentialExtractor.getExecPath();
    QString execFileHash = credentialExtractor.getExecFileHash();

    ApplicationResult connectedAppResult (db->query<Application>
                                              (ApplicationQuery::executablePath == execPath.toStdString() &&
                                               ApplicationQuery::executableHash == execFileHash.toStdString())
                                          );

    Application connectedApp(*connectedAppResult.begin());

    return connectedApp;
}

void APIConnectionHandler::handle(QLocalSocket *sock)
{
    odb::database *db = DB::getDB();
    odb::transaction t (db->begin ());

    sock->waitForReadyRead();
    QByteArray command = sock->readLine().trimmed();
    if ( command == "get" )
    {
        handleGetCommand(sock);
    }
    else if ( command == "set" )
    {
        handleSetCommand(sock);
    }
    else if ( command == "update")
    {
        handleUpdateCommand(sock);
    }
    else if ( command == "delete" )
    {
        handleDeleteCommand(sock);
    } else {
        sock->close();
    }

    t.commit();
}
