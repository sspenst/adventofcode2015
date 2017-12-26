TARGET = aoc2015
SRC_DIR := ./src
OBJ_DIR := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
CXX_FLAGS := -Wall -std=c++11

$(TARGET): $(OBJ_FILES)
	g++ -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	g++ $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean
