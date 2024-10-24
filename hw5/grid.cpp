#include "grid.hpp"
#include <iostream>
#include <sstream>

Grid::Grid(int width, int height) : cells(width, std::vector<Organism*>(height, nullptr)) {}

Grid::~Grid() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            delete cell;
        }
    }
}

bool Grid::isValidPosition(int x, int y) const {
    return x >= 0 && x < cells.size() && y >= 0 && y < cells[0].size();
}

bool Grid::isEmpty(int x, int y) const {
    return cells[x][y] == nullptr;
}

bool Grid::isWall(int x, int y) const {
    return x == 0 || x == cells.size() - 1 || y == 0 || y == cells[0].size() - 1;
}

bool Grid::isAnt(int x, int y) const {
    return dynamic_cast<Ant*>(cells[x][y]) != nullptr;
}

void Grid::moveOrganism(int fromX, int fromY, int toX, int toY) {
    if (isValidPosition(toX, toY)) {
        cells[toX][toY] = cells[fromX][fromY];
        cells[fromX][fromY] = nullptr;
    }
}

void Grid::eatAnt(int x, int y) {
    delete cells[x][y];
    cells[x][y] = nullptr;
}

void Grid::removeOrganism(int x, int y) {
    delete cells[x][y];
    cells[x][y] = nullptr;
}

void Grid::addOrganism(Organism* organism) {
    int x = organism->getX();
    int y = organism->getY();
    if (isValidPosition(x, y) && isEmpty(x, y)) {
        cells[x][y] = organism;
    }
}

Organism* Grid::getOrganism(int x, int y) const {
    if (isValidPosition(x, y)) {
        return cells[x][y];
    }
    return nullptr;
}

void Grid::printGrid() const {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            if (dynamic_cast<const QueenAnt*>(cell)) {
                std::cout << "Q";
            } else if (dynamic_cast<const WorkerAnt*>(cell)) {
                std::cout << "w";
            } else if (dynamic_cast<const MaleAnt*>(cell)) {
                std::cout << "o";
            } else if (dynamic_cast<const Doodlebug*>(cell)) {
                std::cout << "X";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

std::string Grid::getState() const {
    std::stringstream ss;
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            if (dynamic_cast<const QueenAnt*>(cell)) {
                ss << "Q";
            } else if (dynamic_cast<const WorkerAnt*>(cell)) {
                ss << "w";
            } else if (dynamic_cast<const MaleAnt*>(cell)) {
                ss << "o";
            } else if (dynamic_cast<const Doodlebug*>(cell)) {
                ss << "X";
            } else {
                ss << ".";
            }
        }
    }
    return ss.str();
}
