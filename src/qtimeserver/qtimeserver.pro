QT += core
QT -= gui
QT += sql network
TARGET = qtimeserver
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    database.cpp \
    test.cpp \
    user.cpp \
    tcpserver.cpp \
    basecontroller.cpp \
    usercontroller.cpp \
    application.cpp

HEADERS += \
    database.h \
    test.h \
    user.h \
    tcpserver.h \
    basecontroller.h \
    usercontroller.h \
    application.h

