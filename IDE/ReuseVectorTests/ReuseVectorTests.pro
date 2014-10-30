#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T18:52:13
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = ReuseVectorTests
CONFIG   += console \
			c++11
CONFIG   -= app_bundle

DESTDIR += ../../Bin/

TEMPLATE = app


SOURCES += ../../Tests/ReuseVectorTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

unix|win32: LIBS += -L$$PWD/../../Bin/ -lReuseVector

INCLUDEPATH += $$PWD/../../Src
DEPENDPATH += $$PWD/../../Src

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Bin/ReuseVector.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../Bin/libReuseVector.a
