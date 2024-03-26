
// ********************************************************************
// * Name: Stack main                                                 *
// * Description:  A template Stack class designed to be used with    *
// *   any simple C++ type to include floating point, double          *
// *   floating point, character, and boolan.                         *
// *   The stack pointer, as is the convention, points to the last    *
// *   or highest element in the array. So if you allocate 100        *
// *   elements of type "T" then the first empty element will be 99.  *
// * Author: Oscar Naranjo                                            *
// * Date: July 12, 2022                                              *
// ********************************************************************

#include <iostream>
#include <iomanip>
#include <vector>
#include "stack.h"

using namespace std;
int main(void)
{
    cout << "Assignment #7 Test Program" << endl;
    Stack<char> Char10;         // Test Character Stack, Default constructor
    Stack<float> Float5(5);     // Test Float Stack
    Stack<double> Double8(8);   // Test Double Stack
    Stack<bool> Bool2(2);       // Test Bool Stack
    Stack<char> Charcy(Char10); // Default copy constructor
    Bool2.Push(true);           // Test Push on Bool
    Bool2.Push(false);          // Test Push on Bool
    Bool2.Push(true);           // Test error on Push
    cout << "Size of Bool2 is:        " << Bool2.Size() << endl;
    cout << "Top element of Bool2 is: " << Bool2.Top() << endl;
    cout << "Size on Double8 should be 8: " << Double8.Size() << endl;
    Char10.Push('A');
    Char10.Push('B');
    Char10.Push('C');
    cout << "Test Pop on Char10, should produce a 'C': ";
    Char10.Pop();
    Char10.Push('C');
    cout << "Test ostream overload on Charcy, should be Empty:  ";
    cout << Charcy << endl;
    cout << "Test ostream overload on Char10, should be a 'C': ";
    cout << Char10 << endl;
    cout << "Test ostream overload on Char10, should be a 'B': ";
    cout << Char10 << endl;
    cout << "Test ostream overload on Char10, should be a 'A': ";
    cout << Char10 << endl;
    cout << "Test ostream overload on Char10, should be an error: ";
    cout << Char10 << endl;
    return 0;
}