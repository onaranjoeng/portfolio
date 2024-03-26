// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
    List();      // constructor
    List(const List&); // copy constructor
    ~List();     // destructor
    void insertAtFront(const NODETYPE&);
    void insertAtBack(const NODETYPE&);
    void insertMiddle(NODETYPE&, int);
    bool removeFromFront(NODETYPE&);
    bool removeFromBack(NODETYPE&);
    bool removeMiddle(NODETYPE&, int);
    bool isEmpty() const;
    void print() const;
    List& operator=(const List&);   // assignment operator

private:
    ListNode< NODETYPE >* firstPtr;  // pointer to first node
    ListNode< NODETYPE >* lastPtr;   // pointer to last node

    // utility function to allocate new node
    ListNode< NODETYPE >* getNewNode(const NODETYPE&);

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List()
    : firstPtr(0),
    lastPtr(0)
{
    // empty body

} // end List constructor

// Copy constructor
template< class NODETYPE >
List< NODETYPE >::List(const List& l2)
    : firstPtr(0),
    lastPtr(0)
{

    if (l2.isEmpty()) return;

    ListNode< NODETYPE >* firstPtrL2;  // pointer to first node L2
    ListNode< NODETYPE >* lastPtrL2;   // pointer to last node L2
    firstPtrL2 = l2.firstPtr;
    lastPtrL2 = l2.lastPtr;
    ListNode< NODETYPE >* currentPtr = firstPtrL2;


    while (currentPtr != 0)
    {
        insertAtBack(currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }

} // end Copy constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
    if (!isEmpty()) {    // List is not empty
 //      cout << "Destroying nodes ...\n";

        ListNode< NODETYPE >* currentPtr = firstPtr;
        ListNode< NODETYPE >* tempPtr;

        while (currentPtr != 0)         // delete remaining nodes
        {
            tempPtr = currentPtr;

            // commented out the output -- no need to print what we are deallocating
            //         cout << tempPtr->data << '\n';  

            currentPtr = currentPtr->nextPtr;
            delete tempPtr;

        }

    }

    //   cout << "All nodes destroyed\n\n";

} // end List destructor

// insert node at front of list
template< class NODETYPE >
List< NODETYPE >& List< NODETYPE >::operator=(const List& l2)
{
    if (this != &l2)
    {
        while (!this->isEmpty())
            this->removeFromFront(this->firstPtr->data);

        if (l2.isEmpty()) return *this;

        ListNode< NODETYPE >* firstPtrL2;  // pointer to first node L2
        ListNode< NODETYPE >* lastPtrL2;   // pointer to last node L2
        firstPtrL2 = l2.firstPtr;
        lastPtrL2 = l2.lastPtr;
        ListNode< NODETYPE >* currentPtr = firstPtrL2;

        while (currentPtr != 0)
        {
            insertAtBack(currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

    }
    return *this;

}


// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront(const NODETYPE& value)
{
    ListNode< NODETYPE >* newPtr = getNewNode(value);

    if (isEmpty())  // List is empty
        firstPtr = lastPtr = newPtr;

    else {  // List is not empty
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;

    } // end else

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack(const NODETYPE& value)
{
    ListNode< NODETYPE >* newPtr = getNewNode(value);

    if (isEmpty())  // List is empty
        firstPtr = lastPtr = newPtr;

    else {  // List is not empty
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;

    } // end else

} // end function insertAtBack


// insert node at Middle of list
template< class NODETYPE >
void List< NODETYPE >::insertMiddle(NODETYPE& value, int position)
{

    ListNode< NODETYPE >* newPtr = getNewNode(value);

    if (position <= 0) position = 1;

    if (isEmpty())  // List is empty
    {
        firstPtr = lastPtr = newPtr;
    }
    else if (position == 1)
    {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }
    else
    {  // List is not empty

        int pos = 2;
        bool inserted = false;
        ListNode< NODETYPE >* tmpPtr = firstPtr; // temp pointer
        ListNode< NODETYPE >* currentPtr = firstPtr; // temp pointer

        while (!inserted && currentPtr->nextPtr != 0)
        {

            currentPtr = currentPtr->nextPtr;

            if (pos == position) {
                newPtr->nextPtr = currentPtr;
                tmpPtr->nextPtr = newPtr;
                inserted = true;
            }

            tmpPtr = currentPtr;
            pos++;
        }

        if (!inserted) {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
        }

    } // end else

} // end function insertMiddle

// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront(NODETYPE& value)
{
    if (isEmpty())  // List is empty
        return false;  // delete unsuccessful

    else {
        ListNode< NODETYPE >* tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;

        value = tempPtr->data;  // data being removed
        delete tempPtr;

        return true;  // delete successful

    } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack(NODETYPE& value)
{
    if (isEmpty())
        return false;  // delete unsuccessful

    else {
        ListNode< NODETYPE >* tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else {
            ListNode< NODETYPE >* currentPtr = firstPtr;

            // locate second-to-last element
            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;

            lastPtr = currentPtr;
            currentPtr->nextPtr = 0;

        } // end else

        value = tempPtr->data;
        delete tempPtr;

        return true;  // delete successful

    } // end else

} // end function removeFromBack

// delete node from middle of list
template< class NODETYPE >
bool List< NODETYPE >::removeMiddle(NODETYPE& value, int position)
{
    if (isEmpty())
        return false;  // delete unsuccessful

    if (position <= 0)
        return false;  // delete unsuccessful

    if (position == 1)
    {
        ListNode< NODETYPE >* tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;

        value = tempPtr->data;  // data being removed
        delete tempPtr;

        return true;  // delete successful

    }
    else {

        int pos = 2;
        bool removed = false;
        ListNode< NODETYPE >* tmpPtr = firstPtr; // temp pointer
        ListNode< NODETYPE >* currentPtr = firstPtr; // temp pointer


        while (!removed && currentPtr->nextPtr != 0)
        {

            currentPtr = currentPtr->nextPtr;

            if (pos == position) {
                tmpPtr->nextPtr = currentPtr->nextPtr;
                value = currentPtr->data;
                if (tmpPtr->nextPtr == 0)  lastPtr = tmpPtr;
                removed = true;

            }

            tmpPtr = currentPtr;
            pos++;
        }

        delete tmpPtr;

        if (!removed) return false;  // delete unsuccessful

        return true;  // delete successful

    }
}



// is List empty?
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
    return firstPtr == 0;

} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE >* List< NODETYPE >::getNewNode(
    const NODETYPE& value)
{
    return new ListNode< NODETYPE >(value);

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
    if (isEmpty()) {
        cout << "The list is empty\n\n";
        return;

    } // end if

    ListNode< NODETYPE >* currentPtr = firstPtr;

    cout << "The list is: ";

    while (currentPtr != 0) {
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;

    } // end while

    cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
