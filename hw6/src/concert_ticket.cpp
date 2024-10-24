#include "concert_ticket.hpp"

ConcertTicket::ConcertTicket(const std::string& artist, const std::string& venue, double price)
    : artist(artist), venue(venue), price(price) {}

std::string ConcertTicket::getArtist() const {
    return artist;
}

std::string ConcertTicket::getVenue() const {
    return venue;
}

double ConcertTicket::getPrice() const {
    return price;
}

bool ConcertTicket::operator==(const ConcertTicket& other) const {
    return artist == other.artist && venue == other.venue && price == other.price;
}

bool ConcertTicket::operator!=(const ConcertTicket& other) const {
    return !(*this == other);
}