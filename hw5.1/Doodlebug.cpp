#include <cstdlib>
#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "HelperFunctions.hpp"

Doodlebug::Doodlebug(int x, int y, Grid* grid) : Critter(x, y, grid), timeSinceLastMeal(0), timeSinceLastBreed(0) {
    this->symbol = 'X';
}

void Doodlebug::move() {
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    bool moved = false;

    // First check for adjacent ants to eat
    for (int i = 0; i < 8; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) != nullptr && grid->getCell(newX, newY)->getSymbol() != 'X') {
            delete grid->getCell(newX, newY); // Eat the ant
            grid->setCell(newX, newY, this);
            grid->setCell(x, y, nullptr);
            x = newX;
            y = newY;
            timeSinceLastMeal = 0;
            moved = true;
            break;
        }
    }

    // If no adjacent ant, move to a random direction
    if (!moved) {
        int direction = randomDirection();
        int newX = x + directions[direction][0];
        int newY = y + directions[direction][1];

        if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) == nullptr) {
            grid->setCell(newX, newY, this);
            grid->setCell(x, y, nullptr);
            x = newX;
            y = newY;
        }
        ++timeSinceLastMeal;
    }
}

void Doodlebug::breed() {
    if (timeSinceLastBreed >= 10) {
        int directions[16][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
            {-1, -1}, {1, -1}, {-1, 1}, {1, 1}, 
            {-2, 0}, {2, 0}, {0, -2}, {0, 2}, 
            {-2, -2}, {2, -2}, {-2, 2}, {2, 2}
        };
        for (int i = 0; i < 16; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (grid->isValidPosition(newX, newY) && grid->getCell(newX, newY) == nullptr) {
                grid->setCell(newX, newY, new Doodlebug(newX, newY, grid)); // Create new Doodlebug
                timeSinceLastBreed = 0; // Reset breeding counter
                return;
            }
        }
    } else {
        ++timeSinceLastBreed;
    }
}

void Doodlebug::starve() {
    if (timeSinceLastMeal >= 20) {
        grid->setCell(x, y, nullptr); // Remove Doodlebug from grid
        delete this;
    }
}
