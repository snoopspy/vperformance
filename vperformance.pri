#-------------------------------------------------
# c++11
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11

#-------------------------------------------------
# vperformance
#-------------------------------------------------
VPERFORMANCE_PATH = $${PWD}
INCLUDEPATH += $${VPERFORMANCE_PATH}/src

HEADERS += \
  $${VPERFORMANCE_PATH}/src/performance/vperformance.h \
  $${VPERFORMANCE_PATH}/src/performance/vperformancechrono.h \
  $${VPERFORMANCE_PATH}/src/performance/vperformanceelapsedtimer.h \
  $${VPERFORMANCE_PATH}/src/performance/vperformancenull.h
