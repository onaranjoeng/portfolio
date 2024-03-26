//**********************************************************
//  square.h                                               *
//  Header file for the Inheritance of Shape assignment.   *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <iomanip>
#include "shape.h"

using namespace std;

class Square : public Shape
{
	public:
		// Default and Data Constructors
		Square();
		Square(const double l);
		// Set Functions
		void setLength(const double l);
		// Get Functions
		double getLength();
		// prints data
		void virtual PrintData();

	private:
		double length;
};
#endif

