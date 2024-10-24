#include "book.hpp"

Book::Book(const std::string& title, const std::string& author, double price)
    : title(title), author(author), price(price) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

double Book::getPrice() const {
    return price;
}

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && price == other.price;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}
