#include "Critter.hpp"
#include "Grid.hpp"

Critter::Critter(int x, int y, Grid* grid) : x(x), y(y), grid(grid), symbol(' ') {}

char Critter::getSymbol() const {
    return symbol;
}

int Critter::getX() const {
    return x;
}

int Critter::getY() const {
    return y;
}

void Critter::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
