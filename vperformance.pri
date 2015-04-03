#-------------------------------------------------
# c++11
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11

#-------------------------------------------------
# win32
#-------------------------------------------------
win32:LIBS += -lwinmm

#-------------------------------------------------
# vperformance
#-------------------------------------------------
VPERFORMANCE_DIR = $${PWD}
INCLUDEPATH += $${VPERFORMANCE_DIR}/src

HEADERS += \
	$${PWD}/src/performance/vperformance.h \
	$${PWD}/src/performance/vperformancechrono.h \
	$${PWD}/src/performance/vperformanceelapsedtimer.h \
	$${PWD}/src/performance/vperformancegettickcount.h \
	$${PWD}/src/performance/vperformancegettimeofday.h \
	$${PWD}/src/performance/vperformancenull.h \
	$${PWD}/src/performance/vperformancetimegettime.h

