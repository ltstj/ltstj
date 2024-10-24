#include "organism.hpp"

Organism::Organism(int x, int y) : x(x), y(y), timeStepsSurvived(0) {}

int Organism::getX() const {
    return x;
}

int Organism::getY() const {
    return y;
}
