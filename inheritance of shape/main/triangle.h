//**********************************************************
//  triangle.h                                             *
//  Header file for the Inheritance of Shape assignment.   *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape          *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <iomanip>
#include "shape.h"

using namespace std;

class Triangle : public Shape
{
	public:
		// Default and Data Constructors
		Triangle();
		Triangle(const double a, const double b, const double c);
		// set functions
		void setSide1(const double a);
		void setSide2(const double b);
		void setSide3(const double c);
		// get functions
		double getSide1() { return side1; }
		double getSide2() { return side2; }
		double getSide3() { return side3; }
		// prints data
		void virtual PrintData();

	private:
		double side1;
		double side2;
		double side3;
};
#endif

