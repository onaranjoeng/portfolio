// ***************************************************************
// * Template Assignment simplevector.h                          *
// * Description:  Contains the basic definition of the          *
// * SimpleVector Template class.  The method names and          *
// * signatures must not be modified. You will add your          *
// * Method implementation to the end of this file where         *
// * indicated.                                                  *
// * Author: Oscar Naranjo                                       *
// * Last Modified:  June 30th, 2022.                            *
// ***************************************************************

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new> // Needed for bad_alloc exception
#include <cstdlib> // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector {

	private:

		T* aptr; // To point to the allocated array
		int arraySize; // Number of elements in the array
		void memError(); // Handles memory allocation errors
		void subError(); // Handles subscripts out of range

	public:

		// Default constructor
		SimpleVector()
		{
			aptr = 0; arraySize = 0; // already written
		}
	
		SimpleVector(int);// Constructor with parameters
		SimpleVector(const SimpleVector&);// Copy constructor 
		~SimpleVector();// Destructor 
		int size() const { return arraySize;}// Accessor to return the array size
		T getElementAt(int position);// Accessor to return a specific element
		T& operator[](const int&); // Overloaded [] operator 
		
		// My own functions for program to work
		int ptr_size() const { return (int)sizeof(aptr);}
		// Pop back
		void pop_back();
		void push_back(T element);

};

// Constructor to sets the size of the array and allocates memory for it
template <class T>
SimpleVector<T>::SimpleVector(int s) {

	arraySize = s;
	// Allocate memory for the array.
	try {
		aptr = new T[s];
	}
	catch (bad_alloc) {
		memError();
	}
	// Initialize the array.
	for (int i = 0; i < arraySize; i++)
		*(aptr + i) = 0;

}

// Copy Constructor 
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj){

	// Copy the array size
	arraySize = obj.arraySize;
	// Allocate memory for the array
	aptr = new T[arraySize];

	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for (int i = 0; i < arraySize; i++)
		*(aptr + i) = *(obj.aptr + i);

}

// Destructor aka destroys array
template <class T>
SimpleVector<T>::~SimpleVector() {

	if (arraySize > 0)
		delete[] aptr;

}

// memError function aka terminates the program when memory allocation fails

template <class T>
void SimpleVector<T>::memError(){

	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);

}

// subError function aka terminates the program when a subscript is out of range. 

template <class T>
void SimpleVector<T>::subError() {

	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);

}

// getElementAt function
template <class T>
T SimpleVector<T>::getElementAt(int sub) {

	if (sub < 0 || sub >= arraySize)
		subError();

	return aptr[sub];

}

// Overloaded [] operator
// This function returns a reference to the element 
template <class T>
T& SimpleVector<T>::operator[](const int& sub){

	if (sub < 0 || sub >= arraySize)
		subError();

	return aptr[sub];

}

// This function pop back the first element
template <class T>
void SimpleVector<T>::pop_back() {

	if (arraySize < 0)
		subError();

	else {

		// Allocate memory 
		T* temp = new T[arraySize];

		if (temp == 0)
			memError();

		// Copy the elements 
		for (int i = 0; i < arraySize - 1; i++)
			*(temp + i) = *(aptr + i);

		//Decrement array
		arraySize = arraySize - 1;

		//Clear 
		delete[] aptr;

		aptr = new T[arraySize];

		// Copy the elements
		for (int i = 0; i < arraySize; i++)
			*(aptr + i) = *(temp + i);

	}

}

//Push element back
template <class T>
void SimpleVector<T>::push_back(T element) {

	if (arraySize < 0)
		subError();

	else {

		T* tempArray = new T[arraySize + 1];

		if (tempArray == 0)
			memError();

		// Copy the elements into new array
		for (int i = 0; i < arraySize; i++)
			*(tempArray + i) = *(aptr + i);

		//Increment array
		arraySize = arraySize + 1;

		*(tempArray + (arraySize - 1)) = element;

		
		delete[] aptr;

		aptr = new T[arraySize];

		for (int i = 0; i < arraySize; i++)
			*(aptr + i) = *(tempArray + i);

	}

}

#endif
