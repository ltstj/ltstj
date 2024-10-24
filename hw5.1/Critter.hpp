#ifndef CRITTER_HPP
#define CRITTER_HPP

class Grid;

class Critter {
public:
    Critter(int x, int y, Grid* grid);
    virtual ~Critter() = default;

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual void starve() = 0;

    char getSymbol() const;
    int getX() const;
    int getY() const;

    void setPosition(int x, int y);

protected:
    int x, y;
    Grid* grid;
    char symbol;
};

#endif
