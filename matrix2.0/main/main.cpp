//**********************************************************
//  main.cpp                                               *
//  Header file for the matrix multiplication assignment.  *
//  COP3330 ASSIGNMENT #4                                  *
//  Author: Oscar Naranjo                                  *
//  Date: June 16th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;


int main() {

    cout << "WELCOME TO THE MATRIX PROGRAM!" << endl;
    Matrix_Class MyMatrix1(4, 4);        // 4x4 matrix
    Matrix_Class MyMatrix2(4, 4);        // 4x4 matrix
    Matrix_Class MyMatrix3(2, 3);        // 2x3 matrix
    Matrix_Class MyMatrix4(3, 3);        // 3x3 matrix 

    Matrix_Class DuplicateMatrix;
    Matrix_Class DuplicateMatrix2;

    MyMatrix1.Input();
    MyMatrix2.Input();
    // ********************************************
    // * Test print of matrix.                    *
    // ********************************************
    MyMatrix1.Print("Printing out the contents of Matrix 1: ");
    MyMatrix1.Print("Printing out the contents of Matrix 2: ");

    // make zero and resize 
    MyMatrix1.Resize(6,6);
    MyMatrix1.Print("Printing out the contents of Matrix 1: ");
    MyMatrix2.Print("Printing out the contents of Matrix 2: ");

    // matrices to be multiplied
    MyMatrix3.Input();
    MyMatrix4.Input();

    // *********************************************
    // * Test multipication and assignment operator*
    // *********************************************
    DuplicateMatrix = MyMatrix3 * MyMatrix4;  // works because of same size
    DuplicateMatrix2 = MyMatrix1 * MyMatrix4;  // should not work not same size
    DuplicateMatrix.Print("Duplicate Multiplication");
    DuplicateMatrix2.Print("Duplicate Multiplication fail!");
    cout << "I am done Neo! !" << endl;
    return 0;
}
