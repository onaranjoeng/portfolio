// * Name: LinkList cpp ( linklist.cpp filename )                            *
// * Description: Implementation of of the LinkList class used for the       *
// *     the COP3330 class. Definition for a double linked list with dummy   *
// *     header and tail.  Stores last name, first name, middle initial,     *
// *     sex, and whether the person believes cheesecakeis pie or cake.      *
// *                                                                         *
// * Author: Oscar Naranjo                                                   *
// * Date: July 22, 2022 ( last modified )                                   *                                  *
// ***************************************************************************

#include "linklist.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

// Default constructor. 
LinkList::LinkList()
{
	head = new PieCake_struct;
	tail = new PieCake_struct;
	current = new PieCake_struct;
	count = 0;
	head->id=-1;
	head->mi = ' ';
	head->sex = ' ';
	head->pORc = ' ';
	head->fname = "         ";
	head->lname = "         ";
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	tail->id = 99999999;
    tail->fname = "ZZZZZZZZZ";
	tail->lname = "ZZZZZZZZZ";
	tail->mi = 'Z';
	tail->sex = ' ';
	tail->pORc = ' ';
}

// Destructor
LinkList::~LinkList()
{
	// go through the list and delete each record, head, tail, and count
	PieCake_struct* search;
	search = head->next;
	while (search != tail) {

		current = search;
		search = search->next;
		delete current;
		
	}
	delete head;
	delete tail;
	delete current;
}

// True = link list is empty, False otherwise
bool LinkList::Empty()
{
	if (head->next == tail) return true;
	else return false;
}

// Returns number of records minus head and tail
int LinkList::Size()
{
	return count;
}

// Looks for a record with the id,
bool LinkList::Find(const int idnumber)
{
	PieCake_struct* curr;
	curr = new PieCake_struct;
	curr = head;
	
	while (idnumber != curr->id && curr->next != nullptr)
	{

		curr = curr->next;
	}

	if (curr == tail) {
		current = nullptr;
		return false;
	}
	current = new PieCake_struct;
	current = curr;

	              // returns true if  found, false otherwise.

				  // Sets the current to the 
			      //   record found.
	              //   Sets current to null if not found. 
	return true;
}

// Inserts a record into the list. 
void LinkList::Insert(PieCake_struct* p)
{
	
	PieCake_struct* curr;
	curr = new PieCake_struct;
	curr = head;
	
	while (p->lname.compare(curr->lname) > 0  && curr->next != tail)
	{
		curr = curr->next;
	}
	current = new PieCake_struct;
	current = p; 
	
	current->prev = curr; 
	current->next = curr->next;
	current->next->prev = current;
	curr->next = current;

	count++;

}

// Deletes current record.
bool LinkList::Delete()
{
	
	if (current != head && current != tail && current != nullptr) {

		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = nullptr;


		count--;

		return true;
	} else 	return false;
	



	// Must use Find() to locate the record. 
}

// Prints the report..see example.
void LinkList::Print()
{
	
	PieCake_struct* curr;
	curr = new PieCake_struct;
	curr = head;


	cout << left << setw(7) << "ID" << setw(14) << "First Name" << setw(5) << "MI" << setw(12) << "Last Name" << setw(8) << "Sex" << setw(7) << "Answer" << endl;
	do {
		curr = curr->next;
		current = curr;
		List();

	} while (curr->next != tail);


	cout << "Total who thought cheesecake is pie: " << CountPie() << endl;
	cout << "Total who thought cheesecake is cake: " << CountCake() << endl;
	cout << "Total Number of records: " << count << endl;
	

}

// Lists current record to standard output.
void LinkList::List()
{
	if (count == 0) {
		cout << "Empty list" << endl;
		return;
	}
	

	cout << left << setw(7) << current->id << setw(14) << current->fname << setw(5) << current->mi << setw(12) << current->lname << setw(8) << current->sex << setw(7) << current->pORc << endl;
	

}


// Returns number of records that thought
int LinkList::CountPie()
{
	int count_pie = 0;

	// variable to track
	PieCake_struct* curr;
	curr = new PieCake_struct; 
	curr = head;
	//
	do {
		if (curr->pORc == 'P') count_pie++;
		curr = curr->next;
	} while (curr->next != nullptr);

	return count_pie;
}

// Returns the number of records that thought
int LinkList::CountCake()
{
	int count_cake = 0;

	// variable to track
	PieCake_struct* curr;
	curr = new PieCake_struct;
	curr = head;
	//
	do {

		if (curr->pORc == 'C') count_cake++;
		curr = curr->next;
	} while (curr->next != nullptr);

	return count_cake;
}
