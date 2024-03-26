//**********************************************************
//  matrix.h                                               *
//  Header file for the matrix multiplication assignment.  *
//  COP3330 ASSIGNMENT #4                                  *
//  Author: Dr. David A. Gaitros                           *
//  Date: January 6th, 2022                                *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef MATRIX_H
#define MATRIX_H

#include <string>
using namespace std;

class Matrix_Class {

public:
    Matrix_Class();                                 // Default Constructor
    Matrix_Class(const int r, const int c = 6); // Constructor
    ~Matrix_Class();                                // Destructor
    void Clear();                                   // Delete Matrix
    void Zero();                                    // Set all values to zero
    void Print(string msg)const;                   // Print Matrix to Stdout
    void Input();                                   // Input Matrix from Stdin
    void Resize(const int r, const int c);          // Clear and resize to row and col
    void setrow(const int r);                       // Set row size
    void setcolumn(const int c);                    // Set column size
    int  Getrowsize() { return rowsize; }         // Inline function to return rowsize NO NEED TO ADD TO CPP FILE
    int  Getcolsize() { return colsize; }         // Inline function to return colsize NO NEED TO ADD TO CPP FILE

    void MultArray(int** A, int** B, int** C, int m, int n, int l);


    // ************************************************************
    // Operator overloads                                           *
    // ************************************************************
    Matrix_Class& operator = (const Matrix_Class& m);
    Matrix_Class& operator * (Matrix_Class& m1);

private:
    int** matrix;         // 2d array that holds the matrix
    int rowsize;
    int colsize;
};

#endif