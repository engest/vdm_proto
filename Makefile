BUILD_TYPE ?= Debug
#BUILD_TYPE ?= Release

include config.mk

TARGET_BASE := lib
TARGET_DIR := $(TARGET_BASE)/$(BUILD_TYPE)
TARGET := $(TARGET_DIR)/libvdm_proto.so

INC += inc/vdm_proto.h
INC_DIRS += -I$(SYSTEMC_HOME)/include
INC_DIRS += -I$(SYSTEMC_HOME)/include/tlm_utils
INC_DIRS += -I./inc

OBJECTS := src/vdm_proto.o

CXX ?= g++
CPPFLAGS ?= -g -fPIC $(INC_DIRS)

rebuildables=$(OBJECTS) $(TARGET) $(TARGET_DIR) $(TARGET_BASE) doxygen

all: $(TARGET)

$(TARGET_DIR):
	mkdir -p $@

$(TARGET): $(OBJECTS) $(INC) $(TARGET_DIR)
	g++ -shared -o $@ $<

.PHONEY:

doc: Doxyfile
	doxygen

clean:
	rm -rf $(rebuildables)
