// This program should read any string (including spaces) from the user and print it using a character pointer
// The program is setup to use pointer offset notation to get each character of the string

// Number of bugs/errors : 8

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  char s[20];
  char* cPtr;
  cin.getline(s,20);
  cPtr = s;
  while (*cPtr != '\0')
  {
    cout << *cPtr;
    cPtr++;
  }
  cout << "\n";
  return 0;
}

//The 8 errors that were fixed were:
//1. changed "include <stdio>" to "include <iostream>"
//2. changed "include <string>" to "include <cstring>"
//3. changed "void main(void)" to "int main(void)"
//4. changed "char cPtr" to "char* cPtr" 
//5. changed "cin >> s" to "cin.getline(s,20)"
//6. changed "(cPtr-- == '\0')" to "(*cPtr != '\0')"
//7. changed "cout << cPtr++" to "cout << *cPtr"
//8. added cPtr++ after the previous statement