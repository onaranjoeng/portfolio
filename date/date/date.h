// By Oscar Naranjo
// May 25, 2022

using namespace std;

class Date
{
public:

	//Date();   // default constructor
	Date(int m = 1, int d = 1, int y = 2000); // constructor with defaults if missing inputs

	bool Set(int m, int d, int y);			// function to set date
	bool SetFormat(char f);					// allow for the change of the date to another format
	int GetMonth();							// return month
	int GetDay();							// return day
	int GetYear();							// return year
	int Compare(const Date& d);				// comparing function for two dates
	int EndDayMonth(int m);					// function to be able to satisfy increment function
	void Increment(int numDays = 1);		// increase date by a set number of days, deafult to 1
	void Show();							// show function with switch case
	void Input();							// user input function
	
private:

	int day;		
	int month;		
	int year;		
	char format;

};

