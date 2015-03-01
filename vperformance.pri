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
	$${PWD}/src/performance/vperformance.h \
	$${PWD}/src/performance/vperformancechrono.h \
	$${PWD}/src/performance/vperformanceelapsedtimer.h \
	$${PWD}/src/performance/vperformancenull.h
