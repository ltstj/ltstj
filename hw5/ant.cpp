#include "ant.hpp"
#include "grid.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

Ant::Ant(int x, int y) : Organism(x, y), stepsSinceLastMove(0) {}

void Ant::move(Grid &grid) {
    int directions[8][2] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}, 
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };
    std::shuffle(std::begin(directions), std::end(directions), std::default_random_engine(rand()));

    bool moved = false;
    for (auto &dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (grid.isValidPosition(newX, newY)) {
            if (grid.isEmpty(newX, newY)) {
                grid.moveOrganism(x, y, newX, newY);
                x = newX;
                y = newY;
                moved = true;
                break;
            } else if (grid.isWall(newX, newY)) {
                int bounceX = x - dir[0];
                int bounceY = y - dir[1];
                if (grid.isValidPosition(bounceX, bounceY) && grid.isEmpty(bounceX, bounceY)) {
                    grid.moveOrganism(x, y, bounceX, bounceY);
                    x = bounceX;
                    y = bounceY;
                    moved = true;
                    break;
                }
            }
        }
    }

    if (moved) {
        stepsSinceLastMove = 0;
    } else {
        stepsSinceLastMove++;
    }

    timeStepsSurvived++;
}

void Ant::breed(Grid &grid) {
    // Implement breeding logic for Worker and Male ants if needed
}

void Ant::starve(Grid &grid) {
    if (stepsSinceLastMove >= 5) {
        grid.removeOrganism(x, y);
    }
}

QueenAnt::QueenAnt(int x, int y) : Ant(x, y), mated(false), timeSinceLastBreed(0), hasBredNewQueen(false), stepsSinceLastQueenBreed(0) {}

void QueenAnt::move(Grid &grid) {
    if (!mated) {
        return;
    }

    Ant::move(grid);
    timeSinceLastBreed++;
    if (hasBredNewQueen) {
        stepsSinceLastQueenBreed++;
    }
}

void QueenAnt::breed(Grid &grid) {
    if (timeSinceLastBreed >= 30 && mated) {
        if (hasBredNewQueen && stepsSinceLastQueenBreed < 30) {
            return;
        }

        std::vector<std::pair<int, int>> positions;
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {  // Corrected to ensure loop closure
                int newX = x + dx;
                int newY = y + dy;
                if (grid.isValidPosition(newX, newY) && grid.isEmpty(newX, newY)) {
                    positions.emplace_back(newX, newY);
                }
            }
        }

        std::shuffle(positions.begin(), positions.end(), std::default_random_engine(rand()));
        int count = 0;
        for (auto &pos : positions) {
            if (count >= 10) break;
            double randVal = static_cast<double>(rand()) / RAND_MAX;
            if (randVal < 0.0005) {
                grid.addOrganism(new NewQueenAnt(pos.first, pos.second)); // Less than 0.05% for new queens
                hasBredNewQueen = true;
                stepsSinceLastQueenBreed = 0;
            } else if (randVal < 0.01) {
                grid.addOrganism(new NewQueenAnt(pos.first, pos.second)); // Less than 1% for new queens
                hasBredNewQueen = true;
                stepsSinceLastQueenBreed = 0;
            } else if (randVal < 0.4) {
                grid.addOrganism(new MaleAnt(pos.first, pos.second)); // 20-40% for male ants
            } else {
                grid.addOrganism(new WorkerAnt(pos.first, pos.second)); // 60-80% for worker ants
            }
            count++;
        }

        mated = false;
        timeSinceLastBreed = 0;
    }
}

void QueenAnt::starve(Grid &grid) {
    if (timeSinceLastBreed >= 90) {
        grid.removeOrganism(x, y);
    }
}

WorkerAnt::WorkerAnt(int x, int y) : Ant(x, y) {}
MaleAnt::MaleAnt(int x, int y) : Ant(x, y) {}
NewQueenAnt::NewQueenAnt(int x, int y) : Ant(x, y) {}
