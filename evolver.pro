#-------------------------------------------------
#
# Project created by QtCreator 2012-03-08T21:17:36
#
#-------------------------------------------------

QT       += core gui

TARGET = evolver
TEMPLATE = app

INCLUDEPATH += /usr/include/opencv

LIBS += -L/usr/lib \
        -lcxcore \
        -lcv \
        -lhighgui

SOURCES += main.cpp\
        mainwindow.cpp \
    miasto.cpp \
    antena.cpp \
    populacja.cpp \
    chromosom.cpp \
    about.cpp \
    geneticthread.cpp

HEADERS  += mainwindow.h \
    miasto.h \
    antena.h \
    populacja.h \
    chromosom.h \
    cursor.h \
    about.h \
    geneticthread.h

FORMS    += mainwindow.ui \
    about.ui
