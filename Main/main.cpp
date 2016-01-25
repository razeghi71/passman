#include <QCoreApplication>
#include <iostream>
#include "local_credential_socket.h"
#include "external_process.h"
#include "sudo_external_process.h"
#include "openvt_external_process.h"
#include "simple_external_process.h"
#include "user.h"
#include <QSettings>
#include <QThread>
#include "api_connection_approver.h"
#include "api_connection_handler.h"
#include "socketlistener.h"
#include "aes_crypto.h"
#include "db.h"

using namespace std;

void startPasswordGetter(QString path, User normalUser)
{
    ExternalProcess *passwordGetter
            = new SudoExternalProcess(
                new OpenvtExternalProcess(
                    new SudoExternalProcess(
                        new SimpleExternalProcess(path), normalUser
                    )
                , 23) // openvt terminal number
              );
    passwordGetter->run();
}

void startPasswordChecker(QString path)
{
    ExternalProcess *passwordChecker = new SimpleExternalProcess(path);
    passwordChecker->run();
}

QString initializeMasterPassword(LocalCredentialSocket *checkPassSock, LocalCredentialSocket *getPassSock)
{
    while(true){
        getPassSock->waitForReadyRead();
        QByteArray getPassRead = getPassSock->readLine();
        if (getPassRead.at(0) == '0' || getPassRead.at(0) == '1'){
            checkPassSock->write("end\n");
            if ( getPassRead.at(0) == '1' )
                return QString(getPassRead).split(" ").at(1);
            return "";
        }
        checkPassSock->write(getPassRead);
        checkPassSock->waitForReadyRead();
        getPassSock->write(checkPassSock->readLine());
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString settingsFile = "main.ini";

    QSettings settings(settingsFile, QSettings::NativeFormat);
    User normalUser(settings.value("normal_user","").toString());

    QString passwordGetterExec = settings.value("password_getter_exec","").toString();
    QString passwordCheckerExec = settings.value("password_checker_exec","").toString();

    QString passwordGetterSocket = settings.value("password_getter_socket","").toString();
    QString passwordCheckerSocket = settings.value("password_checker_socket","").toString();

    QString dbUsername = settings.value("db_username","").toString();
    QString dbPassword = settings.value("db_password","").toString();
    QString dbName = settings.value("db_name","").toString();
    QString apiListenerSocket = settings.value("api_listener_socket","/tmp/passman_api.sock").toString();
    QString apiMessageViewerExec = settings.value("api_messageviewer_exec","").toString();
    QString apiMessageViewerSocket = settings.value("api_messageviewer_socket","").toString();

    startPasswordGetter(passwordGetterExec, normalUser);
    startPasswordChecker(passwordCheckerExec);

    QThread::sleep(2);

    LocalCredentialSocket *getPassSock = new LocalCredentialSocket;
    LocalCredentialSocket *checkPassSock = new LocalCredentialSocket;

    getPassSock->connectToServer(passwordGetterSocket);
    checkPassSock->connectToServer(passwordCheckerSocket);

    QString master_password = initializeMasterPassword(checkPassSock, getPassSock);
    if ( master_password == "" )
    {
        cerr << "no master password provided" << endl;
        cerr << "quitting ..." << endl;
        QCoreApplication::quit();
    }

    DB::connect(dbUsername,dbPassword,dbName);

    SocketListener apiListener(apiListenerSocket,
                   new APIConnectionApprover(apiMessageViewerSocket,apiMessageViewerExec,normalUser),
                   new APIConnectionHandler(new AESCrypto(master_password.toStdString()),
                                            apiMessageViewerSocket,
                                            apiMessageViewerExec,
                                            normalUser)
                );
    apiListener.startListen();

    return a.exec();


}

