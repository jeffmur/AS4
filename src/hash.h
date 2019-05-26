// Jeffrey Murray CSS 343 B SP19
// Created: 5/25/19
// Last Modified:

#ifndef HASH_H
#define HASH_H

#include "customer.h"
#include <vector>
#include <string>

using namespace std;

class Hash {

public:
    Hash(int size);							// constructor of hash table
    ~Hash();								// destructor, calls makeEmpty
    //bool isEmpty() const;					// true if table is empty, otherwise false
    //void makeEmpty();						// make the table empty so isEmpty returns true
    int hashFunction(int id);               // ID % size
    void insert(Customer &customer);        // add NodeData (customer info)
    bool find(int customerID);
    bool remove(int customerID);
    void display();

private:
    struct Node{
        Customer* data = NULL;
        Node* next = nullptr;
    };
    int SIZE = 10;
    vector<Node*> table;
};

#endif  /* HASH_H */