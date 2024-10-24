#include "order.hpp"

Order::Order(const Vehicle& vehicle, const Customer& customer, const DeliveryOption& deliveryOption)
    : vehicle(vehicle), customer(customer), deliveryOption(deliveryOption) {}

std::string Order::getOrderDetails() const {
    return "Order Details: \nVehicle: " + vehicle.getModel() + "\nCustomer: " + customer.getName() + "\nDelivery Option: " + deliveryOption.getType();
}