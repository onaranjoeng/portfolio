//**********************************************************
//  shape.cpp                                              *
//  CPP file for the Inheritance of Shape assignment.      *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************
#include "shape.h"
#include <iostream>
#include <iomanip>
using namespace std;

// default constructor
Shape::Shape()
{
	area = 0;
	perimeter = 0;
}

// constructor with parameters
Shape::Shape(const double a, const double p)
{
	setArea(a);
	setPerimeter(p);
}
// prints data
void Shape::PrintData()
{
	cout << "No specified Shape Data." << endl;
}
// sets area
void Shape::setArea(const double a)
{
	area = a;
}
// sets perimeter
void Shape::setPerimeter(const double p)
{
	perimeter = p;
}

