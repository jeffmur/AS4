// Jeffrey Murray CSS 343 B SP19
// Created: 5/25/19
// Last Modified:

#ifndef HASH_H
#define HASH_H

#include "customer.h"
#include <list>
#include <string>

using namespace std;

class Hash {

    int SIZE = 100;
    list<Customer*> *table;

public:
    Hash(int size);							// constructor of hash table
    ~Hash();								// destructor, calls makeEmpty
    bool isEmpty() const;					// true if table is empty, otherwise false
    void makeEmpty();						// make the table empty so isEmpty returns true
    bool insert(NodeData* item);            // add NodeData (customer info)
    bool retrieve(NodeData &targetData, int key) const;

private:



// utility functions


};

#endif  /* HASH_H */