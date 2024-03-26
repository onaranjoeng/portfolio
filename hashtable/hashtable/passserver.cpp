// BY OSCAR NARANJO
// COP4530
// NOVEMBER 13, 2022

#include "passserver.h"
using namespace std;
using namespace cop4530;

// constructor, create a hash table of the specified size.
// You just need to pass this size parameter to the constructor of the HashTable.
PassServer::PassServer(size_t size = 101) : HashTable<string, string>(size) {}

// destructor
PassServer::~PassServer() {}

// load a password file into the HashTable object.Each line contains a 
// pair of usernameand an un - encrypted password.Read in the name 
// and encrypt the password and populate the hash table.
bool PassServer::load(const char* filename)
{
    return HashTable<string, string>::load(filename);
}

// add a new username and password.The password passed in
// is in plaintext, it should be encrypted before insertion.
bool PassServer::addUser(pair<string, string>& kv)
{
    pair<string, string> eKV = make_pair(kv.first, encrypt(kv.second));
    return HashTable<string, string>::insert(eKV);
}

// move version of addUser
bool PassServer::addUser(pair<string, string>&& kv) 
{
    return false;
}

// delete an existing user with username k.
bool PassServer::removeUser(const string& k) 
{
    return HashTable<string, string>::remove(k);
}

// change an existing user's password. Note that both
// passwords passed in are in plaintext.They should be encrypted before
// you interact with the hash table.If the user is not in the hash table,
// return false.If p.second does not match the current password, return
// false.Also return false if the new passwordand the old password are the
// same(i.e., we cannot update the password).
bool PassServer::changePassword(const pair<string, string>& p, const string& newpassword) 
{

    if (find(p.first)) 
    {
        pair<string, string> oldEKV = make_pair(p.first, encrypt(p.second));

        if (HashTable<string, string>::match(oldEKV)) 
        {  //if p.second matches
            pair<string, string> eKV = make_pair(p.first, encrypt(newpassword));
            if (!HashTable<string, string>::match(eKV)) //if p.second != newPassword
                return HashTable<string, string>::insert(eKV);
            else return false;
        }
        else return false;
    }
    else return false;
}

//check if a user exists(if user is in the hash table).
bool PassServer::find(const string& user)
{
    return HashTable<string, string>::contains(user);
}

// show the structure and contents of the HashTable object to
// the screen. Same format as the dump() function in the HashTable class template.
void PassServer::dump() 
{
    HashTable<string, string>::dump();
}

// Un-encrypt the password from the data structrure and save the 
// username and password combination into a file. Same format as 
// the write_to_file() function in the HashTable class template.
bool PassServer::write_to_file(const char* filename)
{
    return HashTable<string, string>::write_to_file(filename);
}

// return the size of the HashTable (the number of
// username / password pairs in the table).
size_t PassServer::size() 
{
    return HashTable<string, string>::getSize();
}

string PassServer::encrypt(const string& str)
{
    size_t lenout;
    string strOut;

    const char* c1 = str.c_str();
    lenout = str.size() + (str.size()/3) + 1;

    BYTE* password = new BYTE[MAXSIZE];
    BYTE* passEncrypt = new BYTE[MAXSIZE];
    
    convertToByte(password, str);

    base64_encode(password, passEncrypt, str.size(), 1);

    strOut = convertToString(passEncrypt, lenout);

    return strOut;
}

string PassServer::decrypt(const string& str)
{
    size_t lenout;
    string strOut;

    const char* c1 = str.c_str();
    lenout = str.size() ;

    char* strDecrypt = new char[lenout];

    base64_decode(c1, strDecrypt, lenout);

    strOut = convertToString(strDecrypt, lenout);

    return strOut;
}


string PassServer::convertToString(BYTE* a, int size)
{
   
    string s(a, sizeof(a));
    
    
  //  int i;
  //  string s = "";
  //  for (i = 0; i < size; i++) {
  //      if (a[i] =! nullptr) {
  //          s = s + a[i];
  //      }
  //  }
    return s;
}



void PassServer::convertToByte(BYTE* a, string str )
{
    for (size_t i = 0; i < str.size(); i++) {
        a[i] = BYTE(str[i]);
    }

}

