// OSCAR NARANJO
// COP3330 SECTION 001
// SEPTEMBER 14, 2020

class House {
public:
    House();
    House(int bs, char b = 'X', char f = '*');   // constructor with optional inputs and default setting

    void Grow();                                 // function to grow base
    void Shrink();                               // function to shrink base
    void SetBorder(char b);                      // function to set border
    void SetFill(char f);                        // function to set fill

    void Draw() const;                           // draw the house
    void Summary(House h3) const;                // provide summary of input and output
    int GetSize() const;                         // retrieve size inputs
    int Perimeter() const;                       // retrieve perimeter of house
    double Area() const;                         // return area of house

private:
    int base;                                    // base cannot be less than 3 or greater than 37
    char border;                                 // border of house
    char fill;                                   // fill of house
};
