// Program to read 3-dimensional matrix and display the elements as N^3 matrix
// TODO
// take the SIZE of the matrix as input from the user
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
//

#include <iostream>
using namespace std;

void update_3d(double Matrix_3d[][7][7], int size);
void display_1d(const double Matrix_3d[][7][7], int size);

int main(void)
{
	int size;
	cout << "Enter the size: ";
	cin >> size;
	// prompt the user to initialize the matrix accordingly
	double Matrix_3d[7][7][7] = {};
	// initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, size);
	// display the values
	display_1d(Matrix_3d, size);
	return 0;
}

void update_3d(double matrix_3d[][7][7], int size)
{
	cout << "Entering N^3 elements of the matrix:" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				matrix_3d[i][j][k] = rand() % 100;// cin for Matrix_3d[i][j][k] or random number generator
			}
		}
	}
}

// update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
// must not be able to update the array.
// Share any observations.
void display_1d(const double matrix_3d[][7][7], int size) {
	const double *matrix_1d = &matrix_3d[0][0][0];
	for (int i= 0; i < size*size*size; i++) {
		cout << "The address is " << (matrix_1d + i) << " and the value is " << *(matrix_1d + i) << endl;
    }
}

//Errors that were fixed:
//1. added "using namespace std"
//2. added a way for the user to decide the size instead of it being set
//3. added the random function to the update_3d function
//4. Changed the display_1d function to only contain 1 for loop that iterates through all the values and addresses.