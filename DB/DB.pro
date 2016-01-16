TEMPLATE = lib

CONFIG += qt staticlib

QT-= gui

SOURCES = Application.cpp \
    Application-odb.cxx \
    ApplicationPassword.cpp \
    ApplicationPassword-odb.cxx \
    db.cpp

HEADERS = Application.h \
    Application-odb.hxx \
    ApplicationPassword.h \
    ApplicationPassword-odb.hxx \
    db.h
