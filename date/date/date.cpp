// By Oscar Naranjo
// May 25, 2022

#include "date.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool checkDate(int m, int d, int y);



// set deafult settings
Date::Date(int m, int d, int y) {

    format = 'D';

    if ((d < 1 || d > 31) || (m < 1 || m > 12) || (y < 1582 || y > 3000))
    {
        d = 1;
        m = 1;
        y = 2000;
    }

    day = d;
    month = m;
    year = y;
}

// allow user input
void Date::Input() {

    string dateInput;
    size_t posSlash;
    string d, m, y;

    // input message
    cout << "Please enter in a date in the following format(M/D/Y): ";

    do {

    cin >> dateInput;
    posSlash = dateInput.find('/', 0);

    m = dateInput.substr(0, posSlash );

    dateInput = dateInput.substr(posSlash + (size_t) 1);
    posSlash = dateInput.find('/', 0);

    d = dateInput.substr(0, posSlash);

    y = dateInput.substr(posSlash + (size_t)1);

    } while (!checkDate(stoi(m), stoi(d), stoi(y)));

    // save string to int
    day = stoi(d);
    month = stoi(m);
    year = stoi(y);

}

// date validation
bool checkDate(int m, int d, int y) {

    int datValidation;

    // error message if date entered is before October 1st, 1582
    if (m <= 10 && d >= 1 && y <= 1582) {
        cout << "Date must be later than October 1st, 1582. Please try again: ";
        return false;
    }
    // error message
    else if (m < 1 || m > 12) {
        cout << "Not a valid date, please try again: ";
        return false;
    }

    else 
    {
        switch (m)
        {
        case 2:
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                datValidation = 29;
            else
                datValidation = 28;
            break;
        case 4:
            datValidation = 30;
            break;
        case 6:
            datValidation = 30;
            break;
        case 9:
            datValidation = 30;
            break;
        case 11:
            datValidation = 30;
            break;
        default:
            datValidation = 31;
            break;
        }

        // error message
        if (d < 1 || d > datValidation) {
            cout << "Not a valid date, please try again: ";
            return false;
        }
        // error message
        if (y < 1582 || y > 3000) {
            cout << "Not a valid date, please try again: ";
            return false;
        }
        return true;
    }
   }


// validates if date is correct
bool Date::Set(int m, int d, int y) {

    int datValidation;

    if (m < 1 || m > 12) {
        return false;
    }
    else
    {
        switch (m)
        {
            // validation for leap year in order to satisfy days in Feb
        case 2:
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                datValidation = 29;
            else
                datValidation = 28;
            break;
            // set the months with 30 days (April, June, September, and November) and others with 31 days
        case 4:
            datValidation = 30;
            break;
        case 6:
            datValidation = 30;
            break;
        case 9:
            datValidation = 30;
            break;
        case 11:
            datValidation = 30;
            break;
        default:
            datValidation = 31;
            break;
        }

        // make sure date entered is correct 
        if (d < 1 || d > datValidation) {
            return false;
        }
        // again check for year to be after 1582
        if (y < 1582 || y > 3000) {
            return false;
        }
    }
    //saves values
    day = d;
    month = m;
    year = y;

    return true;
}

