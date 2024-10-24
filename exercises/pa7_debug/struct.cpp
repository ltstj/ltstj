// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same


#include <iostream>
#include <string>

using namespace std;

struct car
{
     char name[20];
     int modelYear;
     float speed;
};

int main(void)
{
     char n[20];
     int a;
     float w;

     struct car c;
     car *cPtr = &c;

     cout << "What is your favorite car's name: ";
     cin >> n;
     strcpy(c.name, n);

     cout << "When was it launched?: ";
     cin >> a;
     c.modelYear = a;

     cout << "How much speed does it give?: ";
     cin >> w;
     c.speed = w;

     cout << "Car's name is" << c.name << ", and should be the same as" << cPtr->name << ".\n";
     cout << "Car's model year is" << c.modelYear << ", and should be the same as " << cPtr->modelYear << ".\n";
     cout << "Car's speed is" << c.speed << ", and should be the same as " << cPtr->speed << ".\n";
}

//The errors that were fixed are:
//1. added "using namespace std;"
//2. changed "char *name" to "char name[20]"
//3. changed "name = n;" to "strcpy(c.name, n);"
//4. changed "cout >> a;" to "cin >> a;"
//5. changed "cin << w;" to "cin >> w;" 
//6. set c.speed to w instead of speed
//7. changed the end of the cout statement from "cPtr.name" to "cPtr->name"
//8. changed the end of the cout statement from "modelYear" to "cPtr->modelYear"
//9. changed the end of the cout statement from "w" to "cPtr->speed"