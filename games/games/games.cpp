#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void displayMenu(int&); // FUNCTION FOR USER INPUT
int getValidScore(); // FUNCTION TO ALLOW USER TO INPUT NUMBERS ONLY 0-300 
int getValidGameNumber(int maxGameumber); // FUNCTION TO DISPLAY THE GRADES OF AN ASSIGNMENT
void displayScores(int scores[NUM_GAMES]); //  displays score
void ChangeAScore(int scores[NUM_GAMES]); // changes score
void displayGameHighestScore(int scores[NUM_GAMES]); //displays the number of the game with the highest score

// CONSTANT
const int NUM_GAMES = 3;

int main()
{
    int choice; // VARIABLE FOR MENU
    string Games[NUM_GAMES] = { "Game 1","Game 2","Game 3" }; // PARALLEL ARRAY
    int scores[NUM_GAMES] = { 178,98,288 };

    cout << "Hello, Welcome to the help with the grading program!" << endl; // WELCOME MESSAGE
    // LOOP UNTIL USER QUITS
    do
    {
        displayMenu(choice);

        // FIRST FUNCTION
        if (choice == 1)
        {
            displayScores(scores[3]);
        }

        // SECOND FUNCTION
        if (choice == 2)
        {
            
        }
        // THIRD FUNCTION
        if (choice == 3)
        {

        }
    } while (choice != 4);
    return 0;
}

// FUNCTION FOR USER INPUT MENU
void displayMenu(int& choice)
{
    // OPTIONS GIVEN TO THE USER
    cout << "1) Display the score\n"
        "2) Change a score\n"
        "3) Display game with highest score \n"
        "4) QUit\n";
    do {
        cout << "Select an option (1-4): ";
        cin >> choice;
    } while (choice <= 0 || choice > 4);
}

int getValidScore() // FUNCTION TO ALLOW USER TO INPUT NUMBERS ONLY 0-300 
{
    int score;
    do
    {
        cin >> score;
        if (score <= 0 || score >= 300)
        {
            cout << "Invalid grade. Please enter in a number greater than 0 and less than 100 \n";
        }
    } while (score <= 0 || score >= 300);
    return score;
}

void displayScores(int scores[NUM_GAMES])
{
    cout << "Displaying scores" << endl;

    int sizeGrades =  scores[0].size();
    for (int i = 0; i < sizeGrades; i++)
    {
        cout << "Game" << i + 1 << "   ";
    }
    cout << "\n";

    for (int i = 0; i < scores; i++)
    {
        cout << Games[i] << "   \t " << fixed;
        for (int g = 0; g < sizeGrades; g++)
        {
            cout << scores[i][g] << "%  \t   " << fixed;
        }
        cout << " " << endl;
    }
}

int getValidGameNumber(int maxGameumber)
{
    int game;
    do
    {
        cin >> game;
        if (game <= 1 || game >= maxGameumber)
        {
            cout << "Not a valid game number, please try again. \n";
        }
        // ERROR FOR WHEN USER INPUTS A WRONG VALUE
    } while (game <= 1 || game >= maxGameumber);
    return game;
}

void ChangeAScore(int scores[NUM_GAMES])
{
    cout << "Change a score" << endl;
    int game;
    cout << "Please enter in the game number" << endl;
    do
    {
        cin >> game;

    } while (getValidGameNumber);
     
    cout << "  Please enter in the bowling score" << endl;
    do
    {
        cin >> score;
        cout << "Please enter in a valid bowling score(0...300)" << endl;
    } while (getValidScore);
}


void displayGameHighestScore(int scores[NUM_GAMES])
{



    cout << "The game with the highest score is " << game << endl;
}

