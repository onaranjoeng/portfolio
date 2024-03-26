// BY OSCAR NARANJO
// COP4530
// OCTOBER 13, 2022

#include "stack.h"

//Constructor
template <typename T>
Stack<T>::Stack()
{
    init();
}

//Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& rhs)
{
    init();
    for (auto itr = rhs.theArray.begin(); itr != rhs.theArray.end(); ++itr)
        push(*itr);
}

//Move Constructor
template <typename T>
Stack<T>::Stack(Stack<T>&& rhs) : topOfStack{ rhs.topOfStack }, theArray{ rhs.theArray }
{
    rhs.topOfStack = -1;
    rhs.theArray = std::vector<T>();
}

//Destructor
template <typename T>
Stack<T>::~Stack<T>()
{
    clear();
}

//Member Function Init
template <typename T>
void Stack<T>::init() 
{
    //Initialize empty double linked list with 2 nodes H,T
    topOfStack = -1;
}

//Copy Assignment Operator
template <typename T>
const Stack<T>& Stack<T>::Stack::operator=(const Stack<T>& rhs) 
{
    // make a copy
    Stack<T> copy = rhs;
    std::swap(*this, copy); // swap
    return *this;
}

//Move Assignment Operator
template <typename T>
Stack<T>& Stack<T>::Stack::operator=(Stack<T>&& rhs) 
{
    // same as copy assignment operator=
    std::swap(topOfStack, rhs.topOfStack);
    std::swap(theArray, rhs.theArray);
}

//Member Size
template <typename T>
int Stack<T>::size() const
{
    // returns the number of elements stored in the Stack.
    return (theArray.size()); 
}

//Member Empty
template <typename T>
bool Stack<T>::empty() const 
{
    //  returns true if the Stack contains no elements, and false otherwise.
    if (size() <= 0)
        return true;
    else
        return false;
}

//Function Clear
template <typename T>
void Stack<T>::clear()
{
    //  delete all elements from the stack.
    while (!empty())
        pop();
}

//Top of Stack
template <typename T>
T& Stack<T>::top()
{
    // returns a reference to the most recently added element of the Stack
    // (as a modifiable L-value).
    return theArray[topOfStack];
}

//Top of Stack Const
template <typename T>
const T& Stack<T>::top() const 
{   
    // accessor that returns the most recently added element of the Stack (as a const reference)
    return theArray[topOfStack];
}

//Copy version of push to stack
template <typename T>
void Stack<T>::push(const T& x)
{
    // adds x to the Stack. copy version.
    topOfStack++;
    theArray.push_back(x);
}

//Move version of push to stack
template <typename T>
void Stack<T>::push(T&& val) 
{
    // adds x to the Stack.move version.
    topOfStack++;
    theArray.push_back(std::move(val));
}

//Pop last element
template <typename T>
void Stack<T>::pop()
{
    // removes and discards the most recently added element of the Stack.
    theArray.pop_back();
    topOfStack--;
}

//Print out elements in opposite order of Stack, oldest first
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const {
    //Prints out the given type data for every element in list
    for (auto itr = theArray.begin(); itr != theArray.end(); ++itr) {
        os << *itr << ofc;
    }
}

//Non-Class Global Overloaded Functions
template <typename T>
bool operator==(const Stack<T>& lhs, const Stack<T>& rhs) 
{

    //Compares if two lists are equal
    if (lhs.size() == rhs.size()) {
        Stack<T> leftTemp = lhs, rightTemp = rhs;
        while (!leftTemp.empty() && !rightTemp.empty()) {
            if (leftTemp.top() != rightTemp.top())
                return false;
            leftTemp.pop();
            rightTemp.pop();
        }
        return true;
    }
    else return false;
}

template <typename T>
bool operator!=(const Stack<T>& lhs, const Stack<T>& rhs) 
{
    return (!(lhs == rhs)); //Return opposite of == operator
}

// returns true if every element in Stack a is smaller than
// or equal to the corresponding element of Stack b
template <typename T>
bool operator<=(const Stack<T>& a, const Stack<T>& b) 
{
    // if they are equal
    if (a == b)
        return true;
    // if its less than
    Stack<T> aTemp = a, bTemp = b;
    while (!aTemp.empty()) {
        if (bTemp.empty())
            return true;
        if (aTemp.top() > bTemp.top())
            return false;
        aTemp.pop();
        bTemp.pop();
    }
    return true;
}

// vokes the print() method to print the Stack a in the specified ostream
template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& a) 
{
    //Call print function of Stack
    a.print(os);
    return os;
}