#include <iostream>
#include <fstream>
#include <string>
// include header files to test functionality

#include "src/customer.h"
#include "src/hash.h"

using namespace std;

int main() {
    ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    if (!infileC) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    Hash test = Hash(10);
    for(;;){
        if(infileC.eof()) { break; }

        string last, first;
        int id = -1;
        infileC >> id >> last >> first;

        // valid Customer ID
        if (id > 999 && id <= 9999) {
            Customer c = Customer(last, first, id);
            test.insert(&c);
        }

    }

}