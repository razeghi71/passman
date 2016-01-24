#include "api_message_viewer.h"
#include <unistd.h>
#include <raw_keyboard_reader.h>
#include <curses.h>
#include <QDebug>

APIMessageViewer::APIMessageViewer(QString appHash, QString appExec, QString device)
{
    srand(time(0));
    this->appExec = appExec;
    this->appHash = appHash;
    this->device = device;
}

bool APIMessageViewer::Ask(QString message)
{
    RawKeyboardReader keyboardReader(device);
    while (true)
    {
        QString allowCode = QString::number(rand() % 1000000);
        QString rejectCode = QString::number(rand() % 1000000);
        QString appExecMessage = "Application Executable Path : " + appExec;
        QString appHashMessage = "Application Executable Hash : " + appHash;
        QString allowMessage = "To Allow Enter : " + allowCode ;
        QString rejectMessage = "To Reject Enter : " + rejectCode;

        initCurses();
        printMessage(message,0);
        printMessage(appExecMessage,3);
        printMessage(appHashMessage,3);
        printMessage(allowMessage,2);
        printMessage(rejectMessage,1);

        QString userInput = keyboardReader.readLine().trimmed();
        finilizeCurses();

        qDebug() << userInput << allowCode ;

        if ( userInput == allowCode )
            return true;
        if ( userInput == rejectCode )
            return false;
    }
}

winsize APIMessageViewer::getTerminalSize()
{
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    return size;
}

QPoint APIMessageViewer::getNewRandomPoint(int strWidth)
{
    winsize terminalSize = getTerminalSize();
    int row = 0;
    do {
        row = rand() % terminalSize.ws_row;
    } while (printedPointRows.contains(row));
    printedPointRows.insert(row);
    int col = rand() % (terminalSize.ws_col -  strWidth);
    return QPoint(row,col);
}

void APIMessageViewer::printMessage(QString message, int colorPair)
{
    QPoint messagePlace = getNewRandomPoint(message.length());
    attron(COLOR_PAIR(colorPair));
    mvaddstr(messagePlace.x(),messagePlace.y(),message.toStdString().c_str());
    attroff(COLOR_PAIR(colorPair));
    refresh();
}

void APIMessageViewer::initCurses()
{
    initscr();
    clear();
    start_color();
    init_pair(1,COLOR_BLUE,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    init_pair(3,COLOR_BLACK,COLOR_CYAN);
}

void APIMessageViewer::finilizeCurses()
{
    endwin();
}


