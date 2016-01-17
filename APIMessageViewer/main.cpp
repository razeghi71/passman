#include <QCoreApplication>
#include <QString>
#include <QSettings>
#include "Common/app_path_hash_approver.h"
#include "api_message_viewer_connection_handler.h"
#include "socketlistener.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketListener mainSocketListener ("/tmp/main_viewer.sock",
                                       new AppPathHashApprover(""," "),
                                       new APIMessageViewerConnectionHandler("/dev/input/by-path/platform-i8042-serio-0-event-kbd"));

    mainSocketListener.startListen();

    return a.exec();
}

