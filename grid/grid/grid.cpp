// BY OSCAR NARANJO
// COP 3363
// OCTOBER 17, 2020

#include <iostream>
#include "grid.h"
#include <ctime>
#include <cstdlib>

using namespace std;

/*int main()
{
	// set up the initial grid

	Grid K(9, 15);

	Grid g(9, 15, 2, 13, Grid::WEST);

	g.PutDown(2, 1);

	for (int i = 0; i < 7; i++)
	{
		g.PlaceBlock(i, 11);
		g.PlaceBlock(i, 7);
		g.PlaceBlock(i, 3);
		g.PlaceBlock(i + 2, 5);
		g.PlaceBlock(i + 2, 9);
	}

	K.Display();
	g.Display();

	// now start moving

	g.TurnLeft();
	g.Move(5);
	g.Display();

	g.TurnLeft();
	g.TurnLeft();
	g.TurnLeft();
	g.Move(1);
	g.Display();

	for (int i = 0; i < 2; i++)
	{
		g.Move(2);
		g.Display();

		g.TurnLeft();
		g.TurnLeft();
		g.TurnLeft();
		g.Move(6);
		g.Display();

		g.PutDown();
		g.Display();

		g.TurnLeft();
		g.Move(2);
		g.Display();

		g.TurnLeft();
		g.Move(6);
		g.Display();

		g.TurnLeft();
		g.TurnLeft();
		g.TurnLeft();
	}

	g.Move(3);
	g.Display();

	g.TurnLeft();
	g.TurnLeft();
	g.TurnLeft();
	g.Move(5);
	g.Display();

	g.PickUp();
	g.Display();

	g.TurnLeft();
	g.Move(1);
	g.Display();

	g.TogglePath();
	g.Display();
	g.TogglePath();
	g.Display();

	g.Grow(5, 5);
	g.Display();
    
    return 0;
}*/


Grid::Grid() {
	// build 1 x 1 grid with mover in only
	//  square, facing east
	InitializeGrid();
	moverRow = 0;
	moverColumn = 0;
	rowSize = 1;
	columnSize = 1;
	grid[0][0] = '>';

}

Grid::Grid(int r, int c) {		// build grid with r rows, c cols,
			 //  blocks around edge with random exit
			 //  and random mover position and direction

	InitializeGrid();
	rowSize = r;
	columnSize = c;
	int randNumCol = 0;
	int randNumRow = 0;
	int randNumWall = 0;
	int randNumPoint = 0;
	int rowPoint = 0;
	int columnPoint = 0;

	if (rowSize > MAX) rowSize = 40;
	if (columnSize > MAX) columnSize = 40;
	if (rowSize < 3) rowSize = 3;
	if (columnSize < 3) columnSize = 3;

	StartGrid(rowSize, columnSize);



	// random number for mover
	srand(time(0));
	randNumCol = (rand() % (columnSize - 2)) + 1;
	randNumRow =( rand() % (rowSize - 2)) + 1;
	direction = rand() % 4;

	moverRow = randNumRow;
	moverColumn = randNumCol;

	grid[randNumRow][randNumCol] = Mover(direction);

	for (int i = 0; i < rowSize; i++)
	{
		PlaceBlock(i, 0);
		PlaceBlock(i, columnSize-1);
	}
	for (int i = 0; i < columnSize; i++)
	{
		PlaceBlock(0, i);
		PlaceBlock(rowSize - 1, i);
	}

	randNumWall = rand() % 4;

	if (randNumWall == 0 || randNumWall == 2) {
		randNumPoint = (rand() % (c - 1)) + 1;
		if (randNumWall == 0) {
			rowPoint = 0;
		} else rowPoint = r -1;
		columnPoint = randNumPoint;

	}
	else {
		randNumPoint = (rand() % (r - 1)) + 1;
		if (randNumWall == 1) {
			columnPoint = 0;
		}
		else columnPoint = c - 1;
		rowPoint = randNumPoint;
	}

	grid[rowPoint][columnPoint] = EMPTY;


}

