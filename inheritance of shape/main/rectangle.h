//**********************************************************
//  rectangle.h                                            *
//  Header file for the Inheritance of Shape assignment.   *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape            *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <iomanip>
#include "shape.h"

using namespace std;

class Rectangle : public Shape
{
	public:
		// Default and Data Constructors
		Rectangle();
		Rectangle(const double l1, const double l2);
		// set functions
		void setLength1(const double l1);
		void setLength2(const double l2);
		// get functions
		double getLength1() { return length1; }
		double getLength2() { return length2; }
		// prints data
		void virtual PrintData();

	private:
		double length1;
		double length2;

};

#endif