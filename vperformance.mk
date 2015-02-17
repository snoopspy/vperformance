VPERFORMANCE_DIR := $(shell dirname $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))

#
# c++11
#
CPPFLAGS += -std=c++11

#
# vperformance
#
CPPFLAGS += -I$(VPERFORMANCE_DIR)/src
LDFLAGS += -L$(VPERFORMANCE_DIR)/lib
LDFLAGS += -lvperformance

