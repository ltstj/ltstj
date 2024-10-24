// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.
#include <iostream>
#include <string>
using namespace std;

// Corrected function name from 'findBiggest' to 'findLargest'
template <typename T>
void findLargest(T a, T b, T c)
{
    T largest = a;
    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;
    cout << "The largest of " << a << ", " << b << ", " << c << " is " << largest << endl;
}

template <typename T>
void findLargest(T a, T b)
{
    T largest = (a > b) ? a : b;
    cout << "The larger of " << a << ", " << b << " is " << largest << endl;
}

class BankAccount
{
    friend ostream &operator<<(ostream &, const BankAccount &);
private:
    string name;
    int amount;
public:
    BankAccount(const string &name, const int amount) : name(name), amount(amount) {}
    bool operator>(const BankAccount &other) const
    {
        return amount > other.amount;
    }
};

ostream &operator<<(ostream &out, const BankAccount &bh)
{
    out << "Name: " << bh.name << ", Amount: " << bh.amount;
    return out;
}

int main()
{
    BankAccount bAA("A", 800);
    BankAccount bAB("B", 120);
    BankAccount bAC("C", 500);

    findLargest(bAA, bAB); // Calls findLargest(BankAccount, BankAccount)
    findLargest(bAB, bAC); // Calls findLargest(BankAccount, BankAccount)
    findLargest(bAC, bAA); // Calls findLargest(BankAccount, BankAccount)
    findLargest(bAA, bAB, bAC); // Calls findLargest(BankAccount, BankAccount, BankAccount)

    return 0;
}

//fixes:
//In the 2 argument overload of findLargest, simplified with ? operator
//BankAccount constructor updated for member initializer list 
//operator> in BankAccount changed to const member function