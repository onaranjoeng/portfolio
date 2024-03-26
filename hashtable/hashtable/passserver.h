// BY OSCAR NARANJO
// COP4530
// NOVEMBER 13, 2022

#ifndef PASSSERVER_H
#define PASSSERVER_H

#include "hashtable.h"
#include "base64.h"

using namespace std;

const int MAXSIZE = 100;

namespace cop4530 {

    class PassServer : public HashTable <string, string> {
    public:
        PassServer(size_t size);  // constructor
        ~PassServer();  // destructor

        bool load(const char* filename);    // load pass file into table
        bool addUser(pair<string, string>& kv);    // add a new user/pass, encrypt
        bool addUser(pair<string, string>&& kv);   // move version of addUser
        bool removeUser(const string& k);   // delete existing user with name K
        bool changePassword(const pair<string, string>& p, const string& newpassword); // change password
        bool find(const string& user);  // check if a user exists in table
        void dump();    // show the structore and contetns of table
        bool write_to_file(const char* filename);   // save user/pass to file
        size_t size();  // return size of HashTable
       

    private:

        string encrypt(const string& str); //encrypt the str
        string decrypt(const string& str); //crypt the str
        string convertToString(BYTE* a, int size);
        void convertToByte(BYTE* a, string str);
    };
}


#endif
