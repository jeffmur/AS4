#include "hash.h"

// for resizing or initial setup of Hash Table
Hash::Hash(int size){
    SIZE = size;
    table.resize(size);
}

Hash::~Hash(){}

int Hash::hashFunction(int id) {
    return (id % SIZE);
}

bool Hash::insert(Customer &customer) {
    int index = hashFunction(customer.ID);
    cout << customer << " " << index << endl;

    Node* toAdd = new Node();
    toAdd->data = &customer;
    toAdd->next = nullptr;

    if(table[index] != NULL){
        Node* old = new Node();
        old->data = table[index]->data;
        old->next = table[index]->next;
        toAdd->next = old;
    }

    table[index] = toAdd;
}


