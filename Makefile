# ==============================================================================
# Windows/MinGW Compiler settings
# ==============================================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP

# ==============================================================================
# Directory layout (Assumes your .cpp files are here)
# ==============================================================================
SRC_DIR   := src
BUILD_DIR := build
TARGET    := raytracer.exe

# ==============================================================================
# File tracking (Automated for Windows Powershell/CMD)
# ==============================================================================
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# ==============================================================================
# Build Rules
# ==============================================================================
.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo Linking executable: $@
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@echo Compiling: $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	@echo Cleaning build artifacts...
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(TARGET) del /f /q $(TARGET)

-include $(DEPS)
