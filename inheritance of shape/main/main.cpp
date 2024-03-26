//**********************************************************
//  main.cpp                                               *
//  Main file for the Inheritance of Shape assignment.     *
//  COP3330 ASSIGNMENT #5 Inheritance of Shape             *
//  Author: Oscar Naranjo                                  *
//  Date: June 19th, 2022                                  *
//  Copyright:  For educational purposes Florida State     *
//       University, Computer Science. Not for             *
//       Distribution.                                     *
// *********************************************************

#include <iostream>
#include <iomanip>
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
using namespace std;


int main() {

    cout << "WELCOME TO THE SHAPE INHERITANCE PROGRAM!" << endl<< endl;

    Square Newsquare;
    Square square(5.50); // square object created
    square.getArea();
    square.getPerimeter();
    square.PrintData();
    cout << endl;

    Rectangle Newrectangle;
    Rectangle rectangle(44.00,31.00); // rectangle object created
    rectangle.getArea();
    rectangle.getPerimeter();
    rectangle.PrintData();
    cout << endl;

    Circle Newcircle;
    Circle circle(4.33); // circle object created
    circle.getArea();
    circle.getPerimeter();
    circle.PrintData();
    cout << endl;

    Triangle Newtriangle;
    Triangle triangle(5.00,5.00,5.00); // triangle object created
    triangle.getArea();
    triangle.getPerimeter();
    triangle.PrintData();
    cout << endl;

    return 0;
}
