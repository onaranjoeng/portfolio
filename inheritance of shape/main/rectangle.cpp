//**********************************************************
//  rectangle.cpp                                          *
//  CPP file for the Inheritance of Shape assignment.      *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************
#include "rectangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

const double MINSIZE = 1.00;

// default constructor
Rectangle::Rectangle()
{
	length1 = 0;
	length2 = 0;
}
// constructor with parameters
Rectangle::Rectangle(const double l1, const double l2)
{
	setLength1(l1);
	setLength2(l2);

	double area = length1* length2;
	double perimeter = (length1 * 2) * (length2 * 2);

	setArea(area);
	setPerimeter(perimeter);
}
// sets length to min if below 1
void Rectangle::setLength1(const double l1)
{
	if (l1 < MINSIZE)
		length1 = MINSIZE;
	else
		length1 = l1;
}
// sets length to min if below 1
void Rectangle::setLength2(const double l2)
{
	if (l2 < MINSIZE)
		length2 = MINSIZE;
	else
		length2 = l2;
}

void Rectangle::PrintData()
{
	cout << "The area of the rectangle is " << getArea() << endl;
	cout << "The perimeter of the rectangle is " << getPerimeter() << endl;
}
