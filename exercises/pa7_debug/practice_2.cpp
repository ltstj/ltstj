// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.


#include <iostream>
using namespace std;
void display(int Matrix[3][3], int size);

int main(void)
{
  int size = 3;
  int Matrix[size][size];
  cout << "Enter 9 elements of the matrix:" << endl;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cin >> Matrix[i][j];
    }
  }
  display(Matrix, size);
  return 0;
}

void display(int Matrix[3][3], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << Matrix[i][j] << ", ";
    }
    cout << endl;
  } 
}

//The errors that were fixed are:
//1. changed Matrix variable type to int from double 
//2. changed "int Matrix[size + 1][size + 1]" to "int Matrix[size][size]"
//3. changed "cin" to "cout"
//4. put the "int j = 0" inside the for loop
//5. changed "Matrix[j][i]" to "Matrix[i][j]"
//6. changed "display(&Matrix, 3)" to "display(Matrix, size);"
//7. changed the "size" variable type to int from float inside display's parameters
//8. changed the comma to a semicolon in the first for loop
//9. changed the "i++" in the inner for loop to a "j++"
//10. added a semicolon at to "cout << endl"