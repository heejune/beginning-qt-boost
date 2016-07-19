#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T22:17:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBoostExample
TEMPLATE = app

INCLUDEPATH += /Users/hekim/Documents/qt-udemy/install/boost/boost_1_61_0

LIBS += -L/Users/hekim/Documents/qt-udemy/install/boost/boost_1_61_0/stage/lib -lboost_thread -lboost_system

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
