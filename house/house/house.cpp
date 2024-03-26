// OSCAR NARANJO
// COP3330 SECTION 001
// SEPTEMBER 14, 2020

#include <cmath>
#include <iomanip>
#include <iostream>
#include "house.h"

using namespace std;


int main() {

    // create some Houses
    House h1(-5), h2(7, '^'), h3(12, 'W', 'o'), h4(50, '$', '-');
    // display original Houses

    cout << "h1 has size = " << h1.GetSize() << " units.\n";
    h1.Draw();
    cout << "\nh2 has size = " << h2.GetSize() << " units.\n";
    h2.Draw();
    cout << "\nh3 has size = " << h3.GetSize() << " units.\n";
    h3.Draw();
    cout << "\nh4 has size = " << h4.GetSize() << " units.\n";
    h4.Draw();
    cout << '\n';

    h1.Shrink(); // demonstrate shrink
    h2.Shrink();
    h3.Grow(); // and grow
    h4.Grow();
    cout << "h1 now has size = " << h1.GetSize() << " units.\n";
    cout << "h2 now has size = " << h2.GetSize() << " units.\n";
    cout << "h3 now has size = " << h3.GetSize() << " units.\n";
    cout << "h4 now has size = " << h4.GetSize() << " units.\n";

    // demonstrate perimeter
    cout << "h2 has perimeter = " << h2.Perimeter() << " units.\n";
    cout << "h3 has perimeter = " << h3.Perimeter() << " units.\n";
    // and area
    cout << "h2 has area = " << h2.Area() << " square units.\n\n";
    cout << "h3 has area = " << h3.Area() << " square units.\n\n";

    h1.Draw();
    h1.Grow();               // show that fill character
    cout << "h1 grows:\n";   // appears only when size
    h1.Draw();               // is at least 3
    h1.Grow();
    cout << "... and grows:\n";
    h1.Draw();
    cout << '\n';

    h1 = h2; // demonstrate the default overload of the
    // assignment operator
    cout << "h1 now has size = " << h1.GetSize() << " units.\n";
    h1.Draw();

    // demonstrate the changing of border and fill characters
    h2.SetBorder('@'); // legal
    h2.SetFill('-'); // legal
    cout << "h2 now looks like:\n";
    h2.Draw();
    cout << '\n';
    h2.SetBorder('\n');	 // illegal border
    h2.SetFill('\a');	 // illegal fill
    cout << "h2 now looks like:\n";
    h2.Draw();
    cout << '\n';

    cout << "\nHere is a summary on h3:\n"; // demonstrate summary
    h3.Summary(h3);

    return 0;
}

House::House() {
    base = 3;
    fill = '*';
    border = 'X';

}

House::House(int bs, char b, char f) {

    if (bs < 3)
        bs = 3;

    if (bs > 37)
        bs = 37;

    base = bs;
    fill = f;
    border = b;

}

double House::Area() const {

    double T_area, S_area, area, a;
    a = base + 2;
    S_area = base * base;
    T_area = (sqrt(3) / 4) * pow(a, 2);
    area = S_area + T_area;
    return area;
}

int House::GetSize() const {

    return base;
}

int House::Perimeter() const {

    int p;
    p = (base * 3) + 2 + (2 * (base + 2));
    return p;
}

void House::SetBorder(char b) {

    if ((int)b < 33 || (int)b > 126)
        b = 'X';
    border = b;
}

void House::SetFill(char f) {

    if ((int)f < 33 || (int)f > 126)
        f = '*';
    fill = f;
}

void House::Grow() {

    base++;

}

void House::Shrink() {

    base--;
}

void House::Draw() const {

    int width, height, side, countsT = 0, countSpaces = 0, countFill = 0;
    string line;

    side = base + 2;
    height = base - 1;
    width = base;

    for (int i = 0; i < side + height; ++i) {

        line = "";

        if (i <= side - 1) {
            countsT = i + 1;
            countSpaces = round((double)(side - countsT) / 2);

            if (i < 2) {
                line.append(countSpaces, ' ');
                line.append(countsT, border);
                line.append(countSpaces, ' ');

            }
            else {
                if (i == side - 1) {
                    countFill = countsT - 4;
                    line.append(countSpaces, ' ');
                    line.append(2, border);
                    line.append(countFill, fill);
                    line.append(2, border);
                    line.append(countSpaces, ' ');
                }
                else {
                    countFill = countsT - 2;
                    line.append(countSpaces, ' ');
                    line.append(1, border);
                    line.append(countFill, fill);
                    line.append(1, border);
                    line.append(countSpaces, ' ');
                }
            }
        }
        else {

            countSpaces = 1;
            countFill = width - 2;

            if (i == side + height - 1) {

                line.append(countSpaces, ' ');
                line.append(1, border);
                line.append(countFill, border);
                line.append(1, border);
                line.append(countSpaces, ' ');
            }
            else {

                line.append(countSpaces, ' ');
                line.append(1, border);
                line.append(countFill, fill);
                line.append(1, border);
                line.append(countSpaces, ' ');

            }


        }

        int lineLength = line.length();

        for (int z = lineLength; z >= 0; --z) {
            line.insert(z, 1, ' ');
        }
        cout << line << endl;

    }

}


void House::Summary(House h3) const {

    cout << fixed;
    cout << setprecision(2);
    cout << " House width and height base to roof = " << base << " units." << endl;
    cout << " Perimeter of house = " << h3.Perimeter() << " units." << endl;
    cout << " Area of house = " << h3.Area() << " units." << endl;
    cout << " House looks like : " << endl;
    h3.Draw();

}
