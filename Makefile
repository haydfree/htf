# Compiler and linker settings
CC = clang
LD = clang
AR = ar

# Project settings
PROJECT_NAME = htf
VERSION = 0.1.0

# Directory structure
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TEST_DIR = test
LIB_DIR = lib
BIN_DIR = bin

# Target names
LIB_NAME = $(PROJECT_NAME)
LIB_STATIC = $(LIB_DIR)/lib$(LIB_NAME).a
LIB_SHARED = $(LIB_DIR)/lib$(LIB_NAME).so.$(VERSION)
TEST_BIN = $(BIN_DIR)/$(PROJECT_NAME)_test
MAIN_BIN = $(BIN_DIR)/$(PROJECT_NAME)

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
MAIN_SRCS = $(wildcard $(SRC_DIR)/main.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test/%.o, $(TEST_SRCS))
MAIN_OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(MAIN_SRCS))

# Compiler and linker flags
CFLAGS = -std=c99 -Wextra -Werror -Wpedantic -Wall
DEBUG_FLAGS = -g3 -O0
RELEASE_FLAGS = -O2 -DNDEBUG
INCLUDE_FLAGS = -I. -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)

# Default to debug build
CFLAGS += $(DEBUG_FLAGS)

# Default target
all: directories $(LIB_STATIC) $(TEST_BIN)

# Create necessary directories
directories:
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/test $(LIB_DIR) $(BIN_DIR)

# Library targets
$(LIB_STATIC): $(OBJS)
	@echo "Building static library: $@"
	@$(AR) rcs $@ $^

$(LIB_SHARED): $(OBJS)
	@echo "Building shared library: $@"
	@$(CC) -shared -Wl,-soname,lib$(LIB_NAME).so.1 -o $@ $^

# Test binary
$(TEST_BIN): $(TEST_OBJS) $(LIB_STATIC)
	@echo "Building test binary: $@"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -I$(TEST_DIR) $^ -o $@ $(LDFLAGS) -l$(LIB_NAME)

# Main binary (if main.c exists)
ifneq ($(MAIN_SRCS),)
$(MAIN_BIN): $(MAIN_OBJS) $(LIB_STATIC)
	@echo "Building main binary: $@"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $^ -o $@ $(LDFLAGS) -l$(LIB_NAME)
endif

# Object file rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(BUILD_DIR)/test/%.o: $(TEST_DIR)/%.c
	@echo "Compiling test: $<"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -I$(TEST_DIR) -c $< -o $@

# Build modes
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

release: CFLAGS += $(RELEASE_FLAGS)
release: clean all

# Testing
test: $(TEST_BIN)
	@echo "Running tests..."
	@./$(TEST_BIN)

# Debugging
debug-test: $(TEST_BIN)
	@echo "Debugging tests..."
	@lldb -o "process handle SIGTRAP -n true -s true -p true" -o "run" -- $(TEST_BIN)

# Installation
install: $(LIB_STATIC) $(LIB_SHARED)
	@echo "Installing libraries..."
	@install -d /usr/local/lib
	@install -m 644 $(LIB_STATIC) /usr/local/lib/
	@install -m 755 $(LIB_SHARED) /usr/local/lib/
	@ln -sf lib$(LIB_NAME).so.$(VERSION) /usr/local/lib/lib$(LIB_NAME).so.1
	@ln -sf lib$(LIB_NAME).so.1 /usr/local/lib/lib$(LIB_NAME).so
	@install -d /usr/local/include/$(LIB_NAME)
	@install -m 644 $(INCLUDE_DIR)/*.h /usr/local/include/$(LIB_NAME)/

# Cleanup
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR) *.core

# Git operations
commit:
	@echo "Committing changes..."
	@git add .
	@git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	@git push origin main

# Help
help:
	@echo "Available targets:"
	@echo "  all        - Build everything (default)"
	@echo "  debug      - Build with debug flags"
	@echo "  release    - Build with release flags"
	@echo "  test       - Build and run tests"
	@echo "  debug-test - Build and debug tests"
	@echo "  install    - Install libraries and headers"
	@echo "  clean      - Remove all build artifacts"
	@echo "  commit     - Commit changes to git"
	@echo "  help       - Show this help message"

.PHONY: all directories debug release test debug-test install clean commit help

