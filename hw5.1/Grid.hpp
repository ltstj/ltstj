#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Critter.hpp"

class Grid {
public:
    Grid(int size);
    ~Grid();

    void initialize(int numDoodlebugs, int numAnts, int numQueens);
    void runSimulation();
    void printGrid();

    Critter* getCell(int x, int y) const;
    void setCell(int x, int y, Critter* critter);
    bool isValidPosition(int x, int y) const;

private:
    int size;
    std::vector<std::vector<Critter*>> grid;

    void placeCritter(Critter* critter);
    void step();
    bool isSimulationOver();
};

#endif
