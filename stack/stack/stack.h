
#ifndef STACK_H
#define STACK_H
// Created by David A Gaitros on 10/15/19.
// ********************************************************************
// * Name: Stack Class                                                *
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
using namespace std;

const int DEFAULTSIZE = 100;

template <class T>
class Stack {

public:
    Stack();                    // Default Constructor, stack is size 100.
    ~Stack();                   // Destructor
    Stack(const int size);      // Constructor, creates stack of size "size"
    Stack(const Stack<T>& item);// Copy constructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    T Top();                    // Returns the top element, does not pop it.
    bool Push(const T item);   // Put an item on the stack.
    bool Pop();                 // Pop an item off and display to std out
    friend ostream& operator <<(ostream& os, Stack<T>& s)
    {
        if (s.Empty())
            os << "Error: Stack is empty";
        else {
            s.Pop();
            
        }
        return os;
       
    }

    Stack& operator=(const Stack<T> s)
    {
        // copy items
        _size = s._size;
        _top = s._top;
        _maxsize = s._maxsize;

        _stack = new T[_size];

        for (int i = 0; i < _size; i++)
            _stack[i] = s._stack[i];
    }

private:
    T* _stack;                  // The "stack"
    int _size;                  // number of elements actually stored
    int _top;                   // Points to the first empty node
    int _maxsize;               // Added to allow you to keep track of the size you allocated.
    T  dummy;                   // Something to return in case there was an error on the Top()
};

#endif 

// Default Constructor, stack is size 100.
template<class T>
inline Stack<T>::Stack()
{
    _stack = new T[DEFAULTSIZE];
    _maxsize = DEFAULTSIZE;
    _size = 0;
    _top = 0;

}

// Destructor
template<class T>
inline Stack<T>::~Stack()
{
    _size = 0;
    _top = 0;

//    delete[] _stack;

}

// Constructor, creates stack of size "size"
template<class T>
inline Stack<T>::Stack(const int size)
{
    _stack = new T[size];
    _maxsize = size;
    _size = 0;
    _top = 0;
}

// Copy constructor
template<class T>
inline Stack<T>::Stack(const Stack<T>& item)
{
    // copy items
    _size = item._size;
    _top = item._top;
    _stack = item._stack;

}

// Return true if the stack is full
template<class T>
inline bool Stack<T>::Full()
{
    if (_size == _maxsize) return true;
    else
        return false;
}

// Return true if the stack is empty
template<class T>
inline bool Stack<T>::Empty()
{
    if (_size == 0) return true;
    else return false;
}

// Return the size of the stack
template<class T>
inline int Stack<T>::Size()
{
    return _size;
}

// Returns the top element, does not pop it.
template<class T>
inline T Stack<T>::Top()
{
    if (Empty()) return dummy;
    else
        return _stack[_top - 1];
}

// Put an item on the stack.
template<class T>
inline bool Stack<T>::Push(const T item)
{
    if (!Full()) {
        _stack[_top] = item;
        _top++;
        _size++;
    }
    else {
        cout << "Cannot Push an element on a full stack. " << endl;
        return false;
    }
    return true;
}

// Pop an item off and display to std out
template<class T>
inline bool Stack<T>::Pop()
{
    if (!Empty()) {
        _top = _top - 1;
        cout << _stack[_top];
        _size--;
    }
    else {
        cout << "The stack is empty. " << endl;
        return false;
    }
    return true;
}


