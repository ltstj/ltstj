//Author: Tejadatta Kalapatapu
//May 10, 2024
//Practice Activity 2: 
//Spelling my first name out with ASCII
#include <iostream>

int main() {
    //Letters are represented by the #s

    //T
    std::cout << "#####\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "  #  \n";
    }

    std::cout << "\n"; // Spacer line

    //E
    std::cout << "#####\n";
    std::cout << "#    \n";
    std::cout << "#### \n";
    std::cout << "#    \n";
    std::cout << "#####\n";

    std::cout << "\n"; // Spacer line

    //J
    std::cout << "#####\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "    #\n";
    }
    std::cout << "#### \n";

    std::cout << "\n"; // Spacer line

    //A
    std::cout << "  #  \n";
    std::cout << " # # \n";
    std::cout << "#####\n";
    std::cout << "#   #\n";
    std::cout << "#   #\n";
}