Grid::Grid(int r, int c, int mr, int mc, int d) {
	// build empty grid with r rows, c cols, and mover
	//  at row mr, col mc, and facing direction d
	InitializeGrid();
	StartGrid(r, c);
	rowSize = r;
	columnSize = c;
	moverRow = mr;
	moverColumn = mc;
	direction = d;

	if (rowSize > MAX) rowSize = 40;
	if (columnSize > MAX) columnSize = 40;
	if (rowSize < 1) rowSize = 3;
	if (columnSize < 1) columnSize = 3;
	if (moverColumn > columnSize) moverColumn = columnSize - 1;
	if (moverRow > rowSize) moverRow = rowSize - 1;

	// random number for mover

	moverRow = mr;
	moverColumn = mc;

	grid[moverRow][moverColumn] = Mover(d);

}

void Grid::InitializeGrid() {

	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t j = 0; j < MAX; j++)
		{
			grid[i][j] = '.';
		}
	}

	for (size_t i = 0; i < MAX * MAX; i++)
	{
		path[i][0] = -1;
		path[i][1] = -1;
	}

	pathRow = -1;

}

void Grid::StartGrid(int r, int c) {

	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			grid[i][j] = '.';
		}
	}
}

char Grid::Mover(int m) {
	char mover = ',';

	switch (m)
	{
	case NORTH:
		mover = '^';
		break;
	case WEST:
		mover = '<';
		break;
	case SOUTH:
		mover = 'v';
		break;
	case EAST:
		mover = '>';
		break;
	default:
		break;
	}

	return mover;

}

void Grid::TogglePath() {
	// toggle whether or not moved path is shown
	if (TogglePathSwitch) {
		TogglePathSwitch = false;
	}
	else TogglePathSwitch = true;

}

void Grid::Display() const {
	// display the grid on screen

	bool findPath = false;

	cout << "The Grid:" << endl;
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			if (TogglePathSwitch) {

				findPath = false;
				for (int y = 0; y <= pathRow; y++)
					if (path[y][0] == i && path[y][1] == j)
						findPath = true;

				if (findPath && (grid[i][j] != ITEM && grid[i][j] != AT)) {

					cout << " " << " ";

				}
				else
				{
					if (grid[i][j] == ITEM && i == moverRow && j == moverColumn) {
						cout << AT << " ";
					}
					else cout << grid[i][j] << " ";
				}
			}
			else
			{
				if (grid[i][j] == ITEM && i == moverRow && j == moverColumn) {
					cout << AT << " ";
				}
				else cout << grid[i][j] << " ";
			}
		}
		cout << endl;
	}
}


void Grid::TurnLeft() {
	// turn the mover to the left

	if (direction == NORTH)
	{
		direction = WEST;
	}
	else if (direction == WEST)
	{
		direction = SOUTH;
	}
	else if (direction == SOUTH)
	{
		direction = EAST;
	}
	else if (direction == EAST)
	{
		direction = NORTH;
	}
	if (grid[moverRow][moverColumn] != ITEM && grid[moverRow][moverColumn] != AT) grid[moverRow][moverColumn] = Mover(direction);

}

bool Grid::Move(int s) {
	// move forward s spaces, if possible

	int tempRow = moverRow;
	int tempColumn = moverColumn;

	for (size_t i = 0; i < s; i++) {

		if (!FrontIsClear()) {

			moverRow = tempRow;
			moverColumn = tempColumn;
			return false;

		}
		else
		{
			if (direction == NORTH) moverRow--;
			if (direction == WEST) moverColumn--;
			if (direction == SOUTH) moverRow++;
			if (direction == EAST) moverColumn++;
		}

	}

	moverRow = tempRow;
	moverColumn = tempColumn;

	for (size_t i = 0; i < s; i++) {

		pathRow++;
		path[pathRow][0] = moverRow;
		path[pathRow][1] = moverColumn;

		if (grid[moverRow][moverColumn] != ITEM && grid[moverRow][moverColumn] != AT) grid[moverRow][moverColumn] = EMPTY;

		if (direction == NORTH) moverRow--;
		if (direction == WEST) moverColumn--;
		if (direction == SOUTH) moverRow++;
		if (direction == EAST) moverColumn++;

		if (grid[moverRow][moverColumn] == EMPTY) grid[moverRow][moverColumn] = Mover(direction);

	}

}

