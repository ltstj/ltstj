#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>
#include "vehicle.hpp"

class Customer {
public:
    Customer(const std::string& name, const std::string& dob, int id);
    void addFavoriteVehicle(const Vehicle& vehicle);
    std::vector<Vehicle> getFavoriteVehicles() const;
    std::string getName() const; 

private:
    std::string name;
    std::string dob;
    int id;
    std::vector<Vehicle> favoriteVehicles;
};

#endif 