#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, double price);
    std::string getTitle() const;
    std::string getAuthor() const;
    double getPrice() const;

    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;

private:
    std::string title;
    std::string author;
    double price;
};

#endif 
