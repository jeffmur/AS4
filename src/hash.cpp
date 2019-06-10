#include "hash.h"

//Constructor, accepts an initial size
Hash::Hash(int size){
    SIZE = size;
    table.resize(size);
}

//Destructor
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

// ------------------------------------hashFunction-----------------------------
// Description: A simple hash function, hashes the given id into an index
// Precondition: None
// Postcondition: None
int Hash::hashFunction(int id) {
    return id % SIZE;
}

// ------------------------------------insert-----------------------------
// Description: Inserts the given customer into the hash table
// Precondition: None
// Postcondition: Customer is in the hash table
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

// ------------------------------------find-----------------------------
// Description: Searches the hash table for a customer with the given
// customer id, then returns a pointer to it. Returns nullptr if not
// found
// Precondition: None
// Postcondition: None
Customer* Hash::find(int custID) {
    int index = hashFunction(custID);
    Node* cur = table[index];

    while(cur != nullptr){
        if(custID == cur->data->ID)
            return cur->data;
        cur = cur->next;
    }
    cout << "ERROR: Not a valid customer ID! : " << custID << endl;
    return nullptr;
}

// ------------------------------------remove-----------------------------
// Description: Searches the hash table for a customer with the given
// customer id, then deletes the customer
// Precondition: None
// Postcondition: Customer with the given id is no longer in the hash table
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
    // not found, leaves Hash unchanged
    return false;
}

// ------------------------------------display-----------------------------
// Description: Prints out the contents of the hash table
// Precondition: None
// Postcondition: None
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
