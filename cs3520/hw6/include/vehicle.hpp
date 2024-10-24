#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& model, double price);
    std::string getModel() const;
    double getPrice() const;

    bool operator==(const Vehicle& other) const;

private:
    std::string model;
    double price;
};

#endif 