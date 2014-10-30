#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T18:35:46
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Testbed
CONFIG   += console \
			c++11
CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR += ../../Bin/

SOURCES += main.cpp

unix|win32: LIBS += -L$$PWD/../../Bin/ -lReuseVector

INCLUDEPATH += $$PWD/../../Src
DEPENDPATH += $$PWD/../../Src

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Bin/ReuseVector.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../Bin/libReuseVector.a
