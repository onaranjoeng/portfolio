// Oscar Naranjo
// May 31, 2022
// COP3330
// Assignment 2
// Implementing BitVector of undetermined size implementing new
//concepts of copy constructor and assignment operators as well
// as destructors to determine the prime numbers up to a maximum range. 

#include <iostream>
#include <iomanip>
#include <string>
#include "bitvector.h"
using namespace std;

// make index bit = 1 
void BitVector::Set(const size_t index) {
	int word, offset, mask = 1;
	word = index / 32;
	offset = index % 32;
	offset = 31 - offset;
	mask = mask << offset;
	bvect[word] |= mask;
}

// make all bits = 1
void BitVector::Set() {
	//for (int i = 0; i < size*32; ++i)
	//	Unset(i);
	for (int i = 0; i < size; ++i)
		bvect[i] = 255;

}

// Unset all bits up to the
	// max numbr that are multiples
	// of the number passed in.
void BitVector::Unsetmultiple(const size_t index) {

	int word, offset, mask;

	for (int i = index; i < size * 32; ++i) {

		mask = 1;

		if (Test(i)) {
			word = i / 32;
			offset = i % 32;
			offset = 31 - offset;
			mask = mask << offset;
			bvect[word] ^= mask;
		}

	}


}


// make index bit = 0
void BitVector::Unset(const size_t index) {

	int word, offset, mask = 1;

	if (Test(index)) {
		word = index / 32;
		offset = index % 32;
		offset = 31 - offset;
		mask = mask << offset;
		bvect[word] ^= mask;
	}
}

// make all bits = 0
void BitVector::Unset() {
	for (int i = 0; i < size; ++i)
		bvect[i] = 0;
}

// flip index bit (change value of bit)
void BitVector::Flip(const size_t index) {
	size_t word, offset, mask = 1;
	word = index / 32;
	offset = index % 32;
	offset = 31 - offset;
	mask = mask << offset;
	bvect[word] |= mask;
}

// flip all bits 
void BitVector::Flip() {
	for (int i = 0; i < size * 32; ++i)
		Flip(i);
}

// return index bit value
bool BitVector::Test(size_t index) const
{
	int word, offset, mask = 1;
	word = index / 32;
	offset = index % 32;
	offset = 31 - offset;
	mask = mask << offset;

	mask = bvect[word] & mask;

	if (mask != 0) return true;
	else return false;
}

// Prints index value and ascii value of bits turned on
void BitVector::Print(const string x) {

	cout << x << endl;
	cout << endl;

	for (int i = 0; i < size * 32; ++i)
		if (Test(i)) cout << "Bit index " << i << " is true" << endl;

}

// Default Constructor
BitVector::BitVector() : BitVector(256) { }

// construct a BitVector w specified size
BitVector::BitVector(size_t numbits)
{
	size = numbits / 32;
	if (numbits % 32 != 0) size++;
	bvect = new int[size];
	if (bvect == 0)
	{
		cout << "** BitVector memory allocation failure -- terminating program.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; ++i)
		bvect[i] = 0;

}

// destructor
BitVector::~BitVector() {
	delete[] bvect;
}

// copy constructor
BitVector::BitVector(const BitVector& a)
{
	size = a.Size();
	bvect = new int[size];
	for (size_t i = 0; i < size; ++i)
		bvect[i] = a.bvect[i];

}

// assignment operator
BitVector& BitVector::operator=(const BitVector& a)
{

	size = a.Size();
	bvect = new int[size];
	for (size_t i = 0; i < size; ++i)
		bvect[i] = a.bvect[i];
	return *this;
}


// return size of bitvector
size_t BitVector::Size() const
{
	return size;
}