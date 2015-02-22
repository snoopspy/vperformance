QT += core
QT -= gui
TARGET = performance_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

include (../../../../../google/gtest/gtest.pri)
include (../../../vperformance.pri)

SOURCES += \
    chrono_test.cpp \
    elapsedtimer_test.cpp \
    mytest.cpp

HEADERS += \
    mytest.h
