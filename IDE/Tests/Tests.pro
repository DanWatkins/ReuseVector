#-------------------------------------------------
#
# Project created by QtCreator 2014-11-20T23:34:29
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = ReuseVectorTests
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++11
DESTDIR += ../../Bin/

INCLUDEPATH += ../../Src/Library/ \
				../../Ext/gtest/inc/

TEMPLATE = app


SOURCES += \
			../../Src/Tests/Main.cpp \
    ../../Src/Tests/Test_ReuseVector.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

unix|win32: LIBS += -L$$OUT_PWD/../../Bin/ -lReuseVector
unix|win32: LIBS += -L$$OUT_PWD/../External/gtest/ -lgtest

HEADERS +=
