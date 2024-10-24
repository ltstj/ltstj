#include "vehicle.hpp"

Vehicle::Vehicle(const std::string& model, double price) : model(model), price(price) {}

std::string Vehicle::getModel() const {
    return model;
}

double Vehicle::getPrice() const {
    return price;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return model == other.model && price == other.price;
}