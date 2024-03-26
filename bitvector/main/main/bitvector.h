
#ifndef BITVECTOR_H
#define BITVECTOR_H
#include <iostream>
using namespace std;
class BitVector
{
public:
	BitVector();                          // Default Constructor
	explicit BitVector(size_t);         // construct a BitVector
	// with specified size
	BitVector(const BitVector&);        // copy constructor
	~BitVector();
	void Set(const size_t index);      // make index bit = 1
	void Set();                        // make all bits = 1
	void Unsetmultiple(const size_t index);
	// Unset all bits up to the
	// max numbr that are multiples
	// of the number passed in.
	void Unset(const size_t index);      // make index bit = 0
	void Unset();                        // make all bits = 0
	void Flip(const size_t index);
	// flip index bit (change value of bit)
	void Flip();                        // flip all bits
	bool Test(size_t index) const;      // return index bit value
	void Print(const string x);                        // Prints index value
		//  and ascii value of
		//  bits turned on.
		// destructor
		BitVector& operator = (const BitVector& a);
	// assignment operator
	size_t Size() const;                 // return the number of bits
private:
	int size;                             // Number of words;
	int* bvect;                          // Bit Vector dynamically
};
#endif
