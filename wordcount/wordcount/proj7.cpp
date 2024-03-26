// Oscar Naranjo
// December 1st, 2022
// COP4530

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

// Functions for each type of character
void words(map<string, pair<int, int>>& wordMap);
void numbers(map<string, pair<int, int>>& numMap);
void characters(map<char, pair<int, int>>& charMap);

int main() {
    
    string word;
    string number;
    char character;

    map<string, pair<int, int>> wordMap;
    map<string, pair<int, int>> numMap;
    map<char, pair<int, int>> charMap;

    while (cin.good()) {

        cin.get(character);
        
        if (isalpha(character))
        { // If character is a letter
            word += tolower(character); 
            // check if empty
            if (!number.empty()) 
            { 
                ++numMap[number].first; 
                if (numMap[number].first == 1) 
                { 
                    numMap[number].second = numMap.size();
                }
                number = ""; 
            }
        }
        else if (isdigit(character)) 
        { // If character is a number
            number += character; 

            if (!word.empty()) 
            {
                ++wordMap[word].first; 
                if (wordMap[word].first == 1) 
                { 
                    wordMap[word].second = wordMap.size();
                }
                word = ""; 
            }
        }
        else 
        { // if character is not a letter
            if (!word.empty()) 
            { 
                ++wordMap[word].first; 
                if (wordMap[word].first == 1) {

                    wordMap[word].second = wordMap.size();
                }
                word = ""; 
            }
            if (!number.empty()) 
            { 
                ++numMap[number].first; 
                if (numMap[number].first == 1) 
                { 
                    numMap[number].second = numMap.size();
                }
                number = ""; 
            }
        }
        ++charMap[character].first;
        charMap[character].second = (int)character;
    }

    if (!word.empty()) 
    { 
        ++wordMap[word].first; // increase for specific word string
        if (wordMap[word].first == 1) 
        { // update for new word
            wordMap[word].second = wordMap.size();
        }
    }
    if (!number.empty()) 
    { 
        ++numMap[number].first; 
        if (numMap[number].first == 1)
        { // update for a new number
            numMap[number].second = numMap.size();
        }
    }
  
    words(wordMap);
    numbers(numMap);
    characters(charMap);

    return 0;
}

void words(map<string, pair<int, int>>& wordMap) 
{
    int numberOfWords; // counter

    // only display the top 10 words
    if (wordMap.size() <= 10) {
        numberOfWords = wordMap.size();
    }
    else {
        numberOfWords = 10;
    }
    cout << endl;
    cout << "There are " << wordMap.size() << " Unique Words, The Top " << numberOfWords << " Words:" << endl;
    cout << endl;
    cout << "Index     Item      Number     Priority" << endl;

    map<string, pair<int, int>>::iterator it;

    // Iterate to find the top 10 or less words
    for (int i = 0; i < numberOfWords; i++) 
    {
        // using stack overflow
        // initialize
        auto best = wordMap.begin(); 
        for (it = wordMap.begin(); it != wordMap.end(); it++) 
        { 
            if (best->second.first < it->second.first) 
            {
                best = it;
            }
            else if (best->second.first == it->second.first) 
            { // update priority
                if (it->second.second < best->second.second) 
                {
                    best = it;
                }
            }
        }

        // display
        cout << "[  " << i << "] " << setw(11) << best->first << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        wordMap.erase(best); // Erase max value
    }
}

void numbers(map<string, pair<int, int>>& numMap) 
{
    int numberOfNumbers; // counter

    //  only display the top 10 numbers
    if (numMap.size() <= 10) {
        numberOfNumbers = numMap.size();
    }
    else {
        numberOfNumbers = 10;
    }
    cout << endl;
    cout << "There are " << numMap.size() << " Unique Numbers, The Top " << numberOfNumbers << " Numbers:" << endl;
    cout << endl;
    cout << "Index     Item      Number     Priority" << endl;

    map<string, pair<int, int>>::iterator it;
    for (int i = 0; i < numberOfNumbers; i++) 
    {
        // The same as the other function but for numbers
        auto best = numMap.begin(); 
        for (it = numMap.begin(); it != numMap.end(); it++) 
        { 
            if (best->second.first < it->second.first) 
            {
                best = it;
            }
            else if (best->second.first == it->second.first) 
            { 
                if (it->second.second < best->second.second) 
                {
                    best = it;
                }
            }
        }

        // display
        cout << "[  " << i << "] " << setw(11) << best->first << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        numMap.erase(best); // Erase max value in map to use for next iteration
    }
}

void characters(map<char, pair<int, int>>& charMap) 
{
    int numberOfCharacters;

    // only display the top 10 characters
    if (charMap.size() <= 10) {
        numberOfCharacters = charMap.size();
    }
    else {
        numberOfCharacters = 10;
    }
    cout << endl;
    cout << "There are " << charMap.size() << " Unique Words, The Top " << numberOfCharacters << " Characters:" << endl;
    cout << endl;
    cout << "Index     Item      Number     Priority" << endl;

    map<char, pair<int, int>>::iterator it;
    for (int i = 0; i < numberOfCharacters; i++) 
    {
        // The same as the other function but for letters/characters
        auto best = charMap.begin(); 
        // go through map
        for (it = charMap.begin(); it != charMap.end(); it++) 
        { 
            if (best->second.first < it->second.first) 
            {
                best = it;
            }
            else if (best->second.first == it->second.first) 
            { 
                if (it->second.second < best->second.second)
                {
                    best = it;
                }
            }
        }
        
        // display for other possibilites of input
        // if character is a newline character
        if (best->first == '\n') 
        { 
            cout << "[" << i << "] " << setw(11) << "Newline" << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        }
        // else if character is a tab character
        else if (best->first == '\t') 
        { 
            cout << "[" << i << "] " << setw(11) << "Tab" << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        }
        // else if characters is a space
        else if (best->first == ' ') 
        { 
            cout << "[" << i << "] " << setw(11) << "Space" << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        }
        else 
        {
            cout << "[" << i << "] " << setw(11) << best->first << setw(6) << best->second.first << setw(11) << best->second.second << endl;
        }
        charMap.erase(best); 
    }
}