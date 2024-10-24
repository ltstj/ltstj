// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with for.
#include <iostream>
#include <iomanip>
#include <cmath> // standard math library
using namespace std;

int main()
{
   int years = 398; //years passed from 1626 to 2024
   double principal = 11.0; // initial amount before interest
   double currentVal = 860000000.0; //Mona Lisa value

   // display headers
   cout << "Interest Rate" << setw( 21 ) << "Amount on deposit" << endl;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // calculate amount on deposit for interest rates 2% - 10%
   for (double interest = 0.02; interest <= 0.10; interest += 0.005) {
        double amount = principal * pow(1.0 + interest, years);
        cout << setw(7) << interest * 100 << "%" << setw(21) << amount << endl;
    } 
   
      //S&P 500 average return rate calculation
      double total = principal * pow(1.1017, years);
      cout << "\nS&P 500 average return (10.17%): " << total << endl;

      //NASDAQ average return rate calculation
      double amount = principal * pow(1.104, years);
      cout << "\nS&P 500 average return (10.4%): " << amount << endl;

      //prints estimated value
      cout << "\nThe estimated value of the Mona Lisa: " << currentVal << endl;

} 


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
