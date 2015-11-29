#-------------------------------------------------
#
# Project created by QtCreator 2012-03-08T21:17:36
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = evolver
TEMPLATE = app

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.12/include

LIBS += -L/usr/local/Cellar/opencv/2.4.12/lib \
        -lopencv_core \
#        -lcv \
        -lopencv_highgui

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
