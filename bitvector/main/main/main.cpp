
#include <iostream>
#include "bitvector.h"
#include <cmath>
using namespace std;
void TheSeive(BitVector& pn);

int main() {
    int largestprime = -0;
    cout << "Hello, BitVextor World!" << endl;
    // ******************************************************************
    // * Test the Default BitVector                                     *
    // ******************************************************************
    BitVector DefaultVector;
    BitVector CopyofDefaultVector;
    BitVector PrimeListTo(128);      // Prime numbers to 100
    // ******************************************************************
    // * Set all the odd bits on and print it out.                      *
    // ******************************************************************
    for (int x = 0; x < DefaultVector.Size(); x++)
        if (x % 2 != 0) DefaultVector.Set(x);
    DefaultVector.Print("All Odd Bits Should be turned on");
    // ******************************************************************
    // * Flip all the bits and print it out.   All even bits should     *
    // *    turned on.                                                  *
    // ******************************************************************
    DefaultVector.Flip();
    DefaultVector.Print("All Even Bits should be turned on");
    // ******************************************************************
    // * Make a copy of the Default Vector using the assignment         *
    // *     operator and Set bits 1 and 3 and unset buts 4 and 6 and   *
    // *     print it out.                                              *
    // ******************************************************************
    CopyofDefaultVector = DefaultVector;
    CopyofDefaultVector.Set(1);
    CopyofDefaultVector.Set(3);
    CopyofDefaultVector.Unset(4);
    CopyofDefaultVector.Unset(6);
    CopyofDefaultVector.Print("Copy of Default BitVector with mods");
    // ******************************************************************
    // * Calculate all prime numbers to 1000 and print them out.        *
    // ******************************************************************
    PrimeListTo.Set();    // Set all of them.
    TheSeive(PrimeListTo);
    PrimeListTo.Print("All Prime numbers up to 128");
    return 0;
}
void TheSeive(BitVector& pn)
{
    int sqrtoflargest = 0;
    sqrtoflargest = (int)sqrt((float)pn.Size());
    for (int index = 2; index < sqrtoflargest; index++)
        if (pn.Test(index))
            pn.Unsetmultiple(index);
}
