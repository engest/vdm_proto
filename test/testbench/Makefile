BUILD_TYPE ?= Debug

include ../../config.mk

TARGET_BASE := bin
TARGET_DIR := $(TARGET_BASE)/$(BUILD_TYPE)
TARGET := $(TARGET_DIR)/testbench

INC += inc/testbench.h
INC_DIRS += -I$(SYSTEMC_HOME)/include
INC_DIRS += -I$(SYSTEMC_HOME)/include/tlm_utils
INC_DIRS += -I../../inc
INC_DIRS += -I../tlmdriver/inc
INC_DIRS += -I./inc
LIBS += -L$(SYSTEMC_HOME)/lib -lsystemc
LIBS += -L../../lib/$(BUILD_TYPE) -lvdm_proto
LIBS += -L../tlmdriver/lib/$(BUILD_TYPE) -ltlmdriver

OBJECTS := src/testbench.o src/vdm_main.o

CXX ?= g++
CPPFLAGS ?= -std=c++11 -g -fPIC $(INC_DIRS)


rebuildables=$(OBJECTS) $(TARGET) $(TARGET_DIR) $(TARGET_BASE)
all: $(TARGET)

$(TARGET_DIR):
	mkdir -p $@

$(TARGET): $(OBJECTS) $(INC) $(TARGET_DIR)
	g++ -o $@ $(OBJECTS) $(LIBS)

.PHONEY:
clean:
	rm -rf $(rebuildables)
