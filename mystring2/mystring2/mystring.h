
// BY OSCAR NARANJO
// NOVEMBER2, 2020
// COP3330


#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

class MyString
{
	friend ostream& operator<< (ostream&, const MyString&);
	friend istream& operator>> (istream&, MyString&);
	friend istream& getline(istream&, MyString&);
	friend istream& getline(istream&, MyString&, char delim);

	friend MyString operator+ (const MyString&, const MyString&);

	friend bool operator< (const MyString&, const MyString&);
	friend bool operator> (const MyString&, const MyString&);
	friend bool operator<=(const MyString&, const MyString&);
	friend bool operator>=(const MyString&, const MyString&);
	friend bool operator==(const MyString&, const MyString&);
	friend bool operator!=(const MyString&, const MyString&);

public:
	MyString();				// empty string
	MyString(const char* s);		// conversion from c-string
	MyString(int);			// conversion from int
	~MyString();				// destructor
	MyString(const MyString&);		// copy constructor
	MyString& operator=(const MyString&);   // assignment operator

	MyString& operator+=(const MyString&);  // concatenation/assignment

	// bracket operators to access char positions
	char& operator[] (unsigned int index);
	const char& operator[] (unsigned int index) const;

	// insert s into the string at position "index"
	MyString& insert(unsigned int index, const MyString& s);

	// find index of the first occurrence of s inside the string
	//  return the index, or -1 if not found
	int indexOf(const MyString& s) const;

	int getLength() const;		// return string length
	const char* getCString() const;	// return c-string equiv

	MyString substring(unsigned int, unsigned int) const;
	MyString substring(unsigned int) const;

private:

	char* str; // pointer

	int size; // size of the string


};




MyString::MyString()
// empty string constgrcutor
{
	size = 0;
	str = new char[size];
	*str = '\0';
}

MyString::MyString(const char* s)
// conversion from c-string
{
	size = strlen(s);
	str = new char[size];

	for (size_t i = 0; i < size; i++)
		str[i] = s[i];

	//str[size - 1] = '\0';
}

MyString::MyString(int s)
// convert from int to string
{
	int input = s;
	int count = 0;

	do
	{
		input = input / 10;
		count++;
	} while (input != 0);

	size = count;
	str = new char[size];

	input = s;

	do
	{
		str[count - 1] = char((input % 10) + 48);
		input = input / 10;
		count--;
	} while (count >= 1);

	//str[size - 1] = '\0';
}

MyString::~MyString()
// cleans up memory in string
{
	delete[] str;
}

MyString::MyString(const MyString& s)
// copy constructor
{
	size = s.size;
	str = new char[size];

	for (int i = 0; i < size; i++)
		str[i] = s.str[i];

}

MyString& MyString::operator=(const MyString& s)
// assignment operator
{
	if (this != &s)
	{
		delete[] str;
		size = s.size;
		str = new char[size];

		for (int i = 0; i < size - 1; i++)
			str[i] = s.str[i];

		//str[size - 1] = '\0';
	}
	return *this;
}

MyString& MyString::operator+=(const MyString& s)
// concatenation/assignments
{
	char* strTemp = new char[size + s.size - 1];

	for (int i = 0; i < size - 1; i++)
		strTemp[i] = str[i];

	for (int i = 0; i < size; i++)
		strTemp[i + size - 1] = s.str[i];


	size = size + s.size;
	delete[] str;
	str = strTemp;

	return *this;

}

char& MyString::operator[] (unsigned int index)
// return the character at the given index position
{
	if (index <= size - 2)
		return str[index];
	else
	{
		char* temp = new char[index + 2];

		for (int i = 0; i < size - 1; i++)
			temp[i] = str[i];

		for (int i = size - 1; i < index + 1; i++)
			temp[i] = ' ';

		temp[index + 1] = '\0';
		delete[] str;
		str = temp;
		size = index + 2;

		return str[index];
	}
}

const char& MyString::operator[] (unsigned int index) const
// return the character at the given index position
{
	if (index <= size - 2)
		return str[index];
	else
		return str[size - 1];
}

MyString& MyString::insert(unsigned int index, const MyString& s)
// change the calling object by inserting the data from the second parameter
{
	if (index <= size - 1)
	{
		char* temp = new char[size + s.size - 1];

		for (int i = 0; i < index; i++)
			temp[i] = str[i];

		for (int i = 0; i < s.size - 1; i++)
			temp[i + index] = s.str[i];

		for (int i = index + s.size - 1; i < size + s.size - 2; i++)
			temp[i] = str[i - s.size + 1];

		temp[size + s.size - 2] = '\0';
		delete[] str;
		str = temp;
		size = size + s.size - 1;
	}
	else // if out of boundary
	{
		char* temp = new char[size + s.size - 1];

		for (int i = 0; i < size - 1; i++)
			str[i] = str[i];

		for (int i = 0; i < s.size - 1; i++)
			temp[size - 1 + i] = s.str[i];

		temp[size + s.size - 2] = '\0';
		delete[] str;
		str = temp;
		size = size + s.size - 1;
	}
	return *this;
}

