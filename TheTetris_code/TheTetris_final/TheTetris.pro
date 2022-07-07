#-------------------------------------------------
#
# Project created by QtCreator 2022-06-27T14:12:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheTetris
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
    Block.cpp \
    HoldArea.cpp \
    menu.cpp

HEADERS  += widget.h \
    assistant.h \
    record.h \
    exit.h \
    reset.h \
    GameWindow.h \
    GameArea.h \
    NextArea.h \
    Block.h \
    HoldArea.h \
    menu.h

FORMS    += widget.ui \
    assistant.ui \
    record.ui \
    exit.ui \
    reset.ui \
    GameWindow.ui \
    menu.ui

RESOURCES += \
    background.qrc

DISTFILES +=
