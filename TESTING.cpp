#include <iostream>
#include <fstream>
#include <string>
// include header files to test functionality

#include "src/customer.h"
#include "src/hash.h"

using namespace std;

void buildCustomers(){
    ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    //ifstream infileC("data/data4customers.txt");

    if (!infileC) {
        cout << "File could not be opened." << endl;
        return;
    }
    Hash test = Hash(10);
    for(;;){
        if(infileC.eof()) { break; }
        if(infileC.bad()) { continue; }
        string last, first;
        int id = -1;
        infileC >> id >> last >> first;

        // valid Customer ID
        if (id > 999 && id <= 9999) {
            Customer *c = new Customer(last, first, id);
            test.insert(*c);
        }
    }
    test.display();

    bool found = test.find(4444);
    cout << "Found? " << ( found ? "True" : "False") << endl;

    bool deleted = test.remove(2000);
    cout << "Deleted? " << ( deleted ? "True" : "False") << endl;

    test.display();
}

int main() {
    buildCustomers();
}