#ifndef DELIVERYOPTION_HPP
#define DELIVERYOPTION_HPP

#include <string>

class DeliveryOption {
public:
    DeliveryOption(const std::string& type, double cost);
    std::string getType() const;
    double getCost() const;

private:
    std::string type;
    double cost;
};

#endif // DELIVERYOPTION_HPP