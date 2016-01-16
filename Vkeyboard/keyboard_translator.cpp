#include "keyboard_translator.h"

KeyboardTranslator::KeyboardTranslator(int keycode)
{
    this->keycode = keycode;
    keyboard_map[KEY_ESC]= "";
    keyboard_map[KEY_1]= "1";
    keyboard_map[KEY_2]= "2";
    keyboard_map[KEY_3]= "3";
    keyboard_map[KEY_4]= "4";
    keyboard_map[KEY_5]= "5";
    keyboard_map[KEY_6]= "6";
    keyboard_map[KEY_7]= "7";
    keyboard_map[KEY_8]= "8";
    keyboard_map[KEY_9]= "9";
    keyboard_map[KEY_0]= "0";
    keyboard_map[KEY_MINUS]= "-";
    keyboard_map[KEY_EQUAL]= "=";
    keyboard_map[KEY_BACKSPACE]= "";
    keyboard_map[KEY_TAB]= "\t";
    keyboard_map[KEY_Q]= "q";
    keyboard_map[KEY_W]= "w";
    keyboard_map[KEY_E]= "e";
    keyboard_map[KEY_R]= "r";
    keyboard_map[KEY_T]= "t";
    keyboard_map[KEY_Y]= "y";
    keyboard_map[KEY_U]= "u";
    keyboard_map[KEY_I]= "i";
    keyboard_map[KEY_O]= "o";
    keyboard_map[KEY_P]= "p";
    keyboard_map[KEY_LEFTBRACE]= "[";
    keyboard_map[KEY_RIGHTBRACE]= "]";
    keyboard_map[KEY_ENTER]= "";
    keyboard_map[KEY_LEFTCTRL]= "";
    keyboard_map[KEY_A]= "a";
    keyboard_map[KEY_S]= "s";
    keyboard_map[KEY_D]= "d";
    keyboard_map[KEY_F]= "f";
    keyboard_map[KEY_G]= "g";
    keyboard_map[KEY_H]= "h";
    keyboard_map[KEY_J]= "j";
    keyboard_map[KEY_K]= "k";
    keyboard_map[KEY_L]= "l";
    keyboard_map[KEY_SEMICOLON]= ";";
    keyboard_map[KEY_APOSTROPHE]= "'";
    keyboard_map[KEY_GRAVE]= "`";
    keyboard_map[KEY_LEFTSHIFT]= "";
    keyboard_map[KEY_BACKSLASH]= "\\";
    keyboard_map[KEY_Z]= "z";
    keyboard_map[KEY_X]= "x";
    keyboard_map[KEY_C]= "c";
    keyboard_map[KEY_V]= "v";
    keyboard_map[KEY_B]= "b";
    keyboard_map[KEY_N]= "n";
    keyboard_map[KEY_M]= "m";
    keyboard_map[KEY_COMMA]= ",";
    keyboard_map[KEY_DOT]= ".";
    keyboard_map[KEY_SLASH]= "/";
    keyboard_map[KEY_RIGHTSHIFT]= "";
    keyboard_map[KEY_KPASTERISK]= "";
    keyboard_map[KEY_LEFTALT]= "";
    keyboard_map[KEY_SPACE]= " ";
    keyboard_map[KEY_CAPSLOCK]= "";
    keyboard_map[KEY_F1]= "";
    keyboard_map[KEY_F2]= "";
    keyboard_map[KEY_F3]= "";
    keyboard_map[KEY_F4]= "";
    keyboard_map[KEY_F5]= "";
    keyboard_map[KEY_F6]= "";
    keyboard_map[KEY_F7]= "";
    keyboard_map[KEY_F8]= "";
    keyboard_map[KEY_F9]= "";
    keyboard_map[KEY_F10]= "";
    keyboard_map[KEY_NUMLOCK]= "";
    keyboard_map[KEY_SCROLLLOCK]= "";
    keyboard_map[KEY_KP7]= "7";
    keyboard_map[KEY_KP8]= "8";
    keyboard_map[KEY_KP9]= "9";
    keyboard_map[KEY_KPMINUS]= "-";
    keyboard_map[KEY_KP4]= "4";
    keyboard_map[KEY_KP5]= "5";
    keyboard_map[KEY_KP6]= "6";
    keyboard_map[KEY_KPPLUS]= "+";
    keyboard_map[KEY_KP1]= "1";
    keyboard_map[KEY_KP2]= "2";
    keyboard_map[KEY_KP3]= "3";
    keyboard_map[KEY_KP0]= "0";
    keyboard_map[KEY_KPDOT]= ".";
}

QString KeyboardTranslator::keyCharachter()
{
    if ( keycode < KEY_KPDOT )
        return keyboard_map[keycode];
    return "";
}

bool KeyboardTranslator::isEnter()
{
    if (keycode == KEY_ENTER )
        return true;
    return false;
}

bool KeyboardTranslator::isBackspace()
{
    if (keycode == KEY_BACKSPACE )
        return true;
    return false;
}

bool KeyboardTranslator::isShift()
{
    if (keycode == KEY_LEFTSHIFT || KEY_RIGHTSHIFT )
        return true;
    return false;
}

