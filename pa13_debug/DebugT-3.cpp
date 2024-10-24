// Debug T-3

// A container class for displaying a comma-separated list.

// Check for possible compiler errors, logical errors and rectify them

// Re-factor the code by adding few comments (make it readable) and

// provide list of most important fixes (in comments)

#include <iostream>
#include <string>

using namespace std;

// Template class for a comma-separated list
template <typename T>
class CommaSeparatedList {
private:
    T *data;
    int size;

public:
    // Constructor to initialize the list with data and size
    CommaSeparatedList(T *d, int s) : data(d), size(s) {}

    // Function to print the list
    void printList() {
        cout << "Comma separated list:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i != size - 1) {
                cout << ", ";
            }
        }
        cout << endl << endl;
    }
};

// Class to represent a Book
class Book {
    friend ostream &operator<<(ostream &, const Book &);

private:
    string title;
    int year;

public:
    // Function to set book details
    void setBook(string Title, int yr) {
        title = Title;
        year = yr;
    }
};

// Overloaded operator to print book details
ostream &operator<<(ostream &out, const Book &b) {
    out << b.title << " was published in " << b.year;
    return out;
}

// Class to represent a Customer
class Customer {
    friend ostream &operator<<(ostream &, const Customer &);

private:
    string name;
    double balDue;

public:
    // Function to set customer details
    void setCustomer(string CustomerName, double bal) {
        name = CustomerName;
        balDue = bal;
    }
};

// Overloaded operator to print customer details
ostream &operator<<(ostream &out, const Customer &aCustomer) {
    out << aCustomer.name << " owes $" << aCustomer.balDue;
    return out;
}

int main() {
    // Declare and assign values to four kinds of CommaSeparatedLists
    int someInts[] = {12, 34, 55, 77, 99};
    double someDoubles[] = {11.11, 23.44, 44.55, 123.66};
    Book someBooks[2];
    someBooks[0].setBook("Wizard of Oz", 1986);
    someBooks[1].setBook("Harry Potter", 2000);
    Customer someCustomers[6];
    someCustomers[0].setCustomer("Zaps", 23.55);
    someCustomers[1].setCustomer("Martin", 155.77);
    someCustomers[2].setCustomer("Fine", 333.88);
    someCustomers[3].setCustomer("Torrence", 123.99);
    someCustomers[4].setCustomer("Richard", 20.06);
    someCustomers[5].setCustomer("Curtin", 56999.19);

    // Calculate size and create CommaSeparatedList objects
    int commaSeparatedListSize = sizeof(someInts) / sizeof(someInts[0]);
    CommaSeparatedList<int> commaSeparatedListOfIntegers(someInts, commaSeparatedListSize);

    commaSeparatedListSize = sizeof(someDoubles) / sizeof(someDoubles[0]);
    CommaSeparatedList<double> commaSeparatedListOfDoubles(someDoubles, commaSeparatedListSize);

    commaSeparatedListSize = sizeof(someBooks) / sizeof(someBooks[0]);
    CommaSeparatedList<Book> commaSeparatedListOfBooks(someBooks, commaSeparatedListSize);

    commaSeparatedListSize = sizeof(someCustomers) / sizeof(someCustomers[0]);
    CommaSeparatedList<Customer> commaSeparatedListOfCustomers(someCustomers, commaSeparatedListSize);

    // Use printList() with each CommaSeparatedList
    commaSeparatedListOfIntegers.printList();
    commaSeparatedListOfDoubles.printList();
    commaSeparatedListOfBooks.printList();
    commaSeparatedListOfCustomers.printList();

    return 0;
}

// Fixes:
//Corrected the template class definition to include the typename keyword.
//Added missing braces in the printList() function.
//fixed the logic for creating CommaSeparatedList objects.
//sizeof operator used correctly to calculate the size of the arrays.
//sizeif typo corrected to sizeof
//prinList typo correct to printList