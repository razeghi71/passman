TEMPLATE = app
CONFIG += qt
QT += network
QT -= gui
TARGET = PasswordChecker
SOURCES = main.cpp \
          password_checker_connection_handler.cpp

HEADERS = password_checker_connection_handler.h

INCLUDEPATH += ../Connection
LIBS += -L../Connection -lConnection
