TEMPLATE = lib

CONFIG += qt staticlib  c++11

QT += network
QT-= gui

SOURCES = \
    sudo_external_process.cpp \
    external_process.cpp \
    openvt_external_process.cpp \
    user.cpp \
    group.cpp \
    simple_external_process.cpp
HEADERS = \
    sudo_external_process.h \
    external_process.h \
    openvt_external_process.h \
    user.h \
    group.h \
    simple_external_process.h
