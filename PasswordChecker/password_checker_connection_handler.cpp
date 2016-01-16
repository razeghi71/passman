#include "password_checker_connection_handler.h"
#include <QSettings>
#include <QCryptographicHash>
#include <QCoreApplication>

PasswordCheckerConnectionHandler::PasswordCheckerConnectionHandler(QString settingsFile)
{
    this->settingsFile = settingsFile;
}

void PasswordCheckerConnectionHandler::handle(QLocalSocket *sock)
{
    QSettings settings(settingsFile, QSettings::NativeFormat);
    while(true)
    {
        sock->waitForReadyRead();
        QList<QByteArray> command = sock->readLine(1024).trimmed().split(' ');

        if(command[0] == "end" || command[0] == "")
        {
            break;
        }
        if(command[0] == "secret_code")
        {
            QByteArray secretCodeAnswer = QVariant(settings.value("secret_code","").toString()+"\n").toByteArray();
            sock->write(secretCodeAnswer);
        }

        if(command[0] == "check")
        {
            QByteArray masterPasswordHash = settings.value("master_password_hash","").toByteArray();
            QCryptographicHash hash(QCryptographicHash::Sha512);
            hash.addData(command[1]);
            if ( hash.result().toHex() == masterPasswordHash )
                sock->write("1\n");
            else
                sock->write("0\n");
        }
    }
    sock->flush();
    sock->close();
    QCoreApplication::quit();
}

