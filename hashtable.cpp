#include "hashtable.h"
#include <fstream>
#include <cstring>
#include <string>
#include <utility>
#include <crypt.h>
#include <unistd.h>

namespace cop4530
{

HashTable::HashTable()
{
    bucketVector.resize(default_capacity);
}

HashTable::HashTable(size_t n)
{
    bucketVector.resize(prime_below(n));
}

//Iterates through the vector and clears all the lists within each bucket
HashTable::~HashTable()
{
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        bucketVector[i].clear();
    }

    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        bucketVector.pop_back();
    }
}

// Encrypts a string *NOT WORKING CORRECTLY*
string HashTable::encrypt(string password)
{
    char salt[] = "$1$########";

    string output = crypt(password.c_str(), salt);

    return output;
}

// Checks to see if a user exists
bool HashTable::findUser(pair< string, string > check)
{
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            if (itr->first == check.first && itr->second == parsePass(encrypt(check.second))){
                return true;
            }
        }
    }

    return false;
}

// Adds a user to the Hash Table if it does not already exist.  Returns true on successful add
bool HashTable::addUser(pair< string, string > add_pair)
{
    // Check to see if the user exists
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            if (itr->first == add_pair.first){
                return false;
            }
        }
    }

    // User doesn't exist, so encrypt the password and add them
    add_pair.second = parsePass(encrypt(add_pair.second));

    // Add the user
    bucketVector[Index(add_pair.first)].push_back(add_pair);
    return true;
}

// Removes a user from the Hash Table, returns true on successful delete
bool HashTable::remove(string username)
{
    // Check to see that the user exists.  If so, erase it.
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            if (itr->first == username){
                bucketVector[i].erase(itr);
                return true;
            }
        }
    }

    // User not found
    return false;
}

// Modifys a users password, returns true on successful password change
bool HashTable::changePassword(pair<string, string> change_pair, string newpass)
{
    // Check to see that the user exists.  If so, erase it.
    if (findUser(change_pair)) {
        change_pair.second = parsePass(encrypt(newpass));
        return true;
    }

    // User not found
    return false;
}

// Returns the size of the Hash Table (number of users)
int HashTable::size()
{
    int size = 0;

    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            size++;
        }
    }

    return size;
}

// Prints the contents of the Hash Table
void HashTable::print()
{
    // Check to see that the user exists.  If so, erase it.
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        cout << "v[" << i <<"]: ";
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            cout << itr->first << ":" << itr->second << "\t";
        }
        cout << endl;
    }
}

// Parses an entry to determine the username and password
pair<string, string> HashTable::parseEntry(string entry)
{
    pair<string, string> output;

    string user;
    int location = 0;

    // Add characters to the user name until the colon is encountered
    for (unsigned int i = 0; i < entry.size(); i++) {
        if (entry[i] != ':') {
            user += entry[i];
        }
        else {
            break;
        }
        location++;
    }

    string pass;

    // Add characters to the password
    for (unsigned int i = location; i < entry.size(); i++) {
        pass += entry[i];
    }

    output.first = user;
    output.second = pass;

    return output;
}

// Takes the salt characters out of an encrypted password
string HashTable::parsePass(string unparsed)
{
    string output;

    // output = the password AFTER "$1$########$"
    output = unparsed.substr(12);

    return output;
}

// Reads in data from a file and adds entries to the hash table
void HashTable::loadFile(string fileName)
{
    // Clear the vector
    int capacity = bucketVector.size();
    bucketVector.clear();
    bucketVector.resize(capacity);

    ifstream in;
    in.open(fileName.c_str());

    while(!in.eof()) {
        string entry;

        in >> entry;

        if (entry == "\n" || entry == "") {
            continue;
        }
        pair<string, string> parsed;
        parsed = parseEntry(entry);

        addUser(parsed);

    }

    in.close();
}

// Writes data to a file
void HashTable::writeFile(string fileName)
{
    ofstream outFile;
    outFile.open(fileName.c_str());

    // Check to see that the user exists.  If so, erase it.
    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            outFile << itr->first << ":" << itr->second << endl;
        }
    }

    outFile.close();
}

// GUI function, returns a list of users
list<string> HashTable::users()
{
    list<string> output;

    for (unsigned int i = 0; i < bucketVector.size(); i++) {
        for (list < pair <string, string> >::iterator itr = bucketVector[i].begin(); itr != bucketVector[i].end(); itr++) {
            output.push_back(itr->first);
        }
    }

    return output;
}

//Returns the bucket index where the pair should be inserted
unsigned int HashTable::Index (const string & key)
{
    return hash_function(key) % bucketVector.capacity();
}

//Returns the hashed index
unsigned int HashTable::hash_function (const string & s)
{
    unsigned int i;
    unsigned long bigval = s[0];
    for (i = 1; i < s.size(); ++i)
      bigval = ((bigval & 65535) * 18000) + (bigval >> 16) + s[i];
    bigval = ((bigval & 65535) * 18000) + (bigval >> 16);
    return bigval & 65535;

}

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
unsigned int HashTable::prime_below (unsigned int n)
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
    return 0;
      }

    // now: 2 <= n < max_prime
    vector <unsigned int> v (n + 1);
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
void HashTable::setPrimes(vector<unsigned int>& vprimes)
{
    //int root;
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
      vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
      {
    if (vprimes[i] == 1)
      for(j = i + i ; j < n; j += i)
        vprimes[j] = 0;
      }
}

}
