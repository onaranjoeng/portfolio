// BY OSCAR NARANJO
// COP 3363
// OCTOBER 17, 2020

#include <iostream>
#include "grid.h"
#include <ctime>
#include <cstdlib>

int main() {

	int r, c;

	cout << "Please enter the amount of rows: ";
		cin >> r;
	cout << "Please enter the amount of columns: ";
		cin >> c;

	Grid k(r, c);
	k.Display();

	int numRows = k.GetNumRows();
	int numCols = k.GetNumCols();
	int row = k.GetRow();
	int Col = k.GetCol();
	
	bool rightclear = false;
	bool allowRight = false;

	do
	{
		if (!k.FrontIsClear())
		{
			k.TurnLeft();
			allowRight = true;

		}
		else k.Move(1);

		rightclear = k.RightIsClear();
		if (rightclear && allowRight) {

			k.TurnLeft();
			k.TurnLeft();
			k.TurnLeft();
			k.Move(1);
		}
	} while (k.GetRow() > 0  && k.GetRow() < k.GetNumRows() -1 && k.GetCol() > 0 && k.GetCol() < k.GetNumCols() - 1);
	k.Display();

	cout << "We escaped!" << endl;
}