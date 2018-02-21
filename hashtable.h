#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <windows.h>
#include <wincrypt.h>
//#include <crypt.h>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <stdlib.h>


using namespace std;

namespace cop4530
{

static const unsigned int max_prime = 64997;
static const unsigned int default_capacity = 11;

class HashTable
  {
  public:
    HashTable();
    HashTable(size_t n);
    ~HashTable();

    bool addUser(pair<string, string>);
    bool remove(string);
    bool findUser(pair<string, string>);
    bool changePassword(pair<string, string>, string);

    pair<string, string> parseEntry(string);
    string encrypt(string);
    string parsePass(string);

    void print();
    int size();

    void loadFile(string);
    void writeFile(string);

    // GUI functions
    list<string> users();
    int buckets() { return bucketVector.size(); }

  private:
    unsigned int Index (const string &);
    unsigned int hash_function   (const string& );
    unsigned int prime_below(unsigned int);
    void setPrimes(vector<unsigned int> &);
    vector < list < pair <string, string> > > bucketVector;
  };
}

#endif
