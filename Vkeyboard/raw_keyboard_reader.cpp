#include "raw_keyboard_reader.h"

#include <QDebug>
#include <unistd.h>
#include <fcntl.h>
#include <keyboard_translator.h>
#include <iostream>
using namespace std;

bool RawKeyboardReader::openDevice()
{
    fd = open(device.toStdString().c_str(), O_RDONLY);
    return fd != -1;
}

bool RawKeyboardReader::closeDevice()
{
    return close(fd) != -1;
}

bool RawKeyboardReader::readEvent(input_event *event)
{
    int size = sizeof(struct input_event);
    int rd = read (fd, event, size);
    return rd >= size;
}

bool RawKeyboardReader::grab()
{
    return ioctl(fd, EVIOCGRAB, 1) != -1;
}

bool RawKeyboardReader::ungrab()
{
    return ioctl(fd, EVIOCGRAB, 1)  != -1;
}

RawKeyboardReader::RawKeyboardReader(QString device)
{
    this->device = device;
}

QString RawKeyboardReader::readLine()
{
    input_event *ev = new input_event;

    if ( !openDevice() ) {
        cerr << "Can not open input device! (do you have sufficient permissions?)" << endl;
        return "";
    }

    QString line;
    grab();
    while (1) {
        if ( !readEvent(ev) )
        {
            cerr << "reading event failed." << endl;
            return "";
        }

        if (ev->value == 1 && ev->type == 1)
        {
            KeyboardTranslator keyPressed = KeyboardTranslator(ev->code);
            if (keyPressed.isEnter())
            {
                break;
            } else if (keyPressed.isBackspace())
            {
                if (line.length() != 0 )
                {
                    line = line.left(line.length() - 1);
                }
            } else
            {
                line += keyPressed.keyCharachter();
            }
        }
    }
    ungrab();
    closeDevice();
    return line;
}

