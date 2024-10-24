#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <unordered_set>
#include "grid.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

void populateGrid(Grid &grid, int numQueens, int numWorkers, int numMales, int numDoodlebugs) {
    for (int i = 0; i < numQueens; ++i) {
        int x = rand() % 100;
        int y = rand() % 100;
        grid.addOrganism(new QueenAnt(x, y));
    }

    for (int i = 0; i < numWorkers; ++i) {
        int x = rand() % 100;
        int y = rand() % 100;
        grid.addOrganism(new WorkerAnt(x, y));
    }

    for (int i = 0; i < numMales; ++i) {
        int x = rand() % 100;
        int y = rand() % 100;
        grid.addOrganism(new MaleAnt(x, y));
    }

    for (int i = 0; i < numDoodlebugs; ++i) {
        int x = rand() % 100;
        int y = rand() % 100;
        grid.addOrganism(new Doodlebug(x, y));
    }
}

int main() {
    srand(time(0));

    int numQueens, numWorkers, numMales, numDoodlebugs;
    std::string input;

    // Prompt for number of doodlebugs
    std::cout << "Enter the number of doodlebugs (default 15): ";
    std::getline(std::cin, input);
    numDoodlebugs = input.empty() ? 15 : std::stoi(input);

    // Prompt for number of queen ants
    std::cout << "Enter the number of queen ants (default 2): ";
    std::getline(std::cin, input);
    numQueens = input.empty() ? 2 : std::stoi(input);

    // Prompt for number of worker ants (female ants)
    std::cout << "Enter the number of worker ants (default 25): ";
    std::getline(std::cin, input);
    numWorkers = input.empty() ? 25 : std::stoi(input);

    // Prompt for number of male ants
    std::cout << "Enter the number of male ants (default 25): ";
    std::getline(std::cin, input);
    numMales = input.empty() ? 25 : std::stoi(input);

    Grid grid(100, 100);

    populateGrid(grid, numQueens, numWorkers, numMales, numDoodlebugs);

    std::unordered_set<std::string> previousStates;
    int timeStep = 0;

    while (true) {
        timeStep++;
        std::cout << "Time Step: " << timeStep << std::endl;

        int antCount = 0;
        int doodlebugCount = 0;

        // Count existing ants and doodlebugs
        for (int x = 0; x < 100; ++x) {
            for (int y = 0; y < 100; ++y) {
                if (dynamic_cast<Ant*>(grid.getOrganism(x, y))) {
                    antCount++;
                } else if (dynamic_cast<Doodlebug*>(grid.getOrganism(x, y))) {
                    doodlebugCount++;
                }
            }
        }

        // Move doodlebugs
        for (int x = 0; x < 100; ++x) {
            for (int y = 0; y < 100; ++y) {
                if (Doodlebug* d = dynamic_cast<Doodlebug*>(grid.getOrganism(x, y))) {
                    d->move(grid);
                }
            }
        }

        // Move ants
        for (int x = 0; x < 100; ++x) {
            for (int y = 0; y < 100; ++y) {
                if (Ant* a = dynamic_cast<Ant*>(grid.getOrganism(x, y))) {
                    a->move(grid);
                }
            }
        }

        // Handle breeding and starvation
        for (int x = 0; x < 100; ++x) {
            for (int y = 0; y < 100; ++y) {
                if (Organism* o = grid.getOrganism(x, y)) {
                    o->breed(grid);
                    o->starve(grid);
                }
            }
        }

        std::cout << "Ants: " << antCount << ", Doodlebugs: " << doodlebugCount << std::endl;

        grid.printGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Check for termination conditions
        if (antCount == 0 || doodlebugCount == 0) {
            std::cout << "Simulation ended: one species is eliminated." << std::endl;
            break;
        }

        // Check for cyclic pattern
        std::string currentState = grid.getState();
        if (previousStates.find(currentState) != previousStates.end()) {
            std::cout << "Simulation ended: cyclic pattern detected." << std::endl;
            break;
        }
        previousStates.insert(currentState);
    }

    return 0;
}
