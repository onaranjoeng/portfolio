#include <string>
#include <iostream>
#include "List.h"

using namespace std;
using namespace cop4530;

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //******************************************************************
    // class: const_iterator
    //******************************************************************
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    // default zero parameter constructor
    template<typename T>
    inline List<T>::const_iterator::const_iterator()
    {
        current = nullptr;
    }

    // return a reference to the corresponding element in the list. 
    template<typename T>
    inline T& List<T>::const_iterator::retrieve() const
    {
        return current->data;
    }

    // protected constructor
    // Set pointer current to the given node pointer p.
    template<typename T>
    inline List<T>::const_iterator::const_iterator(Node* p)
    {
        current = p;
    }

    // operator*() to return element
    template<typename T>
    const T& List<T>::const_iterator::operator*() const
    {
        return retrieve();
    }

    ////////////////////////////////////////////////////////////
    // Prefix and postfix increment and decrement operators.
    ////////////////////////////////////////////////////////////

    // Prefix increment operator.
    template<typename T>
    typename List<T>::const_iterator& List<T>::const_iterator::operator++()
    {
        current = current->next;
        return *this;
    }

    // PostFix increment operator.
    template<typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
    {
        List<T>::const_iterator temp_iterator = *this;
        ++(*this);
        return temp_iterator;
    }

    // Prefix decrement operator.
    template<typename T>
    typename List<T>::const_iterator& List<T>::const_iterator::operator--()
    {
        current = current->prev;
        return *this;
    }

    // PostFix decrement operator.
    template<typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
    {
        List<T>::const_iterator temp_iterator = *this;
        --(*this);
        return temp_iterator;
    }

    ///////////////////////////////////////////////////////////////
    //Two iterators are equal if they refer to the same element.
    ///////////////////////////////////////////////////////////////

    // equal  
    template<typename T>
    inline bool List<T>::const_iterator::operator==(const List<T>::const_iterator& rhs) const
    {
        bool bool_rslt;
        bool_rslt = rhs.current == current;
        return bool_rslt;
    }

    // Not equal 
    template<typename T>
    inline bool List<T>::const_iterator::operator!=(const List<T>::const_iterator& rhs) const
    {
        bool bool_rslt;
        bool_rslt = rhs.current != current;
        return bool_rslt;
    }

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //******************************************************************
    // Nested iterator class
    //******************************************************************
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    // default zero-parameter constructor.
    template<typename T>
    inline List<T>::iterator::iterator()
    {
        // Nothing TO DO
    }

    // one-parameter constructor
    template<typename T>
    inline List<T>::iterator::iterator(Node* p) : List<T>::const_iterator::const_iterator(p) {};
    

    template<typename T>
    inline T& List<T>::iterator::operator*()
    {
        return List<T>::const_iterator::retrieve();
    }


    //Returns a reference to the corresponding element in the list by calling retrieve() member function. 
    template<typename T>
    const T& List<T>::iterator::operator*() const
    {
        return List<T>::const_iterator::operator*();
    }

    // Prefix increment operator.
    template<typename T>
    typename List<T>::iterator& List<T>::iterator::operator++()
    {
        this->current = this->current->next;
        return *this;
    }

    // PostFix increment operator.
    template<typename T>
    typename List<T>::iterator List<T>::iterator::operator++(int)
    {
        List<T>::iterator temp_iterator = *this;
        ++(*this);
        return temp_iterator;
    }

    // Prefix decrement operator.
    template<typename T>
    typename List<T>::iterator& List<T>::iterator::operator--()
    {
        this->current = this->current->prev;
        return *this;
    }

    // PostFix decrement operator.
    template<typename T>
    typename List<T>::iterator List<T>::iterator::operator--(int)
    {
        List<T>::iterator temp_iterator = *this;
        --(*this);
        return temp_iterator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
    // ***************************************************************************
    // CLASS: List
    // ***************************************************************************
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////


    // Default zero-parameter constructor. Call init() to 
    // initialize list member variables
    template<typename T>
    inline List<T>::List()
    {
        init();
    }

    //  Copy constructor. Create the new list using elements 
    // in existing list rhs.
    template<typename T>
    inline List<T>::List(const List& rhs)
    {
        init();
        for (auto& x : rhs)
            push_back(x);

    }

    // move constructor.
    template<typename T>
    inline List<T>::List(List<T> && rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    // Construct a list with num elements, all initialized with value val.
    template<typename T>
    inline List<T>::List(int num, const T& val)
    {
        init();
        for (int i = 0; i < num; i++) push_back(val);

    }

    // Construct a List with elements from another list between start and end.
    // Including the element referred to by the start iterator, but not the end
    // iterator, that is [start, end).
    template<typename T>
    inline List<T>::List(List<T>::const_iterator start, List<T>::const_iterator end)
    {
        init();
        while (true) {
            push_back(start.current->data);
            ++start;
            if (start == end) break;
        }

    }

    // construct a List with elements from the initializer list that is passed in. 
    // Note that this will allow declarations like this:
    // List myList{ 2, 4, 6, 8, 10, 12, 14, 16 };
    template<typename T>
    inline List<T>::List(std::initializer_list<T> iList)
    {
        init();
        for (auto& x : iList)
            push_back(x);
    }


    // destructor. You should properly reclaim all dynamically allocated memory.
    // Should call clear().
    template<typename T>
    inline List<T>::~List()
    {
        clear();
        delete head;
        delete tail;

    }


    // copy assignment operator
    template<typename T>
    const List<T>& List<T>::List::operator=(const List<T>& rhs)
    {
        List<T> temp_list = rhs;
        swap(*this, temp_list);
        return *this;
    }

    // move assignment operator
    //List& operator=(List&& rhs);
    template<typename T>
    inline List<T>& List<T>::List::operator=(List<T>&& rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
    }

    // sets list to the elements of the initializer_list
    template<typename T>
    inline List<T>& List<T>::List::operator=(std::initializer_list<T> iList)
    {
        init();
        for (auto& x : iList)
            push_back(x);
        return *this;
    }

    // return the number of elements in the List.
    template<typename T>
    inline int List<T>::size() const
    {
        return theSize;
    }

    //  return true if no element is in the list; otherwise, return false.
    template<typename T>
    inline bool List<T>::empty() const
    {
        if (size() == 0)
            return true;
        else
            return false;
    }

    // delete all the elements in the list.
    template<typename T>
    inline void List<T>::clear()
    {
        while (!empty())
            pop_front();
    }

    // everse the order of the elements in the list. That is, the original
    // first element becomes the last, while the original last becomes the first.
    template<typename T>
    inline void List<T>::reverse()
    {
        // exit if the list is empty
        if (head == nullptr)
            return;

        // this swaps head and tail
        Node* temp = head;
        head = tail;   // head is now tail
        tail = temp;  // tail is now head

        // create temp to hold new head
        Node* temp_node = head;
        // reverse nodes in between head and tail while back is not empty
        while (temp_node != nullptr) {
            temp = temp_node->prev;       // re use to make sure starts from front
            temp_node->prev = temp_node->next;
            temp_node->next = temp;
            temp_node = temp_node->next; // shift to next node
        }
    }

    // return reference to the first element in the list, respectively.
    template<typename T>
    inline T& List<T>::front()
    {
        if (empty())
        {
            cout << "List error: Front() called on empty list\n";
        }
        return *begin();
    }

    // return reference to the first element in the list, respectively.
    template<typename T>
    inline const T& List<T>::front() const
    {
        if (empty())
        {
            cout << "List error: Front() called on empty list\n";
        }
        return *begin();
    }

    // return reference to the last element in the list, respectively.
    template<typename T>
    inline T& List<T>::back()
    {
        if (empty())
        {
            cout << "List error: Back() called on empty list\n";
        }
        return *--end();
    }

    // return reference to the last element in the list, respectively.
    template<typename T>
    inline const T& List<T>::back() const
    {
        if (empty())
        {
            cout << "List error: Back() called on empty list\n";
        }
        return *--end();
    }

    //  insert the new object as the first element into the list, 
    //  and their move versions.
    template<typename T>
    inline void List<T>::push_front(const T& val)
    {
        insert(begin(), val);

    }

    template<typename T>
    inline void List<T>::push_front(T&& val)
    {
        insert(begin(), move(val));
    }

    //  insert the new object as the last element into the list, 
    //  and their move versions.
    template<typename T>
    inline void List<T>::push_back(const T& val)
    {
        insert(end(), val);
    }

    template<typename T>
    inline void List<T>::push_back(T&& val)
    {
        insert(end(), move(val));
    }

    // delete the first element in the list,
    template<typename T>
    inline void List<T>::pop_front()
    {
        erase(begin());
    }

    // delete the last element in the list,
    template<typename T>
    inline void List<T>::pop_back()
    {
        erase(--end());
    }

    // delete all nodes with value equal to val from the list.
    template<typename T>
    inline void List<T>::remove(const T& val)
    {
        for (List<T>::iterator temp_iterator = begin(); temp_iterator != end();)
        {
            if (temp_iterator.current->data == val)
                temp_iterator = erase(temp_iterator);
            else ++temp_iterator;
        }

    }

    //  delete all nodes for which pred returns true. 
    // PREDICATE is a template type, allowing a function object to be passed. 
    // (i.e. a true/false condition/function can be passed in via the functor).
    template<typename T>
    template<typename PREDICATE>
    inline void List<T>::remove_if(PREDICATE pred)
    {
        for (List<T>::iterator temp_iterator = begin(); temp_iterator != end();)
        {
            if (pred(*temp_iterator))
                temp_iterator = erase(temp_iterator);
            else ++temp_iterator;
        }


    }

    // print all elements in the list, using character ofc as the deliminator 
    // between elements in the list.
    template<typename T>
    inline void List<T>::print(std::ostream& os, char ofc) const
    {
        // create i to loop through list 
        const_iterator i;
        if (ofc == '\0')
            for (i = begin(); i != end(); ++i)
                os << *i;
        else
            for (i = begin(); i != end(); ++i)
                os << *i << ofc;
    }

    //  return iterator to the first element in the list. It should return 
    // the tail on an empty list.  
    template<typename T>
    inline typename List<T>::iterator List<T>::begin()
    {
        if (empty())
            return { tail };
        else
            return { head->next };
    }

    template<typename T>
    inline typename List<T>::const_iterator List<T>::begin() const
    {
        if (empty())
            return { tail };
        else
            return { head->next };
    }

    // return iterator to the end marker of the list (tail).  
    // The tail, in this implementation, should not point to a valid record but 
    // rather just the end-marker of the list.
    template<typename T>
    inline typename List<T>::iterator List<T>::end()
    {
        return { tail };
    }

    template<typename T>
    inline typename List<T>::const_iterator List<T>::end() const
    {
        return { tail };
    }

    // insert value val ahead of the node referred to by itr; and its move version
    template<typename T>
    inline typename List<T>::iterator List<T>::insert(List<T>::iterator itr, const T& val)
    {
        Node* p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{ move(val), p->prev, p } };
    }

    template<typename T>
    inline typename List<T>::iterator List<T>::insert(List<T>::iterator itr, T&& val)
    {
        // had to add std:: to move function for it to work
        Node* p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{ std::move(val), p->prev, p } };
    }

    // delete node referred to by itr. The return value is an iterator to the 
    // following node.
    template<typename T>
    inline typename List<T>::iterator List<T>::erase(List<T>::iterator itr)
    {
        // delete node referred to by itr (from book)
        Node* p = itr.current;
        List<T>::iterator retVal{ p->next };
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;

        return retVal;
    }

    //  delete all nodes between start and end (including start but not end),
    // that is, all elements in the range [start, end).
    template<typename T>
    inline typename List<T>::iterator List<T>::erase(List<T>::iterator start, List<T>::iterator end)
    {
        //  delete all nodes between start and end (from book)
        for (iterator itr = start; itr != end; )
            itr = erase(itr);

        return end;
    }

    //  Should be an empty list , 
    // size=0, with a single node that points to the end marker. 
    template<typename T>
    inline void List<T>::init()
    {
        //  initialize the member variables of list. (From book)
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }


    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
    // ***************************************************************************
    // Helper Functions
    // ***************************************************************************
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////


    //template<typename T>
    //void swap(List<T>& x, List<T>& y)  // helper function for the move and copy constructor/operator
    //{
     //   List<T> tmp;
     //   tmp = x;
     //   x = y;
     //   y = tmp;

    //}
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
    // ***************************************************************************
    // overloading comparison operators
    // ***************************************************************************
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    

