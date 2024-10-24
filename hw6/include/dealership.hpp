#ifndef DEALERSHIP_HPP
#define DEALERSHIP_HPP

#include <string>
#include <vector>
#include "vehicle.hpp"

class Dealership {
public:
    Dealership(const std::string& name, const std::string& location);
    void addVehicle(const Vehicle& vehicle);
    std::vector<Vehicle> getInventory() const;

private:
    std::string name;
    std::string location;
    std::vector<Vehicle> inventory;
};

#endif