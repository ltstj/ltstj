// Debug T-5
// The goal of this debug exercise is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)
// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

#include <iostream>
#include <string>

using namespace std;

// Base class
class car {
protected: // Changed from private to protected
    string name;
    int modelYear;

protected:
    // Protected method to assign values from another car object
    void assign(const car &c) {
        name = c.name;
        modelYear = c.modelYear;
    }

public:
    // Constructor
    car(const string &n, const int my) : name(n), modelYear(my) {}

    // Virtual print method to be overridden by derived classes
    virtual void print() const {
        cout << "Name: " << name << " model Year: " << modelYear << endl;
    }

    // Virtual assignment operator to be overridden by derived classes
    virtual const car &operator=(const car &c) {
        if (this != &c) {
            name = c.name;
            modelYear = c.modelYear;
        }
        return *this;
    }
};

// Derived class sedan
class sedan : public car {
private:
    int mileage;

public:
    // Constructor
    sedan(const string &n, const int my, const int m) : car(n, my), mileage(m) {}

    // Overridden print method
    virtual void print() const override {
        cout << "Name: " << name << " model Year: " << modelYear << " Mileage: " << mileage << endl;
    }
};

// Derived class suv
class suv : public car {
private:
    int miles;

protected:
    // Protected method to assign values from another suv object
    void assign(const suv &c) {
        car::assign(c);
        miles = c.miles;
    }

public:
    // Constructor
    suv(const string &n, const int my, const int m) : car(n, my), miles(m) {}

    // Overridden print method
    virtual void print() const override {
        cout << "Name: " << name << " model Year: " << modelYear << " Miles driven: " << miles << endl;
    }

    // Overridden assignment operator
    virtual const suv &operator=(const car &c) override {
        if (const suv *b = dynamic_cast<const suv*>(&c)) {
            assign(*b);
        }
        return *this;
    }
};

// Function to print car information, passed by reference to avoid slicing
void printCarInfo(const car &c) {
    c.print();
}

int main() {
    car tesla("tesla", 2019);
    sedan hyundai("Hyundai", 2020, 23);
    suv ford("Ford", 2012, 20000);

    printCarInfo(tesla);
    printCarInfo(hyundai);
    printCarInfo(ford);

    suv ford2("Ford", 2017, 10000);
    ford = ford2; // Use assignment operator
    printCarInfo(ford);

    return 0;
}

//fixes:
//Change private to protected so derived classes can access members
//Initialized name and modelYear in suv constructor
//Changed the parameter to a reference in "printCarInfo"
//it assigned objects directly to a reference of type car in main, so changed to use the derived type directly.
//Changed the parameter to a reference in "suv"