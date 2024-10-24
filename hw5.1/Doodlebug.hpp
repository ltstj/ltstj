#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter {
public:
    Doodlebug(int x, int y, Grid* grid);
    virtual void move() override;
    virtual void breed() override;
    virtual void starve() override;

private:
    int timeSinceLastMeal;
    int timeSinceLastBreed;
};

#endif
