//**********************************************************
//  circle.cpp                                             *
//  CPP file for the Inheritance of Shape assignment.      *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************
#include "circle.h"
#include <iostream>
#include <iomanip>
using namespace std;

const double MINRADIUS = 1.00;

// default constructor
Circle::Circle()
{
	radius = 0;
}
// constructor with parameters
Circle::Circle(const double r)
{
	setRadius(r);
}
// set radius to 1 if its lower than 1
void Circle::setRadius(const double r)
{
	if (r < MINRADIUS)
		radius = MINRADIUS;
	else
		radius = r;
	
	// calculate area and perimeter of circle
	double area = 3.14159265359 * radius * radius;
	double perimeter = 3.14159265359 * 2 * radius;

	setArea(area);
	setPerimeter(perimeter);
}
// print data
void Circle::PrintData()
{
	cout << "The area of the circle is " << getArea() << endl;
	cout << "The perimeter of the circle is " << getPerimeter() << endl;
}
