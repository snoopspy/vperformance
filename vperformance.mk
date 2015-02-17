#
# c++11
#
CPPFLAGS += -std=c++11

#
# vperformance
#
VPERFORMANCE_PATH := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CPPFLAGS += -I$(VPERFORMANCE_PATH)/src
LDFLAGS += -L$(VPERFORMANCE_PATH)/lib
LDFLAGS += -lvperformance

