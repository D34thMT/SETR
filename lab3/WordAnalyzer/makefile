# José Jesus - Word Analyzer 07/10/2026

# Module Name
MODULE_NAME = WORD_ANALYZER

# Paths
UNITY_ROOT = ../../shared_libs/src
FILE_UTIL_FOLDER = file_utils
WORD_LIST_FOLDER = word_list
BUILD_FOLDER = build
SRC = src
TEST = test

# Files
MAIN_SRC = $(SRC)/main.c
WORD_LIST_SRC = $(WORD_LIST_FOLDER)/word_list.c
FILE_UTIL_SRC = $(FILE_UTIL_FOLDER)/file_utils.c
UNITY = $(UNITY_ROOT)/unity.c
TEST_UTIL = $(TEST)/testfile_utils.c
TEST_WORD = $(TEST)/testword_list.c

# Include
INC_APP  = -I$(WORD_LIST_FOLDER) -I$(FILE_UTIL_FOLDER)  
INC_TEST = -I$(WORD_LIST_FOLDER) -I$(FILE_UTIL_FOLDER) -I$(UNITY_ROOT)

# Flags
C_COMPILER = gcc
CFLAGS = -std=c99 -Wall 
LDFLAGS = -lm

# Commands
CLEANUP = rm -rf
MKDIR = mkdir -p

# Executable Output Names
APP_TARGET = $(BUILD_FOLDER)/app
TEST_FILE_UTIL = $(BUILD_FOLDER)/test_$(FILE_UTIL_FOLDER)
TEST_WORD_LIST = $(BUILD_FOLDER)/test_$(WORD_LIST_FOLDER)

.PHONY: all default test clean

all: default

default: app

$(BUILD_FOLDER):
	$(MKDIR) $(BUILD_FOLDER)

$(APP_TARGET): $(MAIN_SRC) $(WORD_LIST_SRC) $(FILE_UTIL_SRC) | $(BUILD_FOLDER) 
	$(C_COMPILER) $(CFLAGS) $(INC_APP) $(MAIN_SRC) $(WORD_LIST_SRC) $(FILE_UTIL_SRC) -o $(APP_TARGET) $(LDFLAGS) 

$(TEST_FILE_UTIL): $(TEST_UTIL) $(FILE_UTIL_SRC) $(UNITY) | $(BUILD_FOLDER) 
	$(C_COMPILER) $(CFLAGS) $(INC_TEST) $(TEST_UTIL) $(FILE_UTIL_SRC) $(UNITY) -o $(TEST_FILE_UTIL) $(LDFLAGS) 

$(TEST_WORD_LIST): $(TEST_WORD) $(WORD_LIST_SRC) $(UNITY) | $(BUILD_FOLDER) 
	$(C_COMPILER) $(CFLAGS) $(INC_TEST)	$(TEST_WORD) $(WORD_LIST_SRC) $(UNITY) -o $(TEST_TARGET) $(LDFLAGS) 

app: $(APP_TARGET)
	./$(APP_TARGET)

test_utils: $(TEST_FILE_UTIL)
	./$(TEST_FILE_UTIL)

test_word: $(TEST_WORD_LIST)
	./$(TEST_WORD_LIST)


