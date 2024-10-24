#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Grid.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

// Constructor for Grid
Grid::Grid(int size) : size(size), grid(size, std::vector<Critter*>(size, nullptr)) {}

// Destructor for Grid
Grid::~Grid() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            delete grid[i][j];
        }
    }
}

// Function to initialize the grid with doodlebugs and ants
void Grid::initialize(int numDoodlebugs, int numAnts, int numQueens) {
   
    for (int i = 0; i < numQueens; ++i) {
        placeCritter(new QueenAnt(rand() % size, rand() % size, this));
    }
    for (int i = 0; i < numAnts; ++i) {
        placeCritter(new Ant(rand() % size, rand() % size, this, 'w'));
    }
    for (int i = 0; i < numDoodlebugs; ++i) {
        placeCritter(new Doodlebug(rand() % size, rand() % size, this));
    }
}

// Function to place a critter at a random empty position
void Grid::placeCritter(Critter* critter) {
    int x = critter->getX();
    int y = critter->getY();
    while (grid[x][y] != nullptr) {
        x = rand() % size;
        y = rand() % size;
    }
    grid[x][y] = critter;
    critter->setPosition(x, y);
}

// Function to run the simulation
void Grid::runSimulation() {
    bool simulationRunning = true;
    while (simulationRunning) {
        step();
        printGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        simulationRunning = !isSimulationOver();
    }
}

// Function to perform one step of the simulation
void Grid::step() {
    // Move all doodlebugs first
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() == 'X') {
                grid[i][j]->move();
            }
        }
    }
    // Move all ants next
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() != 'X') {
                grid[i][j]->move();
            }
        }
    }
    // Breed all doodlebugs
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() == 'X') {
                grid[i][j]->breed();
            }
        }
    }
    // Breed all ants
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() != 'X') {
                grid[i][j]->breed();
            }
        }
    }
    // Starve all critters
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->starve();
            }
        }
    }
}

// Function to print the grid to the console
void Grid::printGrid() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                std::cout << grid[i][j]->getSymbol();
            } else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
}

// Function to check if the simulation is over
bool Grid::isSimulationOver() {
    bool antsExist = false;
    bool doodlebugsExist = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->getSymbol() == 'X') {
                    doodlebugsExist = true;
                } else {
                    antsExist = true;
                }
            }
        }
    }
    return !(antsExist && doodlebugsExist);
}

// Function to get the critter at a specific cell
Critter* Grid::getCell(int x, int y) const {
    if (isValidPosition(x, y)) {
        return grid[x][y];
    }
    return nullptr;
}

// Function to set a critter at a specific cell
void Grid::setCell(int x, int y, Critter* critter) {
    if (isValidPosition(x, y)) {
        grid[x][y] = critter;
    }
}

// Function to check if a position is valid within the grid
bool Grid::isValidPosition(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size;
}
