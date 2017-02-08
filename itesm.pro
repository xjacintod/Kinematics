#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T20:58:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = itesm
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    sockettcpip.cpp \
    controlador.cpp

HEADERS  += dialog.h \
    sockettcpip.h \
    controlador.h

FORMS    += dialog.ui
