// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits


Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments) at the end of file.

#include<iostream>
using namespace std;

int main() {
   char digit1, digit2, digit3, digit4; //variables for digits
   string areaCode, exchange; //variables for area code and exchange
   
   cout << "Hello, I am a telemarketing calling making program.\n";
   cout << "Enter a three-digit area code: "; 
   cin >> areaCode; //area code input
   cout << "Enter a three-digit exchange to call: "; 
   cin >> exchange; //exchange input
   cout << "I am calling to tell you to buy a subscription to Dogs Monthly!\n";
   
   // Loop through every combination of digits
   for (digit1 = '0'; digit1 <= '9'; ++digit1) { 
        for (digit2 = '0'; digit2 <= '9'; ++digit2) { 
            for (digit3 = '0'; digit3 <= '9'; ++digit3) { 
                for (digit4 = '0'; digit4 <= '9'; ++digit4) {
                    //prints the number
                    cout << areaCode << "-" << exchange << "-" << digit1 << digit2 << digit3 << digit4 << endl;
                }
            }
        }
    }
    
   cout << "\nCalls completed" << endl; 
   return 0;
}
//The following errors that were fixed are:
//changed the % to # for proper syntax on the first line
//added using namespace std;
//Changed the input statements to "cin" instead of "cout" to take input from user
//In the for loops, used '++' instead of '--' in order for the loop to end and work as intended
//Changed the integers in the for loop to characters