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

void Hash::insert(Customer &customer) {
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

bool Hash::find(int custID) {
    int index = hashFunction(custID);
    Node* cur = table[index];

    while(cur != nullptr){
        if(custID == cur->data->ID)
            return true;
        cur = cur->next;
    }
    return false;
}

// delete and NULL target Node based on customer ID
bool Hash::remove(int custID) {

    // if custID exits
    if(find(custID)){
        int index = hashFunction(custID);
        Node* it = table[index];

        // if on vector delete
        if(it->data->ID == custID){
            delete it->data;
            if(it->next != NULL)
                table[index] = it->next;
            else
                table[index] = NULL;
            delete it;
            return true;
        }
        else {
            // walk through linked list
            Node* prev = table[index];
            it = prev->next;
            while (it != nullptr) {
                // delete and assign pointer
                if (custID == it->data->ID) {
                    prev->next = it->next;
                    delete it->data;
                    delete it;
                    return true;
                }
                it = it->next;
                prev = prev->next;
            }
        }
    }
    else
        // not found, leaves Hash unchanged
        return false;
}

// print each values in vector and linked list if applicable
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
