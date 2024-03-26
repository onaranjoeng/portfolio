
#include <iostream>
#include <cmath>

using namespace std;

// constants
const int ROWCAP = 100;
const int COLCAP = 100;

int findNorm(int[][COLCAP], int, int); // function to find the highest value


int main() {

    int matrixArr[ROWCAP][COLCAP] = { 0 }; // creates a 2D array
    int cols, rows; 

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the matrix: \n";

    for (int i = 0; i < rows; i++) 
    {
        cout << "Enter row # " << i + 1 << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrixArr[i][j]; // starts by getting numbers for each row
        }
    }

    cout << "The matrix entered was: \n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrixArr[i][j] << "\t"; // prints the matrix
        }
        cout << "\n";
    }

    cout << "The L21 norm is: " << findNorm(matrixArr, rows, cols) << endl;

    return 0;
}

int findNorm(int matrixArr[][COLCAP], int rows, int cols) {

    int maxSumAbs = 0, sumAbs; 

    for (int j = 0; j < cols; j++) // loop through columns
    {
       
    }

    return maxSumAbs;

}