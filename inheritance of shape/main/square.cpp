//**********************************************************
//  square.cpp                                             *
//  CPP file for the Inheritance of Shape assignment.      *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************
#include "square.h"
#include <iostream>
#include <iomanip>
using namespace std; 

const double MINLENGTH = 1.00;
// default constructor
Square::Square()
{
	length = 0;
}
// constructor with parameters
Square::Square( const double l) : Shape(l*l, l*4)
{
	setLength(l);
}
// sets length if below 1.00
void Square::setLength(const double l)
{
	if (l < MINLENGTH)
		length = MINLENGTH;
	else
		length = l;

}
double Square::getLength()
{
	return length;
}
// prints data 
void Square::PrintData()
{
	cout << "The area of the square is " << getArea() << endl;
	cout << "The perimiter of the square is " << getPerimeter() << endl;
}
