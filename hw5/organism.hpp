#ifndef ORGANISM_HPP
#define ORGANISM_HPP

class Grid;

class Organism {
protected:
    int x, y;
    int timeStepsSurvived;

public:
    Organism(int x, int y);
    virtual ~Organism() = default;

    virtual void move(Grid &grid) = 0;
    virtual void breed(Grid &grid) = 0;
    virtual void starve(Grid &grid) = 0;

    int getX() const;
    int getY() const;
};

#endif
