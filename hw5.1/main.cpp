#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.hpp"

int main() {
    srand(time(0)); // Seed random number generator
    int gridSize = 100;
    int initialDoodlebugs = 15;
    int initialAnts = 50;
    int initialQueens = 2;

    Grid grid(gridSize);

    grid.initialize(initialDoodlebugs, initialAnts, initialQueens);
    grid.runSimulation();

    return 0;
}
