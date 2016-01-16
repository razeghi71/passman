TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT+=network
QT-=guit

SOURCES += main.cpp

HEADERS +=

INCLUDEPATH += ../Connection ../ApplicationRunner
LIBS += -L../Connection -lConnection -L../ApplicationRunner -lApplicationRunner

