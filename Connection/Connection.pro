TEMPLATE = lib

CONFIG += qt staticlib c++11

QT += network
QT-= gui

SOURCES = approver.cpp \
          connectionahandler.cpp \
          socketlistener.cpp \
          Common/app_path_hash_approver.cpp \
          local_credential_socket.cpp \
          qlocal_socket_credential_extractor.cpp

HEADERS = approver.h \
          connectionahandler.h \
          socketlistener.h \
          Common/app_path_hash_approver.h \
          local_credential_socket.h \
          qlocal_socket_credential_extractor.h

