QT += core
QT -= gui

include (../../../vperformance.pri)

TARGET = dosomething
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DESTDIR  = $${PWD}/../../../bin

SOURCES += main.cpp
