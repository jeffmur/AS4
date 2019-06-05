#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
// include header files to test functionality

#include "src/customer.h"
#include "src/hash.h"
#include "src/classic.h"
#include "src/drama.h"
#include "src/comedy.h"
#include "src/bst.h"

using namespace std;

void buildCustomers(ifstream& infile){
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }
    Hash test = Hash(10);
    for(;;){
        if(infile.eof()) { break; }
        if(infile.bad()) { continue; }
        string last, first;
        int id = -1;
        infile >> id >> last >> first;

        // valid Customer ID
        if (id > 999 && id <= 9999) {
            Customer *c = new Customer(last, first, id);
            test.insert(*c);
        }
    }
    test.display();

    bool found = test.find(4444);
    cout << "Found 4444? " << ( found ? "True" : "False") << endl;

    bool deleted = test.remove(2000);
    cout << "Deleted 2000? " << ( deleted ? "True" : "False") << endl;

    test.display();
}

void buildMovies(ifstream& infile) {
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }
    auto comedyBST = new BinTree<Comedy>();
    auto classicBST = new BinTree<Classic>();
    auto dramaBST = new BinTree<Drama>();
    for(;;){
        if(infile.eof()) { break; }

        string data;
        getline(infile, data);

        if(data.empty() || data == "\r") { continue; }

        // comedy
        if(data[0] == 'F'){
            auto *f = new Comedy(data);
            comedyBST->insert(f);
        }
        // drama
        else if (data[0] == 'D') {
            auto *d = new Drama(data);
            dramaBST->insert(d);
        }
        // classic
        else if (data[0] == 'C') {
            auto *c = new Classic(data);
            classicBST->insert(c);
        }
    }

    comedyBST->display();
    classicBST->display();
    dramaBST->display();

    // ADD TRANSACTIONS HERE?


    // mem garbage collection
    delete dramaBST;
    delete comedyBST;
    delete classicBST;
}

int main() {
    //ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    //ifstream infileC("data/data4customers.txt");
    //buildCustomers(infileC);
    ifstream infileM("data/data4movies.txt");
    buildMovies(infileM);

    return 0;
}