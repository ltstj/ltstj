#makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = team_formation
SRCS = main.cpp student.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = student.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean