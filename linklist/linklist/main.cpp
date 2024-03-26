#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "linklist.h"


void OpenFile(ifstream& f);
void PropogateTheList(ifstream& f, LinkList& ML);
using namespace std;
// ***************************************************************************
// * Name: main                                                              *
// * Description: The main routine to test the Assignment #8 Link List       *
// *   assignment.   Do not alter this source code other than to comment     *
// *   out the member functions that you have not implemented yet.  Details  *
// *   on the test:                                                          *
// *  1. Declare a link list using the Default Constructor.                  *
// *  2. Test to see if the list is empty.                                   *
// *  3. Open the file.                                                      *
// *  4. Use Propogate to read the file and insert records into the list.    *
// *  5. Use Size to see how many records were inserted.                     *
// *  6. Close the file.                                                     *
// *  7. Check to make sure the list is not empty.                           *
// *  8. Find a specific record.                                             *
// *  9. Delete the record that you found.                                   *
// * 10. Make sure you cannot find that record.                              *
// * 11. Print the report.. Should use List() and CountPie() and             *
// * 12.   CountCake() methods.                                              *     
// * Author: Dr. David A. Gaitros                                            *
// * Date: October 3st, 2019 ( last modified )                               *
// * Copywright:  2019 Dr. David A. Gaitros                                  *
// ***************************************************************************
int main(void)
{
    ifstream inputfile;
    LinkList MyList;
    if (MyList.Empty()) cout << "File should be empty..passed Empty() Test" << endl;
    else cout << "Structure should be empty .. Failed Empty() Test" << endl;
    OpenFile(inputfile);
    PropogateTheList(inputfile, MyList);
    cout << "After Propogate number of records is: " << MyList.Size() << endl;
    inputfile.close();
    if (!MyList.Empty()) cout << "File should not  be empty..passed Empty() Test" <<
        endl;
    else cout << "Structure should be not empty .. Failed Empty() Test" <<
        endl;
    if (MyList.Find(67)) cout << "Found Record #67" << endl;
    if (MyList.Delete()) cout << "Deleting Record #67" << endl;
    else cout << "Delete failed the test" << endl;
    if (!MyList.Find(67)) cout << "Did not find Record #67" << endl;
    MyList.Print();
    return 0;
}
// ***************************************************************************
// * Name: OpenFile                                                          *
// * Description:  Asks the user for name name of a file and opens it.       *
// *   Returns the pointer to the file as a parameter.                       *
// * Author: Dr. David A. Gaitros                                            *
// * Date: October 21st, 2019                                                *
// ***************************************************************************
void OpenFile(ifstream& inputfile)
{
    static string filename;
    cout << "Enter a valid input file name: ";
    cin >> filename;
    inputfile.open(filename);
    while (!inputfile.is_open())
    {
        cout << "Invalid filename, re-enter->";
        cin >> filename;
        inputfile.open(filename);
    }
}
// ***************************************************************************
// * Name:PropogateTheList                                                   *
// * Description: Accepts a file stream parameter and a LinkList parameter   *
// *   and reads a record one at a time and inserts into the list calling    *
// *   Insert() method from the LinkList class.                              *
// * Author: Dr. David A. Gaitros                                            *
// * Date: October 31st, 2019                                                *
// ***************************************************************************
void PropogateTheList(ifstream& f, LinkList& ML)
{
    static PieCake_struct* record;
    record = new PieCake_struct;
    f >> record->id >> record->lname >> record->fname >> record->mi >> record->sex >>
        record->pORc;
    while (!f.eof())
    {
        ML.Insert(record);
        record = new PieCake_struct;
        f >> record->id >> record->lname >> record->fname >> record->mi >> record->sex >>
            record->pORc;
    }

}