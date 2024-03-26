//**********************************************************
//  matrix.cpp                                             *
//  CPP file for the matrix multiplication assignment.     *
//  COP3330 ASSIGNMENT #4                                  *
//  Author: Oscar Naranjo                                  *
//  Date: January 16th, 2022                               *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#include "matrix.h"
#include <iomanip>
#include <iostream>

int const MINROW = 2;
int const MAXROW = 6;
int const MINCOL= 2;
int const MAXCOL = 6;

//  Default Constructor, Just sets the row and columns to zero. 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022                               
Matrix_Class::Matrix_Class()
{
	rowsize = 0;
	colsize = 0;

	matrix = nullptr;

}

//  Constructor with two parameters. The matrix must be between 2 
//  and 6 rows and columns and if a bad value is passed in use the default of 6 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
Matrix_Class::Matrix_Class(const int r, const int c)
{
	// initialize values with parameters
	setrow(r);
	setcolumn(c);

	matrix = new int* [rowsize];

	for (int i = 0; i < rowsize; i++)
		matrix[i] = new int[colsize];
	
}

//  Destructor.   Calls Clear().
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
Matrix_Class::~Matrix_Class()
{
	Clear();
}

//  Deletes the 2D Array and sets colsize and rowsize to zero. 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::Clear()
{
	// deletes rows
	for (int i = 0; i < rowsize; i++)
		delete[] matrix[i];

	// deletes 2D Array aka Matrix
	delete[] matrix;

	rowsize = 0;
	colsize = 0;
}

//  Sets all the values to zero
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::Zero()
{
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			matrix[i][j] = 0;
		}
	}
}

//  Prints the matrix out to standard output along with a message
//  that is passed in as a parameter. 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::Print(string msg) const
{

	// print out matrix
	cout << msg << endl;

	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Row size = " << rowsize << " Column size = " << colsize << endl;
}

//  Given the size of the row and column, it prompts the user to input the matrix 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::Input()
{
	cout << "PLease enter values for the matrix!" << endl;
	for (int i = 0; i < rowsize; i++) {
		cout << "Enter " << colsize << " integers for row " << i + 1 << ": ";
		for (int j = 0; j < colsize; j++) {
			cin >> matrix[i][j];
		}
	}
}

//  Changes the size of the matrix to the row and column passed in. 
//  If either the row or column is invalid..do not make any changes.   
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::Resize(const int r, const int c)
{
	// if row or column is invalid no changes 
	if (r < 2 || r > 6 || c < 2 || c > 6)
		cout << "Sorry input is invalid, no changes made!" << endl;
	else {

		Clear();
		// initialize values
		setrow(r);
		setcolumn(c);

		matrix = new int* [rowsize];

		for (int i = 0; i < rowsize; i++)
			matrix[i] = new int[colsize];
	}
	Zero(); // make zero
}

//  Set row values if input is wrong 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::setrow(const int r)
{
	if (r < MINROW || r > MAXROW)
		rowsize = 6;
	else rowsize = r;
}

//  set column values if wrong input 
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022  
void Matrix_Class::setcolumn(const int c)
{
	if (c < MINCOL || c > MAXCOL)
		colsize = 6;
	else colsize = c;
}

// *****************************************************************
// * In the routine below,  the parameters are described as such:  *
// * int * A - This is the first array to be multiplied            *
// * int * B - This is the second array to be multiplied.          *
// * int m   - This is the size of the first matrix  row.          *
// * int n   - This is the size of the second matrix column        *
// * int l   - This is the size of the second matrix row           * 
// *****************************************************************
void Matrix_Class::MultArray(int** A, int** B, int** C, int m, int n, int l)
{
	int i, j, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < l; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
}

//  Right Hand Side assignment operator.  Designed to be used 
//  for values on the right side of the equal sign that can be 
//  changed such as another Matrix_Class object.  
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022 
Matrix_Class& Matrix_Class::operator=(const Matrix_Class& m)
{
	
	
	// initialize values
	setrow(m.rowsize);
	setcolumn(m.colsize);

	matrix = new int* [rowsize];

	for (int i = 0; i < rowsize; i++)
		matrix[i] = new int[colsize];
		
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			matrix[i][j] = m.matrix[i][j]; // set equal to
		}
	}

	return *this;
}

//  Multiply two matrices and return the results.  
//  If the matrices cannot be multiplied ( i.e. the column size of
//  the first does not match the size of the rows and the second )
//  return *this as a results.  
//  Author: Oscar Naranjo                                  
//  Date: January 16th, 2022 
Matrix_Class& Matrix_Class::operator*(Matrix_Class& m1)
{
	// if the column size of the first does not match 
	// the size of the rows and the second

	if (colsize != m1.rowsize) {
		cout << "Matrices cannot be multiplied! Goodbye!" << endl;
		return *this;
	}

	else {
	static Matrix_Class newMatrix(Getrowsize(), m1.Getcolsize()); // return variable

	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < m1.colsize; j++)
		{
			newMatrix.matrix[i][j] = 0;
			for (int k = 0; k < m1.rowsize; k++) // rows times columns
			{
				newMatrix.matrix[i][j] += matrix[i][k] * m1.matrix[k][j]; // multiply matrices
			}
		}
	}
	return newMatrix;
	}
}
