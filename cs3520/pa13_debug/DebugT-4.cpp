// Debug T-5
/* Calculator class uses template class to perform arithmetic operations on different types of data.
 *  It also has function to determine which value is greater which return a boolean type.
 */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
using namespace std;

// Class to perform various operations on two variables of type T
template <typename T>
class Calculator
{
private:
    T num1, num2;
public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}
    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply(T n1, T n2) { return n1 * n2; } // Corrected to take two arguments
    T divide() { return num1 / num2; } // Corrected from modulus to division
    bool isGreater() { return num1 > num2; }
};

int main()
{
    Calculator<int> calc(10, 4); // int operations
    cout << calc.add() << endl;
    cout << calc.subtract() << endl;
    cout << calc.multiply(10, 4) << endl; // Calling with arguments
    cout << calc.divide() << endl;
    cout << boolalpha << calc.isGreater() << endl;

    Calculator<double> calc2(10.234, 4.235); // double operations
    cout << calc2.add() << endl;
    cout << calc2.subtract() << endl;
    cout << calc2.multiply(10.234, 4.235) << endl; // Calling with arguments
    cout << calc2.divide() << endl;
    cout << boolalpha << calc2.isGreater() << endl;

    Calculator<string> calc3("Hello", "World"); // string operations
    cout << calc3.add() << endl;
    cout << boolalpha << calc3.isGreater() << endl; // Comparing strings

    return 0;
}

//fixes:
//multiply function corrected to take 2 arguments instead of class members
//divide function corrected to do division instead of modulus
//member functions called with appropriate arguments

