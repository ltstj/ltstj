#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter {
public:
    Ant(int x, int y, Grid* grid, char symbol = 'w');
    virtual void move() override;
    virtual void breed() override;
    virtual void starve() override;

private:
    int timeSinceLastMove;
    int timeSinceLastBreed;
};

class QueenAnt : public Ant {
public:
    QueenAnt(int x, int y, Grid* grid);
    virtual void move() override;
    virtual void breed() override;
    virtual void starve() override;

private:
    bool hasMated;
    int breedingTime;
    int newAntsCreated;
};

#endif
