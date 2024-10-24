#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>

template <typename T>
class ReservationSystem {
public:
    struct Reservation {
        T item;
        std::string name;
        double price;
        std::string reserver;
        std::string dob;
        std::string id;
        std::time_t timestamp;

        bool operator==(const Reservation& other) const {
            return id == other.id;
        }
    };

    void reserve(const T& item, const std::string& name, double price, const std::string& reserver, const std::string& dob, const std::string& id);
    void addItems(const std::vector<Reservation>& items);
    int getReservationDuration(const std::string& id) const;
    void removeReservation(const std::string& id);
    int getNumberOfReservations() const;

    friend std::ostream& operator<<(std::ostream& os, const ReservationSystem<T>& rs) {
        for (const auto& reservation : rs.reservations) {
            os << "Item: " << reservation.name << ", Price: " << reservation.price << ", Reserver: " << reservation.reserver << ", DOB: " << reservation.dob << ", ID: " << reservation.id << ", Timestamp: " << std::ctime(&reservation.timestamp);
        }
        return os;
    }

private:
    std::vector<Reservation> reservations;
};

template <typename T>
void ReservationSystem<T>::reserve(const T& item, const std::string& name, double price, const std::string& reserver, const std::string& dob, const std::string& id) {
    auto it = std::find_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
        return r.id == id;
    });

    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    if (it != reservations.end()) {
        it->item = item;
        it->name = name;
        it->price = price;
        it->reserver = reserver;
        it->dob = dob;
        it->timestamp = now;
    } else {
        reservations.push_back({item, name, price, reserver, dob, id, now});
    }
}

template <typename T>
void ReservationSystem<T>::addItems(const std::vector<Reservation>& items) {
    for (const auto& item : items) {
        reserve(item.item, item.name, item.price, item.reserver, item.dob, item.id);
    }
}

template <typename T>
int ReservationSystem<T>::getReservationDuration(const std::string& id) const {
    auto it = std::find_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
        return r.id == id;
    });

    if (it != reservations.end()) {
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        return static_cast<int>(std::difftime(now, it->timestamp));
    }
    return -1;
}

template <typename T>
void ReservationSystem<T>::removeReservation(const std::string& id) {
    reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
        return r.id == id;
    }), reservations.end());
}

template <typename T>
int ReservationSystem<T>::getNumberOfReservations() const {
    return reservations.size();
}

#endif
