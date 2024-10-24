#ifndef FAVORITELIST_HPP
#define FAVORITELIST_HPP

#include <vector>
#include "vehicle.hpp"

class FavoriteList {
public:
    void addVehicle(const Vehicle& vehicle);
    std::vector<Vehicle> getVehicles() const;

private:
    std::vector<Vehicle> vehicles;
};

#endif 