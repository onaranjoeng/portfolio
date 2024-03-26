// OSCAR NARANJO
// COP3330 SECTION 001
// SEPTEMBER 14, 2020

using namespace std;

class Mixed
{
	// standard arithmetic operation
	friend Mixed operator+(const Mixed& f1, const Mixed& f2);	// additoin
	friend Mixed operator-(const Mixed&, const Mixed&);			// subtraction
	friend Mixed operator*(const Mixed&, const Mixed&);			// multiplication
	friend Mixed operator/(const Mixed&, const Mixed&);			// division

	friend ostream& operator<<(ostream&, const Mixed&);		// output function
	friend istream& operator>>(istream&, Mixed&);			// input function

public:
	Mixed(int num = 0);				// conversion constructor
	Mixed(int w, int n, int d);		// constructor with 3 parameters

	// increment and decrement operations
	Mixed& operator++();	// prefix increment
	Mixed operator++(int);	// postfix increment
	Mixed& operator--();	// prefix decrement
	Mixed operator--(int);	// postfix decrement

	// comparison operators
	friend bool operator==(const Mixed& n1, const Mixed& n2);	// equals
	friend bool operator<(const Mixed n1, const Mixed n2);		// less than
	friend bool operator>(const Mixed n1, const Mixed n2);		// greater than
	friend bool operator<=(const Mixed n1, const Mixed n2);		// less than or equal to
	friend bool operator>=(const Mixed n1, const Mixed n2);		// greater than or equal to
	friend bool operator!=(const Mixed n1, const Mixed n2);		// not equal to

	double Evaluate() const;	// return the decimal equivalent of the mixed number.
	void ToFraction();			// convert the mixed number into fraction form.
	void Simplify();			// simplify the mixed number representation to lowest terms.

private:
	int numerator, denominator, whole;  // object

};

istream& operator>>(istream& is, Mixed& x) {
	// input function
	char space, slash;
	is >> x.whole >> x.numerator >> slash >> x.denominator;	
	return is;
}

ostream& operator<<(ostream& os, const Mixed& x) {
// output function
	if (x.denominator <= 0){
		os << 0;
		return os;
	}

	if (x.numerator == 0 && x.whole != 0)  {
		os << x.whole;
		return os;
	}

	if ((x.numerator < 0 && x.whole < 0) || (x.numerator == 0 && x.denominator != 0)) {
		os << 0;
		return os;
	}
	

	if (x.whole == 0){
		os << x.numerator << '/' << x.denominator;
	}

	else {

		os << x.whole << ' ' << x.numerator << '/' << x.denominator;
	}

}

Mixed operator+(const Mixed& n1, const Mixed& n2)
{
	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

		// load result with rusulting numerator
	r.numerator = ((r.numerator * l.denominator) + (l.numerator * r.denominator));

		// load result with the common denominator
	r.denominator = r.denominator * l.denominator;
	
	r.Simplify();
	return r;         // return the result Fraction
}

Mixed operator-(const Mixed& n1, const Mixed& n2) {

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	// load result with rusulting numerator
	r.numerator = ((r.numerator * l.denominator) - (l.numerator * r.denominator));

	// load result with the common denominator
	r.denominator = r.denominator * l.denominator;

	r.Simplify();
	return r;         // return the result Fraction
}
Mixed operator*(const Mixed& n1, const Mixed& n2) {

	Mixed r, l;       
	r = n1;
	l = n2;
	r.ToFraction();
	l.ToFraction();

	// load result with rusulting numerator
	r.numerator = r.numerator * l.numerator;

	// load result with the common denominator
	r.denominator = r.denominator * l.denominator;

	r.Simplify();
	return r;         // return the result Fraction
}
Mixed operator/(const Mixed& n1, const Mixed& n2) {

	Mixed r, l;       // declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	// load result with rusulting numerator
	r.numerator = r.numerator * l.denominator;

	// load result with the common denominator
	r.denominator = r.denominator * l.numerator;

	// if denominator is negative change signs
	if (r.denominator < 0)
	{
		r.denominator = r.denominator * -1;
		r.numerator = r.numerator * -1;
	}
	r.Simplify();
	return r;			 // return the result Fraction
}

