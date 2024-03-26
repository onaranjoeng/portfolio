#include "date.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool status = false;
    int comparestatus = 0;

    Date d1;		            // should default to 1/1/2000
    Date d2(5, 18, 2002);    
    Date d3(15, 15, 1500);		// give error
    Date d4(2, 29, 2000);		
    Date d5(12, 29, 2005);		

    cout << "Date d1 is: ";   // display dates to the screen
    d1.Show();
    cout << "Date d2 is: ";   // shoes the default setting
    d2.Show();
    cout << "Date d3 is: ";
    d3.Show();
    cout << "Date d4 is: ";
    d4.Show();

    cout << endl;

    d1.Input();			        // Allow user to enter a date for d1
    cout << "\nDate typed in is: ";
    d1.Show();                  // show user input

    d1.SetFormat('K');		    // attempt to change format but invalid input
    cout << "\nThe new date is: ";
    d1.Show();                  // print d1 -- should stay in deafult setting

    d1.SetFormat('T');		    // change format of d1 to "two digit" format
    cout << "\nDate d1 in two digits is: ";
    d1.Show();                  // print d1 -- should show now in two digit format

    d1.SetFormat('L');		    // change format of d1 to "Long" format
    cout << "\nDate d1 in long form is: ";
    d1.Show();                  // print d1 -- should show now in long format

    d1.SetFormat('J');		    // change format of d1 to "Julian" format
    cout << "\nDate d1 in Julian form is: ";
    d1.Show();                  // print d1 -- should show now in Julian format
   
    d5.Increment(10);
    cout << "\nDate d3 increased by 10 days is: "; // increasing days by 7
    d5.Show();

    cout << endl;

    comparestatus = d1.Compare(d2);      // Returns 1 if parameter object (d1) comes first
    cout << comparestatus << endl;

    comparestatus = d2.Compare(d1);    // returns -1 if calling object (d2) comes first
    cout << comparestatus << endl;

    comparestatus = d1.Compare(d4);      // returns 0 if dates are the same 
    cout << comparestatus << endl;




return 0;

}
