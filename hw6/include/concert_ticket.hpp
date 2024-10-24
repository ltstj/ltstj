#ifndef CONCERTTICKET_HPP
#define CONCERTTICKET_HPP

#include <string>

class ConcertTicket {
public:
    ConcertTicket(const std::string& artist, const std::string& venue, double price);
    std::string getArtist() const;
    std::string getVenue() const;
    double getPrice() const;

    bool operator==(const ConcertTicket& other) const;
    bool operator!=(const ConcertTicket& other) const;

private:
    std::string artist;
    std::string venue;
    double price;
};

#endif 