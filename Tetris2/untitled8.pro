#-------------------------------------------------
#
# Project created by QtCreator 2022-06-27T14:12:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled8
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    assistant.cpp \
    record.cpp \
    exit.cpp \
    reset.cpp \
    GameWindow.cpp \
    GameArea.cpp \
    NextArea.cpp \
    Block.cpp

HEADERS  += widget.h \
    assistant.h \
    record.h \
    exit.h \
    reset.h \
    GameWindow.h \
    GameArea.h \
    NextArea.h \
    Block.h

FORMS    += widget.ui \
    assistant.ui \
    record.ui \
    exit.ui \
    reset.ui \
    GameWindow.ui

RESOURCES += \
    background.qrc

DISTFILES +=
