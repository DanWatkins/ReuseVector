#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T18:10:59
#
#-------------------------------------------------

QT       -= core gui

TARGET = ReuseVector
TEMPLATE = lib
CONFIG += staticlib \
			c++11

DESTDIR += ../../Bin/

SOURCES += ../../Src/ReuseVector.cpp

HEADERS += ../../Src/ReuseVector.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
