TEMPLATE = lib

CONFIG += qt staticlib

QT-= gui

SOURCES = keyboard_translator.cpp \
    raw_keyboard_reader.cpp
HEADERS = keyboard_translator.h \
    raw_keyboard_reader.h
