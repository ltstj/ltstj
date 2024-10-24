#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>
#include <unordered_set>
#include "organism.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

class Grid {
private:
    std::vector<std::vector<Organism*>> cells;

public:
    Grid(int width, int height);
    ~Grid();

    bool isValidPosition(int x, int y) const;
    bool isEmpty(int x, int y) const;
    bool isWall(int x, int y) const;
    bool isAnt(int x, int y) const;

    void moveOrganism(int fromX, int fromY, int toX, int toY);
    void eatAnt(int x, int y);
    void removeOrganism(int x, int y);
    void addOrganism(Organism* organism);
    Organism* getOrganism(int x, int y) const;
    void printGrid() const;

    std::string getState() const; // New method to get the state of the grid
};

#endif
