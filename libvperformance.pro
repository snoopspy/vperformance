QT -= core gui

CONFIG += VPERFORMANCE_LIB_BUILD
include (vperformance.pri)

TARGET = $${VPERFORMANCE_LIB_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}/lib

HEADERS += \
  src/performance/vperformance.h

SOURCES += \
  src/performance/vperformance.cpp
