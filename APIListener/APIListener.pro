TEMPLATE = lib

CONFIG += qt staticlib

QT += network
QT-= gui

SOURCES = api_connection_approver.cpp \
          api_connection_handler.cpp

HEADERS = api_connection_approver.h \
          api_connection_handler.h

INCLUDEPATH += ../Connection ../ApplicationRunner ../DB
LIBS += -L../Connection -lConnection -L../ApplicationRunner -lApplicationRunner -L../DB -lDB