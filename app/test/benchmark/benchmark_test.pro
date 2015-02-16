QT += core
QT -= gui
TARGET = benchmark_test
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp
