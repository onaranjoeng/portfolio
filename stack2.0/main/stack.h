// ********************************************************************
// * Name: Stack Class                                                *
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
using namespace std;
const int DEFAULTSIZE = 100;
template <typename T>

// ********************************************************************
// * The following 4 lines of code are there so the friend output     *
// * operator works in the IDE environments like CLION.               *
// ********************************************************************

class Stack;
template <class T>
ostream& operator <<(ostream& os, Stack<T>& s)
{

    if (s.Empty())
        os << "The Stack is empty" << endl;
    else
        os << "The Stack is not empty" << endl;
    os << "The Top element is-> " << s.Top() << endl;
    os << "The size of the stack is : " << s.Size() << endl;
    os << "The number of elements it can hold is : " << s.Number() << endl;
    if (s.Full())
        os << "The Stack is Full!" << endl;
    else
        os << "The Stack is not Full!" << endl;

    os << "Popping the top element before we print it out" << endl;
    s.Pop();
    os << "The contents of the stack is : ";

    for (int i = s._top + 1; i < s._size; i++)
        os << s._stack[i];
    os << endl;
    return os;

}

// ********************************************************************
// * The class Stack definition.                                      *
// ********************************************************************

template <typename T>
class Stack {
public:
    Stack();                             // Default Constructor, stack is size 100.
    Stack(const int size);               // Constructor, creates stack of size "size"
    Stack(const Stack& Obj);            // Copy constructor
    bool Full();                         // Return true if the stack is full
    bool Empty();                        // Return true if the stack is empty
    int Size();                          // Return the size of the stack
    int Number();                        // Return the number of elements stored
    T Top();                             // Returns the top element, does not pop it
    //void List();                         // Prints out the stack.
    bool Push(const T item);            // Put an item on the stack
    bool Pop();                          // Pop an item off and display to std out

    friend ostream& operator << <>(ostream& os, Stack<T>& s);

    Stack<T>& operator = (const Stack<T>& s) {

        _stack = new T[s._size];
        _size = s._size;
        _number = s._number;
        _top = s._top;

        for (int i = 0; i < s._size; i++)
            _stack[i] = s._stack[i];

        return *this;
    }

    ~Stack();                             // deletes the array

private:

    T dummy;
    T* _stack;                          // The "stack"
    int _size;                           // The number of elements the stack can hold
    int _top;                            // Points to the first empty node
    int _number;                         // The number of elements in the stack.

};

// Functions made by Oscar Naranjo
// September 1, 2022
// Default Constructor, stack is size 100.

template<typename T>
inline Stack<T>::Stack()
{
    _stack = new T[DEFAULTSIZE];
    _size = DEFAULTSIZE;
    _number = 0;
    _top = 99;
}

// Constructor, creates stack of size "size"
template<typename T>
inline Stack<T>::Stack(const int size)
{
    if (size > 0) {
        _stack = new T[size];
        _size = size;
        _number = 0;
        _top = size - 1;
    }
    else {
        _stack = new T[DEFAULTSIZE];
        _size = DEFAULTSIZE;
        _number = 0;
        _top = 99;
    }
}

// Copy constructor
template<typename T>
inline Stack<T>::Stack(const Stack& Obj)
{
    // copy items
    _number = Obj._number;
    _top = Obj._top;
    _size = Obj._size;
    _stack = new T[Obj._size];

    for (int i = 0; i < _size; i++)
        _stack[i] = Obj._stack[i];

}

// Return true if the stack is full
template<typename T>
inline bool Stack<T>::Full()
{
    if (_number == _size) return true;
    else
        return false;
}

// Return true if the stack is empty
template<typename T>
inline bool Stack<T>::Empty()
{
    if (_number == 0) return true;
    else return false;
}

// Return the size of the stack
template<typename T>
inline int Stack<T>::Size()
{
    return _size;
}

// Return the number of elements stored
template<typename T>
inline int Stack<T>::Number()
{
    return _number;
}

// Returns the top element, does not pop it
template<typename T>
inline T Stack<T>::Top()
{
    if (Empty()) return dummy;
    else
        return _stack[_top + 1];
}

// Put an item on the stack
template<typename T>
inline bool Stack<T>::Push(const T item)
{
    if (!Full()) {
        _stack[_top] = item;
        _top--;
        _number++;
    }
    else {
        cout << endl << "Error pushing, stack full!" << endl;
        return false;
    }
    return true;
}

// Pop an item off and display to std out

template<typename T>
inline bool Stack<T>::Pop()
{
    if (!Empty()) {
        _top = _top + 1;
        _number--;
    }
    else {
        cout << "Eror: The stack is empty." << endl;
        return false;
    }
    return true;
}

// delete constructor
template<typename T>
inline Stack<T>::~Stack()
{
    _number = 0;
    _top = 0;
    _size = 0;
}