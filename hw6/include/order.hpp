#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include "vehicle.hpp"
#include "customer.hpp"
#include "delivery_option.hpp"

class Order {
public:
    Order(const Vehicle& vehicle, const Customer& customer, const DeliveryOption& deliveryOption);
    std::string getOrderDetails() const;

private:
    Vehicle vehicle;
    Customer customer;
    DeliveryOption deliveryOption;
};

#endif