TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT+=network
QT-=gui

SOURCES += main.cpp

HEADERS +=

INCLUDEPATH += ../Connection \
               ../ApplicationRunner \
               ../APIListener \
               ../Encryption \
               ../DB

LIBS += -L../APIListener -lAPIListener \
        -L../Connection -lConnection \
        -L../DB -lDB -L/usr/lib/odb -lodb  -lodb-mysql \
        -L../Encryption -lEncryption -lcryptopp \
        -L../ApplicationRunner -lApplicationRunner



