QT       += core
QT       -= gui

TARGET = performance_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

INCLUDEPATH += ../../src

SOURCES += main.cpp \
    ../../src/vperformance.cpp

HEADERS += \
    ../../src/vperformance.h
