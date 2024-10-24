#ifndef ANT_HPP
#define ANT_HPP

#include "organism.hpp"

class Ant : public Organism {
protected:
    int stepsSinceLastMove;

public:
    Ant(int x, int y);
    virtual void move(Grid &grid) override;
    virtual void breed(Grid &grid) override;
    virtual void starve(Grid &grid) override;
};

class QueenAnt : public Ant {
private:
    bool mated;
    int timeSinceLastBreed;
    bool hasBredNewQueen;
    int stepsSinceLastQueenBreed;

public:
    QueenAnt(int x, int y);
    virtual void move(Grid &grid) override;
    virtual void breed(Grid &grid) override;
    virtual void starve(Grid &grid) override;
};

class WorkerAnt : public Ant {
public:
    WorkerAnt(int x, int y);
};

class MaleAnt : public Ant {
public:
    MaleAnt(int x, int y);
};

class NewQueenAnt : public Ant {
public:
    NewQueenAnt(int x, int y);
};

#endif
