#-------------------------------------------------
#
# Project created by QtCreator 2014-11-20T23:35:19
#
#-------------------------------------------------

QT       -= gui

TARGET = ReuseVector
TEMPLATE = lib

CONFIG += c++11
DESTDIR += ../../Bin/

DEFINES += LIBRARY_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    ../../Src/Library/ReuseVector.h \
	../../Src/Library/ReuseVectorIterator.h

SOURCES += \
    ../../Src/Library/ReuseVector.cpp \
    ../../Src/Library/ReuseVectorIterator.cpp

OTHER_FILES +=
