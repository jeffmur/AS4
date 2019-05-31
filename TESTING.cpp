#include <iostream>
#include <fstream>
#include <string>
// include header files to test functionality

#include "src/customer.h"
#include "src/hash.h"
#include "src/movie.h"
#include "src/comedy.h"

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

void buildMovies(ifstream& infile){
//    if (!infile) {
//        cout << "File could not be opened." << endl;
//        return;
//    }
//    // build Trees ?
//    for(;;){
//        if(infile.eof()) { break; }
//
//        string data;
//        getline(infile, data);
//
//        if(data.empty() || data == "\r") { continue; }
//
//        Movie *m = new Movie(data);
//
//        // Movies will assign each string to genre based on char
//        // Possible build tree function to initialize data
//    }
    Movie *classicA = new Movie("C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942\r");
    Movie *classicB = new Movie("C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942\r");
    Movie *comedyA = new Movie("F, 10, Woody Allen, Annie Hall, 1977\r");
    cout << "Equal? " << ( *classicA == *comedyA ? "True" : "False") << endl;
}

int main() {
    //ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    //ifstream infileC("data/data4customers.txt");
    //buildCustomers(infileC);
    ifstream infileM("data/data4movies.txt");
    buildMovies(infileM);
}