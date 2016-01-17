TEMPLATE = app
CONFIG += qt
QT += network
QT -= gui
TARGET = APIMessageViewer
SOURCES = main.cpp \
          api_message_viewer.cpp \
          api_message_viewer_connection_handler.cpp

HEADERS = api_message_viewer.h \
          api_message_viewer_connection_handler.h

INCLUDEPATH += ../Connection ../Vkeyboard
LIBS += -L../Connection -lConnection -L../Vkeyboard -lVkeyboard -lncurses
