//**********************************************************
//  circle.h                                               *
//  Header file for the Inheritance of Shape assignment.   *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <iomanip>
#include "shape.h"

using namespace std;

class Circle : public Shape
{
	public:
		// Default and Data Constructors
		Circle();
		Circle(const double r);
		// set functions
		void setRadius(const double r);
		// get functions
		double getRadius() { return radius;}
		// prints data
		void virtual PrintData();

	private:
		double radius;
};
#endif
