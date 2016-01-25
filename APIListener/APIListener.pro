TEMPLATE = lib

CONFIG += qt staticlib c++11

QT += network
QT-= gui

SOURCES = api_connection_approver.cpp \
          api_connection_handler.cpp \
    message_viewer_client.cpp

HEADERS = api_connection_approver.h \
          api_connection_handler.h \
    message_viewer_client.h

INCLUDEPATH += ../Connection \
               ../ApplicationRunner \
               ../DB \
               ../Encryption
