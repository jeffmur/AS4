// ------------------------------------------------ hash.h --------------------------------------------------------
// Jeffrey Murray CSS 343 B
// Creation: 5/25/19
// Modified: 5/25/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Encapsulate customer data (Nodes)
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//       - Contains Customer Objects
//       - Uses basic hash by prime algorithm
//       - As well as a linked list to avoid collision (in the case of > SIZE customers in system)
// -----------------------------------------------------------------------------------------------------------------
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
    int hashFunction(int id);               // ID % size
    void insert(Customer &customer);        // add NodeData (customer info)
    Customer* find(int customerID);         // find customer by ID
    bool remove(int customerID);            // remove customer from array or linked list
    void display();                         // print could have overloaded <<

private:
    struct Node{
        Customer* data = NULL;
        Node* next = nullptr;
    };
    int SIZE = 57;
    vector<Node*> table;
};

#endif  /* HASH_H */