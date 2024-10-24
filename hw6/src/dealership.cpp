#include "dealership.hpp"

Dealership::Dealership(const std::string& name, const std::string& location) : name(name), location(location) {}

void Dealership::addVehicle(const Vehicle& vehicle) {
    inventory.push_back(vehicle);
}

std::vector<Vehicle> Dealership::getInventory() const {
    return inventory;
}