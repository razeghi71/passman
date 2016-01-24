TEMPLATE = lib

CONFIG += qt staticlib  c++11

QT-= gui

SOURCES = keyboard_translator.cpp \
    raw_keyboard_reader.cpp
HEADERS = keyboard_translator.h \
    raw_keyboard_reader.h
