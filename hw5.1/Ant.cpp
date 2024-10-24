#include <cstdlib>
#include "Ant.hpp"
#include "Grid.hpp"
#include "HelperFunctions.hpp"

// Other functions remain unchanged

Ant::Ant(int x, int y, Grid* grid, char symbol) : Critter(x, y, grid) {
    this->symbol = symbol;
    this->timeSinceLastMove = 0;
    this->timeSinceLastBreed = 0;
}

void Ant::move() {
    // Directions: 0=up, 1=down, 2=left, 3=right, 4=up-left, 5=up-right, 6=down-left, 7=down-right
    int direction = randomDirection();
    int newX = x;
    int newY = y;

    switch (direction) {
        case 0: newY = y - 1; break; // up
        case 1: newY = y + 1; break; // down
        case 2: newX = x - 1; break; // left
        case 3: newX = x + 1; break; // right
        case 4: newX = x - 1; newY = y - 1; break; // up-left
        case 5: newX = x + 1; newY = y - 1; break; // up-right
        case 6: newX = x - 1; newY = y + 1; break; // down-left
        case 7: newX = x + 1; newY = y + 1; break; // down-right
    }

    
    if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) == nullptr) {
        grid->setCell(x, y, nullptr);  // Clear current position
        x = newX;
        y = newY;
        grid->setCell(x, y, this);     // Move to new position
        timeSinceLastMove = 0;         // Reset starving counter
    } else {
        ++timeSinceLastMove;           // Increment starving counter if move was not successful
    }
}

void Ant::breed() {
    // Breeding logic: If the ant survives for 30 time-steps, it will try to breed
    if (timeSinceLastBreed >= 3) {
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        for (int i = 0; i < 8; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) == nullptr) {
                grid->setCell(newX, newY, new Ant(newX, newY, grid, 'o')); // Create new ant
                timeSinceLastBreed = 0; // Reset breed counter
                return;
            }
        }
    } else {
        ++timeSinceLastBreed;
    }
}

void Ant::starve() {
    if (timeSinceLastMove >= 5) {
        grid->setCell(x, y, nullptr); // Remove ant from grid
        delete this;
    }
}

QueenAnt::QueenAnt(int x, int y, Grid* grid) : Ant(x, y, grid, 'Q'), breedingTime(0), newAntsCreated(0) {
    this->hasMated = false;
}

void QueenAnt::move() {
    if (hasMated) {
        Ant::move(); // Queen ant moves like any other ant after mating
    }
    // Queens don't move until they have mated and produced offspring
}

void QueenAnt::breed() {
    if (!hasMated) {
        // Check for adjacent male ants
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        for (int i = 0; i < 8; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            Critter* critter = grid->getCell(newX, newY);
            if (critter != nullptr && critter->getSymbol() == 'o') {
                hasMated = true;
                return;
            }
        }
    } else {
        // Queen ant breeds after 30 time-steps
        if (breedingTime >= 30) {
            // Create 10 new ants in the surrounding 16-neighborhood
            int directions[16][2] = {
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                {-1, -1}, {1, -1}, {-1, 1}, {1, 1}, 
                {-2, 0}, {2, 0}, {0, -2}, {0, 2}, 
                {-2, -2}, {2, -2}, {-2, 2}, {2, 2}
            };
            for (int i = 0; i < 16 && newAntsCreated < 10; ++i) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) == nullptr) {
                    grid->setCell(newX, newY, new Ant(newX, newY, grid, 'w')); // Create worker ant
                    ++newAntsCreated;
                }
            }
            breedingTime = 0; // Reset breeding counter
            newAntsCreated = 0;
        } else {
            ++breedingTime;
        }
    }
}

void QueenAnt::starve() {
    // Queen ants don't starve
}
