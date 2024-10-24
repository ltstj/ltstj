CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = src
INCLUDE = include
BIN = bin
OBJ = obj

SOURCES = $(wildcard $(SRC)/*.cpp)

OBJECTS = $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

EXECUTABLE = $(BIN)/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BIN)

.PHONY: all clean
