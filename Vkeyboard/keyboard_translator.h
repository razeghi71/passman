#ifndef KEYBOARDTRANSLATOR_H
#define KEYBOARDTRANSLATOR_H

#include <linux/input.h>
#include <QString>

class KeyboardTranslator
{
    QString keyboard_map[84];
    int keycode;
public:
    KeyboardTranslator(int keycode);
    QString keyCharachter();
    bool isEnter();
    bool isBackspace();
    bool isShift();

};

#endif // KEYBOARDTRANSLATOR_H
