QT += core
QT -= gui

CONFIG += VPERFORMANCE_LIB_BUILD
include (vperformance.pri)

TARGET = $${VPERFORMANCE_LIB_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}/lib

HEADERS += \
  src/performance/vperformance.h \
  src/performance/vperformanceelapsedtimer.h \
  src/performance/vperformancechrono.h \
  src/VPerformance \
  src/VPerformanceChrono \
  src/VPerformanceElapsedTimer

SOURCES +=
