//**********************************************************
//  shape.h                                                *
//  Header file for the Inheritance of Shape assignment.   *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                 *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <iomanip>
using namespace std;

class Shape
{
	public:
		// Default and Data Constructors
		Shape();
		Shape(const double a, const double p);
		// print Function
		virtual void PrintData()=0;
		// Set Functions
		void setArea(const double a);
		void setPerimeter(const double p);
		// Get Functions
		double getArea() { return area; }
		double getPerimeter() { return perimeter; }
		
	private:
		double area;
		double perimeter;
};
#endif

