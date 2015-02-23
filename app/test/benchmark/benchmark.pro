QT += core
QT -= gui

TARGET = benchmark
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DESTDIR  = $${PWD}/../../../bin

QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lwinmm

SOURCES += main.cpp
