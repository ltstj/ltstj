CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJ = main.o Critter.o Ant.o Doodlebug.o Grid.o

all: simulation

simulation: $(OBJ)
	$(CXX) $(CXXFLAGS) -o simulation $(OBJ)

main.o: main.cpp Critter.hpp Ant.hpp Doodlebug.hpp Grid.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Critter.o: Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Critter.cpp

Ant.o: Ant.cpp Ant.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Doodlebug.cpp

Grid.o: Grid.cpp Grid.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

clean:
	rm -f *.o simulation
