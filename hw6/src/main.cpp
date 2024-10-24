#include <iostream>
#include "vehicle.hpp"
#include "customer.hpp"
#include "dealership.hpp"
#include "order.hpp"
#include "delivery_option.hpp"
#include "account.hpp"
#include "favorite_list.hpp"
#include "reservation_system.hpp"
#include "book.hpp"
#include "concert_ticket.hpp"

int main() {
    // Example of Vehicle Ordering System
    Vehicle car("Tesla Model S", 79999.99);
    Customer customer("Bob Doe", "1990-01-01", 1);
    Dealership dealership("Tesla Store", "New York");
    DeliveryOption delivery("Home Delivery", 500.00);
    Order order(car, customer, delivery);

    std::cout << order.getOrderDetails() << std::endl;

    // Examples
    // int
    ReservationSystem<int> intReservations;
    intReservations.reserve(42, "Integer Reservation", 0.0, "John Doe", "1990-01-01", "ID1");
    intReservations.reserve(7, "Another Integer Reservation", 0.0, "Jane Doe", "1992-02-02", "ID2");
    std::cout << "Number of int reservations: " << intReservations.getNumberOfReservations() << std::endl;

    // std::string
    ReservationSystem<std::string> stringReservations;
    stringReservations.reserve("Concert A", "Concert Reservation", 50.0, "Alice", "1985-05-05", "ID3");
    stringReservations.reserve("Concert B", "Another Concert Reservation", 75.0, "Bob", "1987-07-07", "ID4");
    std::cout << "Number of string reservations: " << stringReservations.getNumberOfReservations() << std::endl;

    // Book
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
    Book book2("1984", "George Orwell", 8.99);
    ReservationSystem<Book> bookReservations;
    bookReservations.reserve(book1, "Book Reservation", 10.99, "Charlie", "1995-03-03", "ID5");
    bookReservations.reserve(book2, "Another Book Reservation", 8.99, "Dave", "1996-04-04", "ID6");
    std::cout << "Number of book reservations: " << bookReservations.getNumberOfReservations() << std::endl;

    // ConcertTicket
    ConcertTicket ticket1("Artist A", "Venue A", 50.00);
    ConcertTicket ticket2("Artist B", "Venue B", 75.00);
    ReservationSystem<ConcertTicket> ticketReservations;
    ticketReservations.reserve(ticket1, "Concert Ticket Reservation", 50.00, "Eve", "1980-08-08", "ID7");
    ticketReservations.reserve(ticket2, "Another Concert Ticket Reservation", 75.00, "Frank", "1982-09-09", "ID8");
    std::cout << "Number of concert ticket reservations: " << ticketReservations.getNumberOfReservations() << std::endl;

    // addItems function
    std::vector<ReservationSystem<int>::Reservation> intItems = {
        {42, "Updated Integer Reservation", 0.0, "John Doe", "1990-01-01", "ID1"},
        {99, "New Integer Reservation", 0.0, "Jane Smith", "1993-03-03", "ID9"}
    };
    intReservations.addItems(intItems);
    std::cout << "Number of int reservations after adding an item: " << intReservations.getNumberOfReservations() << std::endl;

    return 0;
}
