# ==============================================================================
# Compiler settings
# ==============================================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP

# ==============================================================================
# Directory layout
# ==============================================================================
SRC_DIR   := src
BUILD_DIR := build
TARGET    := raytracer.exe

# ==============================================================================
# File tracking
# ==============================================================================
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# ==============================================================================
# Shell command compatibility
# MSYS2 defines MSYSTEM, normal Windows CMD usually does not.
# ==============================================================================
ifdef MSYSTEM
	MKDIR_BUILD = mkdir -p $(BUILD_DIR)
	REMOVE_BUILD = rm -rf $(BUILD_DIR)
	REMOVE_TARGET = rm -f $(TARGET)
else
	MKDIR_BUILD = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	REMOVE_BUILD = if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	REMOVE_TARGET = if exist $(TARGET) del /f /q $(TARGET)
endif

# ==============================================================================
# Build Rules
# ==============================================================================
.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo Linking executable: $@
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR):
	$(MKDIR_BUILD)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo Compiling: $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	@echo Cleaning build artifacts...
	$(REMOVE_BUILD)
	$(REMOVE_TARGET)

-include $(DEPS)