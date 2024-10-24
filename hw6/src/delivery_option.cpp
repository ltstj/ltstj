#include "delivery_option.hpp"

DeliveryOption::DeliveryOption(const std::string& type, double cost) : type(type), cost(cost) {}

std::string DeliveryOption::getType() const {
    return type;
}

double DeliveryOption::getCost() const {
    return cost;
}