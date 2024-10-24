// Debug T-1
// Function template adds objects. The function works on any object which has '+' opertor defined.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;

// The issue was with the template parameter list. It should have two separate type parameters.
template <typename T, typename U>
T add(T x, U y) 
{
    T sum = static_cast<T>(x + y); // Cast y to type T before adding
    return sum;
}

class Person
{
    friend ostream &operator<<(ostream &, const Person &);
private:
    string lastName;
    string firstName;
    int age;
public:
    void setValues(string last, string first, int age)
    {
        lastName = last;
        firstName = first;
        this->age = age; // 'this' pointer to distinguish member variable
    }
    
    // Operator+ should return a new object, not modify the existing one
    Person operator+(const Person& p)
    {
        Person temp;
        temp.lastName = "age of ";
        temp.firstName = firstName + " " + p.firstName; // Concatenate first names
        temp.age = age + p.age; // Add ages
        return temp;
    }
};

ostream &operator<<(ostream &out, const Person &per)
{
    out << per.firstName << " " << per.lastName << per.age << " years old";
    return out;
}

int main()
{
    int a = 7, b = 26, c;
    double d = 39.25, e = 2.01, f;
    Person g, h, i;
    g.setValues("Mitchell", "Donald", 40);
    h.setValues("Clayton", "Rita", 35);

    c = add(a, b); // add<int, int>(a, b)
    f = add(d, e); // add<double, double>(d, e)
    i = add(g, h); // add<Person, Person>(g, h) 

    cout << c << endl; // 33
    cout << f << endl; // 41.26
    cout << i << endl; // Donald Rita age of 75 years old

    return 0;
}

//Fixes:
//issue with the template parameter list, there has to be 2 separate parameters
//Cast y to type T before adding
//'this' pointer to distinguish member variable, Using this->age 
//Concatenate first names
