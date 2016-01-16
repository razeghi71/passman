#include <QCoreApplication>
#include <socketlistener.h>
#include <QSettings>
#include "Common/app_path_hash_approver.h"
#include "password_checker_connection_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketListener mainSocketListener ("/tmp/main_passcheck.sock",
                                       new AppPathHashApprover("",""),
                                       new PasswordCheckerConnectionHandler("passcheck.ini"));
    mainSocketListener.startListen();
    return a.exec();
}

