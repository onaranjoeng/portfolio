// BY OSCAR NARANJO
// COP4530
// NOVEMBER 13, 2022

using namespace std;
#include "hashtable.h"


// Create a hash table, where the size of the vector is set to
// prime_below(size) (where size is default to 101), where
// prime_below() is a private member function of the HashTableand provided to
template<typename K, typename V>
inline HashTable<K, V>::HashTable(size_t size)
{
    htable.resize(prime_below(size));  //Init to prime based on given size
    currentSize = 0;
}

//  Delete all elements in hash table.
template<typename K, typename V>
inline HashTable<K, V>::~HashTable()
{
    clear();
}

// check if key k is in the hash table
template<typename K, typename V>
inline bool HashTable<K, V>::contains(const K& k)
{
    auto& List = htable[myhash(k)];

    // loop to check if value is in the hashtable
    for (auto& htable : List)
        if (htable.first == k)
            return true;    
    return false;
}

// check if key-value pair is in the hash table.
template<typename K, typename V>
inline bool HashTable<K, V>::match(const pair<K, V>& kv)
{
    auto& List = htable[myhash(kv.first)];

    // loop to check if both the Key and Value exist 
    if (List.size() > 0) 
    {
        for (auto& theList : List)
        {
            if (theList.first == kv.first)
                if (theList.second == kv.second)
                    return true;    // Key and Value are both in table
        }
        return false;
    }
    else return false;
}

// add the key-value pair kv into the
// hash table.Don't add if kv is already in the hash table. If the key is the hash
// table but with a different value, the value should be updated to the new one
// with kv.Return true if kv is inserted or the value is updated; return false
// otherwise(i.e., if kv is in the hash table).
template<typename K, typename V>
inline bool HashTable<K, V>::insert(const pair<K, V>& kv)
{
    auto& List = htable[myhash(kv.first)];
    //Checks to see if KV pair is in table, updates it with proper values
    if (List.size() > 0) 
    {
        for (auto& theList : List)
        {
            if (theList.first == kv.first)
                if (theList.second == kv.second)
                    return false;
                else { 
                    theList.second = kv.second;
            break;
            }
            else { 
                List.push_back(kv);
            break; 
            }
        }
    }
    else List.push_back(kv);

    currentSize++;
    if (currentSize > htable.size())
        rehash();   //Increase size of hashtable
    return true;
}

//  move version of insert.
template<typename K, typename V>
inline bool HashTable<K, V>::insert(pair<K, V>&& kv)
{
    auto& List = htable[myhash(kv.first)];

    if (List.size() > 0) {
        for (auto& theList : List) {
            if (theList.first == kv.first)
                if (theList.second == kv.second)
                    return false;
                else { 
                    swap(theList.second, kv.second); 
            break; 
            }
            else { 
                List.push_back(std::move(kv)); 
            break; }

        }
    }
    else List.push_back(std::move(kv));

    currentSize++;
    if (currentSize > htable.size())
        rehash();   //Increase size of hashtable
    return true;
}

// delete the key k and the corresponding value if it is
// in the hash table.Return true if k is deleted, return false otherwise(i.e., if key k
// is not in the hash table).
template<typename K, typename V>
inline bool HashTable<K, V>::remove(const K& k)
{
    auto& List = htable[myhash(k)];
    bool flag = false;
    unsigned int index = 0;

    for (auto& theList : List) 
    {
        //if Key is found
        if (theList.first == k) 
        {
            flag = true;
            auto itr = List.begin();
            advance(itr, index);
            List.erase(itr);
            --currentSize;  
            break;
        }
        index++;
    }
    return flag;
}

// delete all elements in the hash table
template<typename K, typename V>
inline void HashTable<K, V>::clear()
{
    makeEmpty();
}

// load the content of the file with name
// filename into the hash table.In the file, each line contains a single pair of key
// and value, separated by a white space.
template<typename K, typename V>
inline bool HashTable<K, V>::load(const char* filename)
{
    // open file
    ifstream infile;
    infile.open(filename);

 
    string line;
    while (getline(infile, line)) 
    {
        istringstream iss(line);
        string user, pass;
        iss >> user >> pass;    
        pair<std::string, string> p = make_pair(user, pass);
        insert(p);
    }
    infile.close();
    return true;
}

// display all entries in the hash table. If an entry contains multiple
// key - value pairs, separate them by a semicolon character(:)
template<typename K, typename V>
inline void HashTable<K, V>::dump()
{
    int Index = 0;
    cout << endl;

    for (auto& theList : htable) 
    {
        int i = 0;
        cout << "v[" << Index++ << "]: ";

       for (auto& x : theList) {
          
          if (++i > 1)
                cout << ":";
            cout << x.first << " " << x.second;
        }
        cout << endl;
    }
}


// write all elements in the hash table
// into a file with name filename.Similar to the file format in the load function,
// each line contains a pair of key - value pair, separated by a white space.
template<typename K, typename V>
inline bool HashTable<K, V>::write_to_file(const char* filename)
{
    ofstream ofile;
    ofile.open(filename);
    
    for (auto& theList : htable)
        for (auto& x : theList)
            ofile << x.first << " " << x.second << "\n";
    ofile.close();
    return true;
}

// delete all elements in the hash table. The public interface clear() will call this function.
template<typename K, typename V>
inline void HashTable<K, V>::makeEmpty()
{
    for (auto& theList : htable)
        theList.clear();
    currentSize = 0;
}

// Called when the number of elements in the hash table is greater than the size of the vector.
template<typename K, typename V>
inline void HashTable<K, V>::rehash()
{
    vector<list<pair<K, V> > > oldTable = htable;
    oldTable.resize(prime_below(2 * htable.size()));

    for (auto& theList : htable)
        theList.clear();

    //copy table
    currentSize = 0;
    for (auto& theList : oldTable)
        for (auto& x : theList)
            insert(std::move(x));

}

// return index of vector entry where k is stored
template<typename K, typename V>
inline size_t HashTable<K, V>::myhash(const K& k)
{
    size_t index = 0;
    for (auto ch : k)
        index = 37 * index + ch;
    return index % htable.size();
}

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below(unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }
    // now: 2 <= n < max_prime
    std::vector <unsigned long> v(n + 1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }
    return 2;
}
//Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;
    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();
    for (i = 2; i < n; ++i)
        vprimes[i] = 1;
    for (i = 2; i * i < n; ++i)
    {
        if (vprimes[i] == 1)
            for (j = i + i; j < n; j += i)
                vprimes[j] = 0;
    }
}