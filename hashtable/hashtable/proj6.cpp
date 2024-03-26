// BY OSCAR NARANJO
// COP4530
// NOVEMBER 13, 2022

#include <iostream>
#include "passserver.h"
#include "base64.h"
#include "hashtable.h"

using namespace std;
using namespace cop4530; 

// functions for menu
void Menu();
void GetServerSize(size_t& serverSize);
void GetUsername(string& user);
pair<string, string> AddNewUser();


int main()
{
   
    char c;
    bool running = true;
    size_t serverSize;
   
    GetServerSize(serverSize);
    PassServer passServer(serverSize);

    while (running) {
        
        while (cin.get(c) && running) 
        {
            if (c == 'l') {  //Load File
                string filename;
                cout << "\nEnter password file name to load from: ";
                cin >> filename;
                if (!passServer.load(filename.c_str()))
                    cout << "\nERROR: Cannot open file!! " << filename << endl;
            }
            else if (c == 'a') {  //Add new user
                pair<string, string> newUser = AddNewUser();
                if (passServer.addUser(newUser))
                    cout << "\nUser " << newUser.first << " added." << endl;
                else cout << "ERROR: Failed!" << endl;
            }
            else if (c == 'r') {  //Remove user
                string user;
                GetUsername(user);
                if (passServer.removeUser(user))
                    cout << "\nUser: " << user << " deleted." << endl;
                else cout << "ERROR: Failed!" << endl;
            }
            else if (c == 'c') {  //Change user pass
                string user, pass, newPass;
                GetUsername(user);
                cout << "Enter password: ";
                cin >> pass;
                cout << "\nEnter new password: ";
                cin >> newPass;
                if (passServer.changePassword(make_pair(user, pass), newPass))
                    cout << "\nPassword changed for user " << user << endl;
                else cout << "\nERROR: Could not change user password!!" << endl;
            }
            else if (c == 'f') {  //Find new user
                string user;
                GetUsername(user);
                if (passServer.find(user))
                    cout << "\nUser '" << user << "' found." << endl;
                else cout << "ERROR: User '" << user << "' not found." << endl;
            }
            else if (c == 'd') {  //Dump the hash table
                passServer.dump();
            }
            else if (c == 's') {  //Print the size of hash table
                cout << "Size of hashtable is " << passServer.size() << endl;
            }
            else if (c == 'w') {  //Write hash table to file
                string filename;
                cout << "\nEnter password file name to write to: ";
                cin >> filename;
                if (!passServer.write_to_file(filename.c_str()))
                    cout << "\nERROR: Cannot write file " << filename << endl;
            }
            else if (c == 'x') {   //Terminate program
                running = false;
                break;
            }
            else {   //Print menu reset
                string toavoidawarning;
                toavoidawarning += c;
                if (toavoidawarning != "\0")
                    Menu();
            }
            
        }
        running = false;
    }
    return 0;
}

//Function Menu prints the menu
void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}


void GetServerSize(size_t& serverSize) 
{
    cout << "Enter hash table capacity: ";
    cin >> serverSize;
    cout << endl;
}


void GetUsername(string& user)
{
    cout << "Enter username: ";
    cin >> user;
}

pair<string, string> AddNewUser() 
{
    string user, pass;
    GetUsername(user);
    cout << "Enter password: ";
    cin >> pass;
    return make_pair(user, pass);
}
