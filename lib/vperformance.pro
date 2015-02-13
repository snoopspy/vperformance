QT -= gui

CONFIG += VPERFORMANCE_LIB_BUILD
include (vperformance.pri)

TARGET = $${VPERFORMANCE_LIB_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
  ../src/vperformance.h

SOURCES += \
  ../src/vperformance.cpp
