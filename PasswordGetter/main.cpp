#include <QCoreApplication>
#include <socketlistener.h>
#include "password_getter_connection_handler.h"
#include "Common/app_path_hash_approver.h"
#include <QSettings>
#include "raw_keyboard_reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketListener mainSocketListener ("/tmp/main_passget.sock",
                                       new AppPathHashApprover(""," "),
                                       new PasswordGetterConnectionHandler("/dev/input/by-path/platform-i8042-serio-0-event-kbd"));

    mainSocketListener.startListen();
    return a.exec();
}

