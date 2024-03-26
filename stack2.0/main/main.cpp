// ********************************************************************
// * Name: Stack main                                                *
// * Description: A template Stack class designed to be used with     *
// * any simple C++ type to include floating point, double            *
// * floating point, character, and Boolean.                          *
// * The stack pointer, as is the convention, points to the last      *
// * or highest element in the array. So if you allocate 100          *
// * elements of type "T" then the first empty element will be 99.    *
// * Author: Oscar Naranjo                                            *
// * Date: September 1, 2022                                          *
// ********************************************************************

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
int main(void) {
    cout << "Assignment #0 Test Program" << endl;

    Stack<char>     Char26(26);     // Test Character Stack
    Stack<char>     Char26Cy(26);   // Test Assignment operator
    Stack<int>      Int100;              // Test Integer Stack default value
    Stack<float>    Float10(10);    // Test float of Size 10
    Stack<bool>     Bool2(2);       // Test bool of Size 2
    Bool2.Push(true);
    Bool2.Push(false);
    Stack<bool>     Bool2Cy(Bool2);     // Copy constructor

// *********************************************************************
// * Test of the Character stack of size 26.                           *
// *********************************************************************
    cout << "********* Test of Character Stack*********" << endl;
    char Alphabet = 'Z';
    for (int index = 0; index < 26; index++) {
        Char26.Push(Alphabet);
        Alphabet = (char(int(Alphabet - 1)));
    }
    cout << Char26 << endl;

    // Test Bool Stack
// *********************************************************************
// * Test of the Assignment Overload                                   *
// *********************************************************************
    Char26Cy = Char26;
    cout << "********** Test of Assignment = operator overload *********" << endl;
    cout << Char26Cy << endl;

    // *********************************************************************
    // * Test of the Integers                                              *
    // *********************************************************************
    cout << "********** Test of the Integer Stack *********" << endl;
    for (int index = 10; index >= 0; index--)
        Int100.Push(index);
    cout << Int100 << endl;

    // *********************************************************************
    // * Test of the Floats                                                *
    // *********************************************************************
    cout << "********** Test of the Float Stack *********" << endl;
    cout << "********** Should be an error, stack is full ********";
    for (int index = 10; index >= 0; index--)
        Float10.Push(index + .5);
    cout << Float10 << endl;

    // *********************************************************************
    // * Test of the bool stack and copy constructor.                      *
    // *********************************************************************
    cout << "********* Test of Bool stack, copy constructor *********" << endl;
    cout << Bool2Cy << endl;
    return 0;
}