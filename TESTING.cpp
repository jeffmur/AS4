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
#include "bst.h"

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
    auto *comedyBST = new BinTree<Comedy>();
    auto *classicBST = new BinTree<Classic>();
    auto *dramaBST = new BinTree<Drama>();
    for(;;){
        if(infile.eof()) { break; }

        string data;
        getline(infile, data);

        if(data.empty() || data == "\r") { continue; }

        // comedy
        if(data[0] == 'F'){
            auto *f = new Comedy(data);
            //cout << *f << endl;
            comedyBST->insert(f);
        }
        // drama
        else if (data[0] == 'D') {
            auto *d = new Drama(data);
            //cout << *d << endl;
            dramaBST->insert(d);
        }
        // classic
        else if (data[0] == 'C') {
            auto *c = new Classic(data);
            //cout << *c << endl;
            classicBST->insert(c);
        }

        // Movies will assign each string to genre based on char
        // Possible build tree function to initialize data
    }
//    Classic *cA = new Classic("C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942\r");
//    Classic *cB = new Classic("C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942\r");
//    Comedy *fA = new Comedy("F, 10, Woody Allen, Annie Hall, 1977\r");
//    cout << "cA == cB? " << ( *cA == *cB ? "True" : "False") << endl;
    comedyBST->display();
    classicBST->display();
    dramaBST->display();

}

void processTransactions(ifstream& infile)
{

}

int main() {
    //ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    //ifstream infileC("data/data4customers.txt");
    //buildCustomers(infileC);
    ifstream infileM("data/data4movies.txt");
    buildMovies(infileM);
    ifstream infileT("data/data4commands.txt");
    processTransactions(infileT);

}