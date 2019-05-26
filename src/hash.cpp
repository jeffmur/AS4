#include "hash.h"

// for resizing or initial setup of Hash Table
Hash::Hash(int size){
    SIZE = size;
    table.resize(size);
}

Hash::~Hash(){
    for(int i = 0; i < SIZE; i++){
        Node* cur = table[i];
        while(cur != nullptr){
            Node* toDelete = cur;
            delete cur->data;
            cur = cur->next;
            delete toDelete;
        }
    }
    table.clear();
}

int Hash::hashFunction(int id) {
    return id % SIZE;
}

bool Hash::insert(Customer &customer) {
    int index = hashFunction(customer.ID);
    //cout << customer << " " << index << endl;

    Node* toAdd = new Node();
    toAdd->data = &customer;
    toAdd->next = nullptr;

    if(table[index] != NULL){
        Node* old = table[index];
        toAdd->next = old;
    }

    table[index] = toAdd;
}

void Hash::display(){
    printf("\nIndex: \t\t Links: \n");
    for(int i = 0; i < SIZE; i++){
        if(table[i] == NULL)
            continue;
        Node* cur = table[i];
        cout << i << " ";
        while(cur != nullptr){
            cout << "-> " << *cur->data;
            cur = cur->next;
        }
        cout << endl;
    }
}
