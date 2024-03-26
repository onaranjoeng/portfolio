// BY OSCAR NARANJO
// COP4530
// NOVEMBER 13, 2022

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <utility>
#include <vector>
#include <cstring>
#include <iterator>
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
namespace cop4530 {

    // max_prime is used by the helpful functions provided
    // to you.
    static const unsigned int max_prime = 1301081;
    // the default_capacity is used if the initial capacity 
    // of the underlying vector of the hash table is zero. 
    static const unsigned int default_capacity = 11;

    template <typename K, typename V>
    class HashTable {
    public:

        HashTable(size_t size);   //constructor
        ~HashTable();   //destructor

        bool contains(const K& k);  // check if key k is in the hash table.
        bool match(const pair<K, V>& kv); // check if key-value pair is in the hash table.
        bool insert(const pair<K, V>& kv);  // add the key-value pair kv into the hash table
        bool insert(pair<K, V>&& kv);  // move version of insert
        bool remove(const K& k);    // delete the key & corresponding value

        void clear();   // delete all elements in the hash table
        bool load(const char* filename);    // load the content of the file with name filename into the hash table
        void dump();    // display all entires in hash table
        bool write_to_file(const char* filename); // write all elements in the hash table into a file with name filename

        size_t getSize() { return currentSize; }   //member function to get currentSize


    private:

        size_t myhash(const K& k);  // return index of vector entry where k is stored
        size_t count = 0;
        vector<list<pair<K, V>> > htable;    // Chain linked hashTable list
        size_t currentSize;

        void makeEmpty();   // delete all elements in the hash table.
        void rehash();  // Called when the number of elements in the hash table is greater than the size of the vector.
        unsigned long prime_below(unsigned long);   // helper function for resizing
        void setPrimes(vector<unsigned long>&);

    };

#include "hashtable.hpp"
}
#endif

