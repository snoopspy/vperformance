QT += core
QT -= gui

include (vperformance.pri)

TARGET = vperformance
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
