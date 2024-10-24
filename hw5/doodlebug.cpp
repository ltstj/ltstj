#include "doodlebug.hpp"
#include "grid.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

Doodlebug::Doodlebug(int x, int y) : Organism(x, y), stepsSinceLastMeal(0), directionIndex(0) {}

void Doodlebug::move(Grid &grid) {
    int directions[8][2] = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1},
        {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };

    bool moved = false;
    for (int i = 0; i < 8; ++i) {
        int index = (directionIndex + i) % 8;
        int newX = x + directions[index][0];
        int newY = y + directions[index][1];

        if (grid.isValidPosition(newX, newY)) {
            if (grid.isAnt(newX, newY)) {
                grid.eatAnt(newX, newY);
                grid.moveOrganism(x, y, newX, newY);
                x = newX;
                y = newY;
                stepsSinceLastMeal = 0;
                directionIndex = (index + 1) % 8;
                moved = true;
                return;
            } else if (grid.isEmpty(newX, newY)) {
                grid.moveOrganism(x, y, newX, newY);
                x = newX;
                y = newY;
                directionIndex = (index + 1) % 8;
                moved = true;
                break;
            }
        }
    }

    if (!moved) {
        stepsSinceLastMeal++;
    }

    timeStepsSurvived++;
}

void Doodlebug::breed(Grid &grid) {
    if (timeStepsSurvived >= 10) {
        std::vector<std::pair<int, int>> positions;
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int newX = x + dx;
                int newY = y + dy;
                if (grid.isValidPosition(newX, newY) && grid.isEmpty(newX, newY)) {
                    positions.emplace_back(newX, newY);
                }
            }
        }

        std::shuffle(positions.begin(), positions.end(), std::default_random_engine(rand()));
        if (!positions.empty()) {
            auto pos = positions.front();
            grid.addOrganism(new Doodlebug(pos.first, pos.second));
        }

        timeStepsSurvived = 0;
    }
}

void Doodlebug::starve(Grid &grid) {
    if (stepsSinceLastMeal >= 20) {
        grid.removeOrganism(x, y);
    }
}
