# José Jesus, Set/2026
# Adapted from Paulo Pedreiras

MODULE_NAME = configData

# Paths
UNITY_ROOT = ../../shared_libs
SRC_FOLDER = src
CONFDATA_FOLDER = configData
BUILD_FOLDER = build
TEST_FOLDER = test

# Source Files
MAIN_SRC = $(SRC_FOLDER)/main.c
MODULE_SRC = $(CONFDATA_FOLDER)/configData.c
TEST_SRC = $(TEST_FOLDER)/test$(MODULE_NAME).c
UNITY_SRC = $(UNITY_ROOT)/src/unity.c

# Include Directories
INC_APP = -I./$(MODULE_NAME)
INC_TEST = -I./$(MODULE_NAME) -I$(UNITY_ROOT)/src

# Commands
CLEANUP = rm -rf
MKDIR = mkdir -p

# Compiler & Flags
C_COMPILER = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Executable Output Names
APP_TARGET = $(BUILD_FOLDER)/app
TEST_TARGET = $(BUILD_FOLDER)/test_$(MODULE_NAME)

.PHONY: all default test clean


all: default

default: app

$(BUILD_FOLDER):
	$(MKDIR) $(BUILD_FOLDER)

$(APP_TARGET): $(MAIN_SRC) $(MODULE_SRC) | $(BUILD_FOLDER)
	$(C_COMPILER) $(CFLAGS) $(INC_APP) $(MAIN_SRC) $(MODULE_SRC) -o $(APP_TARGET) $(LDFLAGS)

$(TEST_TARGET): $(UNITY_SRC) $(MODULE_SRC) $(TEST_SRC) | $(BUILD_FOLDER)
	$(C_COMPILER) $(CFLAGS) $(INC_TEST) $(UNITY_SRC) $(MODULE_SRC) $(TEST_SRC) -o $(TEST_TARGET) $(LDFLAGS)


app: $(APP_TARGET)
	./$(APP_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	$(CLEANUP) $(BUILD_FOLDER)