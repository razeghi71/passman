#ifndef APIMESSAGEVIEWER_H
#define APIMESSAGEVIEWER_H

#include <QString>
#include <sys/ioctl.h>
#include <QPoint>
#include <QSet>


class APIMessageViewer
{
    QString appHash;
    QString appExec;
    QString device;
    QSet<int> printedPointRows;

    winsize getTerminalSize();
    QPoint getNewRandomPoint(int strWidth);
    void printMessage(QString message, int colorPair);
    void initCurses();
    void finilizeCurses();
public:
    APIMessageViewer(QString appHash, QString appExec, QString device);
    bool Ask(QString message);

};

#endif // APIMESSAGEVIEWER_H
