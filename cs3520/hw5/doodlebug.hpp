#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "organism.hpp"

class Doodlebug : public Organism {
private:
    int stepsSinceLastMeal;
    int directionIndex;

public:
    Doodlebug(int x, int y);
    virtual void move(Grid &grid) override;
    virtual void breed(Grid &grid) override;
    virtual void starve(Grid &grid) override;
};

#endif
