CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o organism.o ant.o doodlebug.o grid.o

all: simulation

simulation: $(OBJS)
	$(CXX) $(CXXFLAGS) -g -o simulation $(OBJS)

main.o: main.cpp grid.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

organism.o: organism.cpp organism.hpp
	$(CXX) $(CXXFLAGS) -g -c organism.cpp

ant.o: ant.cpp ant.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -g -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -g -c doodlebug.cpp

grid.o: grid.cpp grid.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -g -c grid.cpp

clean:
	rm -f *.o simulation
