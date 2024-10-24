#include "customer.hpp"

Customer::Customer(const std::string& name, const std::string& dob, int id) : name(name), dob(dob), id(id) {}

void Customer::addFavoriteVehicle(const Vehicle& vehicle) {
    favoriteVehicles.push_back(vehicle);
}

std::vector<Vehicle> Customer::getFavoriteVehicles() const {
    return favoriteVehicles;
}

std::string Customer::getName() const {
    return name;
}