// show function with different options
void Date::Show() {

    int newYear;
    int dayCount = 0;
    int Julian = 0;
    string dayCero, monthCero, yearCero;
    string monthString = "";

    switch (format)
    {
    case 'D': // Default format
        cout << month << "/" << day << "/" << year << endl;
        break;

    case 'T': // Two Digit format

        dayCero = to_string(day);
        if (dayCero.length() == 1) dayCero = "0" + dayCero;

        monthCero = to_string(month);
        if (monthCero.length() == 1) monthCero = "0" + monthCero;

        newYear = year % 100;

        yearCero = to_string(newYear);
        if (yearCero.length() == 1) yearCero = "0" + yearCero;

        cout << monthCero << "/" << dayCero << "/" << yearCero << endl;
        break;

    case 'L':  // Long format

        switch (month)
        {
        case 1:
            monthString = "Jan";
            break;
        case 2:
            monthString = "Feb";
            break;
        case 3:
            monthString = "Mar";
            break;
        case 4:
            monthString = "Apr";
            break;
        case 5:
            monthString = "May";
            break;
        case 6:
            monthString = "June";
            break;
        case 7:
            monthString = "July";
            break;
        case 8:
            monthString = "Aug";
            break;
        case 9:
            monthString = "Sept";
            break;
        case 10:
            monthString = "Oct";
            break;
        case 11:
            monthString = "Nov";
            break;
        case 12:
            monthString = "Dec";
            break;
        default:
            break;
        }
        cout << monthString << " " << day << ", " << year << endl;
        break;

    case 'J':  // Julian format

        switch (month)
        {
        case 1:
            Julian = day; //31 days max
            break;
        case 2: 
            if (day < 29)
            Julian = day + 31; // 60 days max
            break;
        case 3:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day; // 91 days max
            break;
        case 4:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31; // 122 days max
            break;
        case 5:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30; // 153 days max
            break;
        case 6:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31; //184 days max
            break;
        case 7:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30; // 214 days max
            break;
        case 8:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30 + 31; // 245 days max
            break;
        case 9:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30 + 31 + 31; // 276 days max
            break;
        case 10:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30 + 31 + 31 + 30; // 306 days max
            break;
        case 11:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31; // 337 days max
            break;
        case 12:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayCount = 29 + 31;
            else
                dayCount = 28 + 31;
            Julian = dayCount + day + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; // 366 days max

            break;
        default:
            break;
        }
        cout << Julian << ", " << year << endl;
        break;



    default:
        break;
    }  
}

// set format to different ways to type date
bool Date::SetFormat(char f) {


    //    'D' = Default format
    //    'T' = Two - Digit format
    //    'L' = Long format
    //    'J' = Julian format

    if (f != 'D' && f != 'T' && f != 'L' && f != 'J')
        return false;

    format = f;

    return true;
}

int Date::GetMonth() {

    return month;
}

int Date::GetDay() {

    return day;
}

int Date::GetYear() {

    return year;
}

// compares two different dates and a -1, 0, or 1
int Date::Compare(const Date& d) {

   
    string dateA, dateB;

    string dayCero, monthCero;

    dayCero = to_string(day);
    if (dayCero.length() == 1) dayCero = "0" + dayCero;
    
    monthCero = to_string(month);
    if (monthCero.length() == 1) monthCero = "0" + monthCero;

    dateA = to_string(year) + monthCero + dayCero;

    dayCero = to_string(d.day);
    if (dayCero.length() == 1) dayCero = "0" + dayCero;

    monthCero = to_string(d.month);
    if (monthCero.length() == 1) monthCero = "0" + monthCero;

    dateB = to_string(d.year) + monthCero + dayCero;

    if (dateA == dateB) return 0;

    if (dateA > dateB) return 1;

    return -1;

}

// function for increment function
int Date::EndDayMonth(int m) {

    int dateValidation;

    switch (m)
    {
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            dateValidation = 29;
        else
            dateValidation = 28;
        break;
    case 4:
        dateValidation = 30;
        break;
    case 6:
        dateValidation = 30;
        break;
    case 9:
        dateValidation = 30;
        break;
    case 11:
        dateValidation = 30;
        break;
    default:
        dateValidation = 31;
        break;
    }

    return dateValidation;

}

// function to increase days in the date and therefore the overall date
void Date::Increment(int numDays) {

    int dateValidation = EndDayMonth(month);
    int newDay;

    newDay = day + numDays; 
    if (newDay > dateValidation) {

        day = newDay - dateValidation; 
        month++; 
        if (month == 13)
        {
            month = 1;
            year++;
        }
    }
    else day = newDay;
}
