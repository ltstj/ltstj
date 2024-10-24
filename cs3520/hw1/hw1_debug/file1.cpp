/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'


*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments) at the end of file.

#include <iostream>
using namespace std;

int main() {
  int limit = 10, even_product = 1, odd_product = 1, sum = 0; // set even_product and odd_product to 1
  char c;

  cout << "The value of limit is " << limit << endl;

  // Calculate the sum of products of odd and even numbers from 1 to limit
  for (int i = 1; i <= limit; ++i) {
    if (i % 2 == 0) {
      even_product *= i;
    } else {
      odd_product *= i;
    }
  }
  sum = even_product + odd_product;
  cout << "The Sum = " << sum << "\n";

  // prints A to Z in reverse order
  for (c = 'Z'; c >= 'A'; c -= 2) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}

//The following errors that were fixed are:
//fixing the values of the variables even_product and odd_product and setting sum to 0
//changing the loop in the first loop to i = 1
//changing the second loop to print "c" instead of "i"