#include "password_getter_connection_handler.h"
#include <QSettings>
#include <QCryptographicHash>
#include <raw_keyboard_reader.h>
#include <iostream>
#include <QCoreApplication>

using namespace std;


PasswordGetterConnectionHandler::PasswordGetterConnectionHandler(QString keyboardDevice)
{
    this->keyboardDevice = keyboardDevice;
}

QString PasswordGetterConnectionHandler::getSecretCode(QLocalSocket *sock)
{
    sock->write("secret_code\n");
    sock->waitForReadyRead();
    return sock->readLine().trimmed();
}

bool PasswordGetterConnectionHandler::checkPassword(QLocalSocket *sock, QString enteredMasterPassword)
{
    QByteArray requestCheck = QVariant("check " + enteredMasterPassword + "\n").toByteArray();
    sock->write(requestCheck);
    sock->waitForReadyRead();
    if ( sock->readLine().trimmed() == "1" )
        return true;
    return false;
}

void PasswordGetterConnectionHandler::handle(QLocalSocket *sock)
{
    RawKeyboardReader reader = RawKeyboardReader(keyboardDevice);

    QString secretCode = getSecretCode(sock);

    srand(time(0));

    while (true)
    {
        int exitNum = rand() % 1000000;
        cout << "Here is the secret_code that you gave us: " << secretCode.toStdString() << endl;
        cout << "Please enter master password or " << exitNum << " to exit : ";
        cout.flush();
        QString enteredMasterPassword = reader.readLine().trimmed();
        cout << endl;

        if (QString::number(exitNum) == enteredMasterPassword)
        {
            sock->write("0\n");
            break;
        }
        else if( checkPassword(sock,enteredMasterPassword) ) {
            QByteArray masterPasswordRespone= QVariant("1 " + enteredMasterPassword + "\n").toByteArray();
            sock->write(masterPasswordRespone);
            break;
        }
    }
    sock->flush();
    sock->close();
    QCoreApplication::quit();
}

