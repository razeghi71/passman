TEMPLATE = lib

CONFIG += qt staticlib  c++11

QT-= gui

SOURCES = Encryption.cpp \
    encryption.cpp \
    aes_crypto.cpp

HEADERS = Encryption.h \
    encryption.h \
    aes_crypto.h