int MyString::indexOf(const MyString& s) const
// search through the MyString to find the first occurence of the pattern or substring given in the parameter.
{
	if (size < s.size)
		return -1;

	else if (size == s.size)
	{
		int i = 0;
		while ((str[i] == s.str[i]) && (str[i] != '\0'))
			i++;

		if (str[i] == '\0')
			return 0;
		else
			return -1;
	}
	else // calling object is longer
	{
		int index = 0;

		while (index < (str - s.str + 1))
		{
			int j = 0;
			int k = 0;
			while ((s[0] != str[index]) && (index < (size - s.size + 1)))
				index++;

			if (index == size - s.size + 1)
				return -1;
			else
			{
				k = index;
				while ((s[j] == str[k]) && (s[j] != '\0'))
				{
					k++;
					j++;
				}
				if (s[j] == '\0')
					return index;
				else
					index++;
			}
		}
	}
}

int MyString::getLength() const
// return the length of the stored string
{
	return size - 1;
}

const char* MyString::getCString() const
// return the actual stored data as a c-string
{
	return str;
}

MyString MyString::substring(unsigned int index, unsigned int length) const

{
	MyString subStr = substring(index);

	if (subStr.size - 1 <= length)
		return subStr;
	else
	{
		char* temp = new char[length + 1];

		for (int i = 0; i < length; i++)
			temp[i] = subStr.str[i];

		temp[length] = '\0';
		delete[] subStr.str;
		subStr.str = temp;
		subStr.size = length + 1;
		return subStr;
	}
}

MyString MyString::substring(unsigned int index) const

{
	MyString subStr;
	int tempSize = size - index;

	char* tempstring = new char[tempSize];

	for (int i = index; i < size - 1; i++)
		tempstring[i] = str[i + index];

	subStr.str = tempstring;
	subStr.size = tempSize;
	//}
	return subStr;
}

ostream& operator<< (ostream& os, const MyString& s)
// output string
{
	for (size_t i = 0; i < s.size; i++)
		os << s.str[i];

	return os;
}

istream& operator>> (istream& is, MyString& s)
// allows user to input string
{
	int maxsize = 1;
	int index = 0;
	char* strB = new char[maxsize];

	while (isspace(is.peek()))
		is.ignore();



	while ((!isspace(is.peek())) && (!is.eof()))
	{
		char* tempStr = new char[maxsize];

		for (int i = 0; i < maxsize; i++)
			tempStr[i] = strB[i];

		//is >> strB[index];

		tempStr[index] = is.get();
		if (index == 0) strB[index] = tempStr[index];

		index++;
		maxsize++;

		delete[] strB;
		strB = tempStr;
	}

	s.str = strB;
	s.size = maxsize;

	return is;
}

istream& getline(istream& is, MyString& s)
// extracts whole c-string
{

	int index = 0;
	int strsize = 10;
	char* strB = new char[strsize];

	do
	{
		if (!is.eof())
		{
			if (index < strsize - 1)
			{
				strB[index] = is.get();
				index++;
			}
			else
			{
				strsize++;
				char* tempStr = new char[strsize];

				for (int i = 0; i < index; i++)
					tempStr[i] = strB[i];
				tempStr[index] = is.get();
				index++;

				delete[] strB;
				strB = tempStr;
			}
		}
	} while (!is.eof());

	is.ignore();
	strsize = index;

	//delete[] s.str;

	s.str = strB;
	s.size = strsize;

	return is;
}

istream& getline(istream& is, MyString& s, char delim)
// extracts whole c-string
{
	int index = 0;
	int strsize = 10;
	char* strB = new char[strsize];

	do
	{
		if (!is.eof())
		{
			if (index < strsize - 1)
			{
				strB[index] = is.get();
				index++;
			}
			else
			{
				strsize++;
				char* tempStr = new char[strsize];

				for (int i = 0; i < index; i++)
					tempStr[i] = strB[i];
				tempStr[index] = is.get();
				index++;

				delete[] strB;
				strB = tempStr;
			}
		}
	} while ((is.peek() != delim) && (!is.eof()));

	is.ignore();
	strsize = index;

	//delete[] s.str; 

	s.str = strB;
	s.size = strsize;

	return is;
}

MyString operator+ (const MyString& s1, const MyString& s2)
// adds string to string
{
	MyString s = s1;
	s += s2;

	return s;
}

bool operator< (const MyString& s1, const MyString& s2)
	// checks for less than comparison
{
	int i = 0;

	while ((s1.str[i] != '\0') && (s1.str[i] == s2.str[i]))
		i++;

	if ((s1.str[i] - s2.str[i]) < 0)
		return true;

	else
		return false;
}


bool operator> (const MyString& s1, const MyString& s2)
// checks for grater than comparison
{
	if (s1 <= s2)
		return false;
	else
		return true;
}

bool operator<=(const MyString& s1, const MyString& s2)
// checks for less than or equal to comparison
{

	if ((s1 < s2) || (s1 == s2))
		return true;
	else
		return false;
}

bool operator>=(const MyString& s1, const MyString& s2)
// checks for greater than or equal to comparison
{

	if (s1 < s2)
		return false;
	else
		return true;
}

bool operator==(const MyString& s1, const MyString& s2)
// checks for equal to comparison
{

	for (int i = 0; i < s1.size; i++)
	{
		if (s1.str[i] != s2.str[i])
			return false;
	}
	return true;
}

bool operator!=(const MyString& s1, const MyString& s2)
// checks for not equal to comparison
{
	if (s1 == s2)
		return false;
	else
		return true;
}
