#-------------------------------------------------
#
# Project created by QtCreator 2017-01-30T16:52:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tecdemty
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    controlador.cpp \
    ethsocket.cpp

HEADERS  += dialog.h \
    controlador.h \
    ethsocket.h

FORMS    += dialog.ui
