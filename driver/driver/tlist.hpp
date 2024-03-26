#include <string>
#include <iostream>
#include <utility>


using namespace std;
// **********************************************************
// Functions for class TList                                *
// **********************************************************

// Create empty linked list
template<typename T>
inline TList<T>::TList()
{
	first = last = nullptr;
	size = 0;

}

// Create list with num copies of val
template<typename T>
inline TList<T>::TList(T val, int num)
{
	size = 0;
	first = nullptr;
	last = nullptr;

	for (int i = 0; i < num; i++)
		InsertBack(val);

}

// Destructor
template<typename T>
inline TList<T>::~TList()
{
	Clear();          // delete size as well
	delete first;
	delete last;

}

// Copy constructor
template<typename T>
inline TList<T>::TList(const TList& L)
{
	Node<T>* temp;
	temp = L.first;
	while (temp != nullptr) {
		InsertBack(temp->data);
		temp = temp->next;
	}
	delete temp;

}

// Move constructor
template<typename T>
inline TList<T>::TList(TList&& L)
{
	first = last = nullptr;
	size = 0;

	swap(*this, L);
	
}

// Checks to see whether list is empty
template<typename T>
inline bool TList<T>::IsEmpty() const
{
	if (GetSize() == 0) return true;
	else
		return false;
}

// Clear out list, reset to empty
template<typename T>
inline void TList<T>::Clear()
{
	while (!IsEmpty())
		RemoveFront();
}

// Return the size of the list
template<typename T>
inline int TList<T>::GetSize() const
{
	return size;
}

// Insert data d as first element
template<typename T>
inline void TList<T>::InsertFront(const T& d)
{
	Node<T>* newNode = new Node<T>(d); // create newNode and put in the data


	if (first != nullptr)
		first->prev = newNode;

	if (last == nullptr)
		last = newNode;  // pointer to last node in list

	newNode->next = first;
	newNode->prev = nullptr;
	first = newNode;

	size++;
}

// Insert data d as last element
template<typename T>
inline void TList<T>::InsertBack(const T& d)
{
	Node<T>* newNode = new Node<T>(d); // create a new node

	if (IsEmpty()) {
		first = newNode;
		last = newNode;  
		size++;      // if empty insert back increase size
	}
	else
	{
		if (first == nullptr)  
			first = newNode;   

		if (last != nullptr)
			last->next = newNode;  // pointer to last node in list

		newNode->next = nullptr;
		newNode->prev = last;
		last = newNode;

		size++;
	}
}

// Remove first element of list
template<typename T>
inline void TList<T>::RemoveFront()
{
	if (!IsEmpty()) {
		first = first->next;

		if (first == nullptr) {
			first = last = nullptr;
			size = 0;
		}
		else {
			first->prev = nullptr;
			size--;
		}
	}

}

// Remove last element of list
template<typename T>
inline void TList<T>::RemoveBack()
{

	if (!IsEmpty()) {
		Node<T>* temp = last;
		last = last->prev;
		last->next = nullptr;
		delete temp;
		size--;
	}

}

// Return first element of list
template<typename T>
inline T& TList<T>::GetFirst() const
{
	if (IsEmpty()) return dummy;
	else
		return first->data;
}

// Return last element of list
template<typename T>
inline T& TList<T>::GetLast() const
{
	if (IsEmpty()) return dummy;
	else
		return last->data;
}

// Return iterator to first item
template<typename T>
inline TListIterator<T> TList<T>::GetIterator() const
{
	TListIterator<T>* iterator = new TListIterator<T>();;

	if (IsEmpty())
		return *iterator;

	iterator->ptr = first;
	return *iterator;
}

// Return iterator to last item
template<typename T>
inline TListIterator<T> TList<T>::GetIteratorEnd() const
{
	TListIterator<T>* iterator = new TListIterator<T>();

	if (IsEmpty())
		return *iterator;

	iterator->ptr = last;
	return *iterator;

}

//  Insert data element d just before item at pos position
template<typename T>
inline void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
	Node<T>* newInsert = new Node<T>(d);
	Node<T>* p = pos.ptr;


	if (IsEmpty())
	{
		first = newInsert;
		last = newInsert;
		size++;
		return;
	}

	size++;

	if (pos.ptr == nullptr) {
		newInsert->prev = last;
		last->next = newInsert;
		newInsert->next = nullptr;
		last = newInsert;
	}
	else {

		if (pos.ptr->prev == nullptr) {
			first = newInsert;
			newInsert->prev = nullptr;
			newInsert->next = p;
		}
		else {
			newInsert->prev = p->prev;
			newInsert->next = p->prev->next;
			p->prev->next = newInsert;
			p->prev = newInsert;
		}
	}



}

// Remove data item at position pos. Return iterator to the item.                                          * 
// that comes after the one being deleted
template<typename T>
inline TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
	if (IsEmpty()) { // dont remove
		return pos;
	}
	else {
		if (pos.ptr == nullptr) { // remove back
			RemoveBack();
			pos.ptr = last;
		}
		else { 
			Node<T>* p = pos.ptr; // new node
			p->prev->next = p->next;
			p->next->prev = p->prev;
			pos = pos.Next(); // move to next node
			delete p; // delete p
			size--;  // decrease size
		}
		return pos;
	}
}

// Print list contents in order, separated by given delimiter. 
template<typename T>
inline void TList<T>::Print(std::ostream& os, char delim) const
{
	if (IsEmpty())  // if its empty
		os << "It ismpty List!" << endl;
	else {
		static Node<T>* temp; // temp node
		temp = first;
		while (temp != nullptr) { // print while not at the end
			os << temp->data << delim;
			temp = temp->next;
		}
	}
}

// default constructor
template<typename T>
inline TListIterator<T>::TListIterator()
{
	ptr = nullptr;
}

// next item available?
template<typename T>
inline bool TListIterator<T>::HasNext() const
{
	if (ptr->next == nullptr) return false;
	else return true;

}

// previous item available?
template<typename T>
inline bool TListIterator<T>::HasPrevious() const
{
	if (ptr == nullptr || ptr->prev == nullptr) return false;
	else return true;

}

// advance to next item
template<typename T>
inline TListIterator<T> TListIterator<T>::Next()
{
	if (HasNext()) ptr = ptr->next;
	return *this;
}

// move to previous item
template<typename T>
inline TListIterator<T> TListIterator<T>::Previous()
{
	if (HasPrevious()) ptr = ptr->prev;
	return *this;

}

// return data element of current node
template<typename T>
inline T& TListIterator<T> ::GetData() const
{
	return ptr->data;
}
