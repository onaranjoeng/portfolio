
#include <iostream>
#include <iomanip>
using namespace std;

void displayMenu(int&); // FUNCTION FOR USER INPUT
void insertBefore(double num[], double newNum, double findNum, int& size); // FUNCTION TO INSERT ANOTHER NUMBER
void removeAll(double num[], int& size); // function to remove a number from the array
void printArray(double num[], int size); // function to print the array
void cyclicRightShift(double num[], int size); // function to shift numbers to the left
int numSearch(double num[], double findNum, int size); // function to find number in array

const int CAPACITY = 100; // constant size of the array

int main() {

    double num[CAPACITY] = { 0 };// array for number of elements set to zero
    int choice, size; // variables
    double findNum, newNum;

    do {
        cout << "Enter the number of elements you want to enter (Max 100): ";
        cin >> size; // saves size of array
    } while (size < 0 || size >= 100); // restrictions 0-100

    cout << "Enter " << size << " numbers" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];  // stores each number into array
    }

    do
    {
        displayMenu(choice); // displays the menu

        if (choice == 1)
        {
            cout << "Enter the number: ";
            cin >> newNum;
            cout << "Enter the number to be inserted before: ";
            cin >> findNum;
            cout << "Element Inserted.\n";
            insertBefore(num, newNum, findNum, size);
        }
        if (choice == 2)
        {
            removeAll(num, size);
        }
        if (choice == 3)
        {
            printArray(num, size);
        }
        if (choice == 4)
        {
            cyclicRightShift(num, size);
        }
       
    } while (choice != 5); // quits program
    return 0;
}


// FUNCTION FOR USER INPUT MENU
void displayMenu(int& choice)
{
    // OPTIONS GIVEN TO THE USER
    cout << "1) Insert an element\n"
        "2) Remove an element\n"
        "3) Print the array\n"
        "4) Cyclic Right shift\n"
        "5) Exit\n";
    do {
        cout << "Select an option: ";
        cin >> choice; // user input
        if (choice <= 0 || choice > 5)
        {
            cout << "That is not an option, please try again.\n";
        }
    } while (choice <= 0 || choice > 5); // restrictions

    if (choice == 5)
    {
        cout << "Goodbye!" << endl; // exit message
    }
}

void printArray(double num[], int size) {

    cout << "The array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << num[i] << " "; // prints the numbers inputted by user
    }
    cout << "\n\n";
}

void insertBefore(double num[], double newNum, double findNum, int& size) {

    int pos = numSearch(num, findNum, size);
    int newSize = 0;
    if (pos == -1) return;

    size++; 
    double tempNum[CAPACITY] = { 0 }; 

    for (int i = 0; i < size; i++) { 

        tempNum[newSize] = num[i];

        if (i == pos) {
            tempNum[newSize - 1] = newNum; // creates a new array with new values  
        }

        newSize++; 

    }

    for (int i = 0; i < CAPACITY; i++)
        num[i] = tempNum[i]; // copies array into new one

}

int numSearch(double num[], double findNum, int size) {

    int pos = -1; // set to an impossible numer
    for (int i = 0; i < size; i++)
    {
        if (num[i] == findNum)
            pos = i; // if number is equal to the value in array save to i
    }
    return pos;
}

void removeAll(double num[], int& size) {

    double key;
    int newSize = 0;
    double tempNum[CAPACITY] = { 0 }; // array for number of elements set to zero
    cout << "Enter the element: ";
    cin >> key; // stores input

    for (int i = 0; i < size; i++) { // loops through array
        if (num[i] != key) {
            tempNum[newSize] = num[i]; // creates a new array with new values
            newSize++; // adds to size
        }
    }

    for (int i = 0; i < CAPACITY; i++)
        num[i] = tempNum[i]; // copies array into new one

    size = newSize; 
    
    cout << "element deleted." << endl;

}

void cyclicRightShift(double num[], int size) {

    double temp = num[0]; // temporarily sets number in position zero to temp

    for (int i = 0; i < size; i++)
    cout << "Elements shifted.\n\n";
}