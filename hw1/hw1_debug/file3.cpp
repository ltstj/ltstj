
#include <iostream>
using namespace std;

int main() {
    int num;
    bool factor_found = false;

    cout << "Enter Number:\n";
    cin >> num;

    if (num < 0) {
        cout << num << " is negative\n";
        return 0;
    }

    if (num == 0 || num == 1) {
        cout << num << " is not prime or composite\n";
        return 0;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            factor_found = true;
            break;
        }
    }

    if (factor_found) {
        cout << num << " is a composite number\n";
    } else {
        cout << num << " is a prime number\n";
    }

}
//The following errors that were fixed are:
//added using namespace std;
//changed the first if statement to 'num < 0' instead of 'num = 0' to detect negative numbers
//changed the second if statement to 'num == 0 || num == 1' instead of 'num == 0 && num == 1' to detect a 1 OR 0.
//set factor_false to false instead of true
//changed the for loop to 'int i = 2; i <= num / 2; i++' to properly detect factors if they exist