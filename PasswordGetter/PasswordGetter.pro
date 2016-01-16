TEMPLATE = app
CONFIG += qt
QT += network
QT -= gui
TARGET = PasswordGetter
SOURCES = main.cpp \
          password_getter_connection_handler.cpp

HEADERS = password_getter_connection_handler.h
INCLUDEPATH += ../Connection ../Vkeyboard
LIBS += -L../Connection -lConnection -L../Vkeyboard -lVkeyboard