Mixed& Mixed::operator++()	// pre-fix increment
{
	whole = whole + 1;		// increment the real part
	return *this;			// return reference to calling object
}

Mixed Mixed::operator++(int)	// post-fix increment
{
	Mixed temp = *this;		// copy current object to temp
	whole = whole + 1;		// increment
	return temp;			// return OLD value
}

Mixed& Mixed::operator--()	// pre-fix decrement
{
	whole = whole - 1;		// decrement the real part
	return *this;			// return reference to calling object
}

Mixed Mixed::operator--(int)
{
	Mixed temp = *this;	    // copy current object to temp
	whole = whole - 1;		// decrement
	return temp;			// return OLD value
}

bool operator==(const Mixed& n1, const Mixed& n2) {
	// check if fractions are qual

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	if (r.numerator == l.numerator && r.denominator == l.denominator)
		return true;
	else
		return false;
}

bool operator<(const Mixed n1, const Mixed n2) {
	// check for greater than

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	if (r.numerator * l.denominator < r.denominator * l.numerator)
		return true;
	else
		return false;
 }
bool operator>(const Mixed n1, const Mixed n2) {
	// check for less than 

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	return (l < r);

 }
bool operator<=(const Mixed n1, const Mixed n2) {
	// check for less than or equal to fractions

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	if (r > l)
		return false;
	else
		return true;
 }
bool operator>=(const Mixed n1, const Mixed n2) {
	// check for greater than or equal to fractions

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();

	if (r < l)
		return false;
	else
		return true;
 }

bool operator!=(const Mixed n1, const Mixed n2) {
	// check for not equal fractions

	Mixed r, l;			// declare variables to hold mixed numer
	r = n1;
	l = n2;
	r.ToFraction();		// swtich to fraction
	l.ToFraction();
	
	if (r.numerator != l.numerator && r.denominator != l.denominator)
		return true;
	else
		return false;
 }

Mixed::Mixed(int num)
// Conversion constructor.
{
	whole = num;
	numerator = 0;
	denominator = 1;
}

Mixed::Mixed(int w, int n, int d)
{
	
	whole = w;
	numerator = n;
	denominator = d;
}

double Mixed::Evaluate() const
// Calculates and returns the decimal value of a fraction
{
	float decimal;
	if (whole < 0)
	decimal = (static_cast<double>(whole) * static_cast<double>(denominator) - static_cast<double>(numerator)) / static_cast<double>(denominator);
	else
	{
		decimal = (static_cast<double>(whole) * static_cast<double>(denominator) + static_cast<double>(numerator)) / static_cast<double>(denominator);
	}
	return decimal;
}

void Mixed::ToFraction() 
// Changes from mixed to a fractions
{
	// if whole number is negative
	if (whole > 0) {
		int num;
		num = denominator * whole;
		numerator = num + numerator;
		whole = 0;
	}
	// or positive
	if (whole < 0) {
		int num;
		num = denominator * whole;
		numerator = num - numerator;
		whole = 0;
	}
	
}
void Mixed::Simplify() 
// Simplifies the mixed number
{
	int bigger_num;

	if (whole == 0) {
		whole = numerator / denominator;
		numerator = numerator % denominator;
	}

	if (numerator < denominator) {

		bigger_num = denominator;
	}
	else {
		bigger_num = numerator;
	}

	for (int i = bigger_num; i > 0; i--) {
		if (numerator % i == 0 && denominator % i == 0) {

			numerator = numerator / i;
			denominator = denominator / i;
		}
	}

	if (abs(numerator) > denominator) {
		numerator = numerator % denominator;
		whole += denominator;
	}
	
	if (whole != 0) numerator = abs(numerator);

	
}