void Grid::PutDown() {
	// put down an item at the mover's position
	grid[moverRow][moverColumn] = ITEM;

}

bool Grid::PutDown(int r, int c) {
	// put down an item at (r,c), if possible
	if (r > rowSize) return false;
	if (c > columnSize) return false;

	if (grid[r][c] != ITEM && grid[r][c] != BLOCK)
	{
		grid[r][c] = ITEM;
		return true;
	}
	else
		return false;

}

bool Grid::PlaceBlock(int r, int c) {
	// put a block at (r,c), if possible

	if (grid[r][c] == EMPTY)
	{
		grid[r][c] = BLOCK;
		return true;
	}
	else
		return false;
}

bool Grid::PickUp() {
	// pick up item at current position

	if (grid[moverRow][moverColumn] == ITEM)
	{
		grid[moverRow][moverColumn] = Mover(direction);
		return true;
	}
	else
		return false;

}

void Grid::Grow(int gr, int gc) {
	// grow the grid by gr rows, gc columns

	int oldRowSize = rowSize;
	int oldColumnSize = columnSize;
	rowSize = rowSize + gr;
	columnSize = columnSize + gc;

	if (rowSize > MAX) rowSize = 40;
	if (columnSize > MAX) columnSize = 40;

	for (size_t i = oldRowSize; i < rowSize; i++) {
		for (size_t j = oldColumnSize; i < columnSize; i++) {
			grid[i][j] = '.';
		}
	}
}

// Accessors
bool Grid::FrontIsClear() const {
	// check to see if space in front of 
	//  mover is clear

	switch (direction)
	{
	case NORTH:
		if ((moverRow - 1) < 0) return false;
		if (grid[moverRow - 1][moverColumn] == BLOCK) return false;
		break;
	case WEST:
		if ((moverColumn - 1) < 0) return false;
		if (grid[moverRow][moverColumn - 1] == BLOCK) return false;
		break;
	case SOUTH:
		if ((moverRow + 1) > rowSize -1) return false;
		if (grid[moverRow + 1][moverColumn] == BLOCK) return false;
		break;
	case EAST:
		if ((moverColumn + 1) > columnSize -1) return false;
		if (grid[moverRow][moverColumn + 1] == BLOCK) return false;
		break;
	default:
		break;
	}
	return true;

}

bool Grid::RightIsClear() const {
	// check to see if space to right of 
			 //  mover is clear
	switch (direction)
	{
	case NORTH:
		if ((moverColumn + 1) > columnSize-1) return false;
		if (grid[moverRow][moverColumn + 1] == BLOCK) return false;
		break;
	case WEST:
		if ((moverRow - 1) < 0) return false;
		if (grid[moverRow - 1][moverColumn] == BLOCK) return false;
		break;
	case SOUTH:
		if ((moverColumn - 1) < 0) return false;
		if (grid[moverRow][moverColumn - 1] == BLOCK) return false;
		break;
	case EAST:
		if ((moverRow + 1) > rowSize - 1) return false;
		if (grid[moverRow + 1][moverColumn] == BLOCK) return false;
		break;
	default:
		break;
	}

	return true;

}
int Grid::GetRow() const {
	// return row of the mover
	return moverRow;

}
int Grid::GetCol() const {
	// return column of the mover
	return moverColumn;

}
int Grid::GetNumRows() const {
	// return number of rows in the grid
	return rowSize;

}
int Grid::GetNumCols() const {
	// return number of columns in the grid
	return columnSize;

}

