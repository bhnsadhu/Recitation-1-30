CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g -fsanitize=address
INCLUDES = -I./includes

BIN_DIR = bin
SRC_DIR = src
TEST_DIR = tests

DRIVER_SRC = $(SRC_DIR)/driver.cc $(SRC_DIR)/solution.cc
TEST_SRC = $(TEST_DIR)/tests.cc $(SRC_DIR)/solution.cc

DRIVER_TARGET = $(BIN_DIR)/exec
TEST_TARGET = $(BIN_DIR)/tests

.PHONY: all clean tests exec run

all: exec tests

exec: $(DRIVER_TARGET)

tests: $(TEST_TARGET)

$(DRIVER_TARGET): $(DRIVER_SRC)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DRIVER_SRC) -o $(DRIVER_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -I./tests $(TEST_SRC) -o $(TEST_TARGET)

run: $(DRIVER_TARGET)
	@echo "Running driver..."
	@$(DRIVER_TARGET)

clean:
	rm -rf $(BIN_DIR)/*
