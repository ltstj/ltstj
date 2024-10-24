// Program to check if the user-provided number is a palindrome

// TODO: Fix the bugs and make sure the program runs as expected.
// Provide a brief comment identifying each bug fixed.

#include <iostream>
using namespace std;

bool func(int n);

int main()
{
        int input;
        cout << "enter an integer please: ";
        cin >> input;
        bool returned_val = func(input);
        if (returned_val)
        {
                cout << "It is a palindrome" << endl;
        }
        else
        {
                cout << "It is not a palindrome" << endl;
        }

        return 0;
}

// the return value of your func should be true / false only
bool func(int n)
{
        int given_number = n;
        int temp = 0;
        int remainder;
        while (n != 0)
        {
                remainder = n % 10;
                temp = temp * 10 + remainder;
                n = n/10;
        }

        if (given_number == temp)
        {
                return true;
        }
        else
        {
                return false;
        }
}

//The errors that were fixed are:
//1. added "using namespace std"
//2. changed "void func(int)" to "bool func(int n)"
//3. changed main() to an int instead of void
//3. changed "char input = 1001" to "int input"
//4. added "cin >> input" 
//5. declared "returned_val" a boolean
//6. changed the print statement from "It is not a palindrome" to "It is a palindrome"
//7. changed the other print statement from "It is a palindrome" to "It is not a palindrome"
//8. changed the "void func(int n, double result)" to "bool func(int n)"
//9. changed "float given_number int temp = 0;" to "int given_number = 0" and added another line for temp
//10. added a variable "int remainder"
//11. changed "n / 10" to "n % 10"
//12. switched the order of the next 2 lines and set temp to "temp * 10 + remainder"
//13. changed "(n == temp)" to "(given_number == temp)"
//14. switched the return true and return false for accurate results