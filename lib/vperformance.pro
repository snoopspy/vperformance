QT -= gui

CONFIG += VPERFORMANCE_LIB_BUILD
include (vperformance.pri)

TARGET    = $${VPERFORMANCE_LIB_NAME}
TEMPLATE  = lib
CONFIG   += staticlib
DESTDIR   = $${PWD}

HEADERS += \
  ../src/vperformance.h

SOURCES += \
  ../src/vperformance.cpp

