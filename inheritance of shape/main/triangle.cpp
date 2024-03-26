//**********************************************************
//  triangle.cpp                                             *
//  CPP file for the Inheritance of Shape assignment.      *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************
#include "triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double MINSIZE = 1.00;

// default constructor
Triangle::Triangle()
{
	side1 = 0;
	side2 = 0;
	side3 = 0;
}
// constructor with parameters
Triangle::Triangle(const double a, const double b, const double c) 
{
	setSide1(a);
	setSide2(b);
	setSide3(c);
	
	// calculate area of triangle
	double s = (side1 + side2 + side3) / 2;
	double root = s * (s - side1) * (s - side2) * (s - side3);
	double area = sqrt(root);

	// calculate perimeter of triangle
	double perimeter = (side1 + side2 + side3);

	setPerimeter(perimeter);
	setArea(area);
}

// print data
void Triangle::PrintData()
{
	cout << "The area of the triangle is " << getArea() << endl;
	cout << "The perimeter of the triangle is " << getPerimeter() << endl;
}

// set side
void Triangle::setSide1(const double a)
{
	if (a < MINSIZE)
		side1 = MINSIZE;
	else
		side1 = a;
}
// set side
void Triangle::setSide2(const double b)
{
	if (b < MINSIZE)
		side2 = MINSIZE;
	else
		side2 = b;
}
// set side
void Triangle::setSide3(const double c)
{
	if (c < MINSIZE)
		side3 = MINSIZE;
	else
		side3 = c;
}
