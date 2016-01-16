#ifndef RAWKEYBOARDREADER_H
#define RAWKEYBOARDREADER_H

#include <QString>


class RawKeyboardReader
{
    QString device;
    int fd;

    bool openDevice();
    bool closeDevice();
    bool readEvent(struct input_event *event);
    bool grab();
    bool ungrab();
public:
    RawKeyboardReader(QString device);
    QString readLine();

};

#endif // RAWKEYBOARDREADER_H
