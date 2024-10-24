#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include "customer.hpp"

class Account {
public:
    Account(const std::string& username, const std::string& password, const Customer& customer);
    bool login(const std::string& username, const std::string& password) const;

private:
    std::string username;
    std::string password;
    Customer customer;
};

#endif 