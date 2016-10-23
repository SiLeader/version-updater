#
# Version Updater
# (C) 2016 SiLeader.
#

# Directory
PROJECT_ROOT	:= ..
BIN_DIR			:= $(PROJECT_ROOT)/bin
SRC_DIR			:= $(PROJECT_ROOT)/src

# Files
TARGET	:= $(BIN_DIR)/vu
SRC	:= $(wildcard $(SRC_DIR)/*.cpp)

# Compilers and Options
CXX			:= clang++
CXXFLAGS	:= -std=c++14 -O2

# Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
