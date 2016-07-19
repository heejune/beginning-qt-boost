#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T11:46:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBoostRestClient
TEMPLATE = app

INCLUDEPATH += /Users/hekim/Documents/qt-udemy/install/boost/boost_1_61_0

SOURCES += main.cpp \
    widget.cpp \
    asioclient.cpp

HEADERS  += widget.h \
    asioclient.h
FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../install/boost/boost_1_61_0/stage/lib/release/ -lboost_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../install/boost/boost_1_61_0/stage/lib/debug/ -lboost_system
else:unix: LIBS += -L$$PWD/../../../install/boost/boost_1_61_0/stage/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../install/boost/boost_1_61_0/stage
DEPENDPATH += $$PWD/../../../install/boost/boost_1_61_0/stage

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../install/boost/boost_1_61_0/stage/lib/release/libboost_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../install/boost/boost_1_61_0/stage/lib/debug/libboost_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../install/boost/boost_1_61_0/stage/lib/release/boost_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../install/boost/boost_1_61_0/stage/lib/debug/boost_system.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../install/boost/boost_1_61_0/stage/lib/libboost_system.a
