QT += core
QT -= gui

include (../../../../../google/gtest/gtest.pri)
include (../../../vperformance.pri)

TARGET = performance_test
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DESTDIR = $${PWD}/../../../bin

SOURCES += \
    chrono_test.cpp \
    elapsedtimer_test.cpp

HEADERS += \
    mytest.h
