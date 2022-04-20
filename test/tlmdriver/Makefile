BUILD_TYPE ?= Debug

include ../../config.mk

TARGET_BASE := lib
TARGET_DIR := $(TARGET_BASE)/$(BUILD_TYPE)
TARGET := $(TARGET_DIR)/libtlmdriver.so

INC += inc/tlmdriver.h
INC_DIRS += -I$(SYSTEMC_HOME)/include
INC_DIRS += -I$(SYSTEMC_HOME)/include/tlm_utils
INC_DIRS += -I./inc

OBJECTS := src/tlmdriver.o

CXX ?= g++
CPPFLAGS ?= -g -fPIC $(INC_DIRS)


rebuildables=$(OBJECTS) $(TARGET) $(TARGET_DIR) $(TARGET_BASE)
all: $(TARGET)

$(TARGET_DIR):
	mkdir -p $@

$(TARGET): $(OBJECTS) $(INC) $(TARGET_DIR)
	g++ -shared -o $@ $<

.PHONEY:
clean:
	rm -rf $(rebuildables)
