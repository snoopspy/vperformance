#-------------------------------------------------
# c++11
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11

#-------------------------------------------------
# library name
#-------------------------------------------------
VPERFORMANCE_LIB_NAME = vperformance
android-g++ {
  VPERFORMANCE_LIB_NAME = $${VPERFORMANCE_LIB_NAME}_android
}
CONFIG(debug, debug|release) {
  VPERFORMANCE_LIB_NAME = $${VPERFORMANCE_LIB_NAME}_d
}

#-------------------------------------------------
# vperformance
#-------------------------------------------------
VPERFORMANCE_PATH = $${PWD}/..
INCLUDEPATH += $${VPERFORMANCE_PATH}/src
!CONFIG(VPERFORMANCE_LIB_BUILD) {
  PRE_TARGETDEPS += $${VPERFORMANCE_PATH}/lib/lib$${VPERFORMANCE_LIB_NAME}.a
  LIBS += -L$${VPERFORMANCE_PATH}/lib
  LIBS += -l$${VPERFORMANCE_LIB_NAME}
}
