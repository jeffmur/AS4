// ------------------------------------------------ store.h -------------------------------------------------------
// Jeffrey Murray, Alex Hilwa CSS 343 B
// Creation: 6/6/19
// Modified: 6/11/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - main interface with parsing files
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//         - Includes data structures:
//              - Hash Table O(1)
//              - Binary Search Tree O(n)
//         - Uses inheritance classes (Classic, Comedy and Classic) of parent Movie
//
// Input:  data4commands.txt
//         data4customers.txt
//         data4movies.txt
// -----------------------------------------------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "customer.h"
#include "hash.h"
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "bst.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
class Store
{
public:
    Store();
    ~Store();

    void buildCustomers(ifstream& infile);                      // creates Hash Table and inserts Customer Objects
    void buildMovies(ifstream& infile);                         // creates BSTs and inserts based on genre
    void processCommands(ifstream& infile);                     // processes incoming commands
    void displayAll() const;                                    // pretty print for Movies
    string combineV(vector<string> data);                       // strips the movie data from raw data
    void addTransaction(string action, int custID, Movie* ptr); // adds to customer and global transaction history

private:
    BinTree<Comedy> *comedyBST;         // stores all Comedy movies (sorted by Title, then Year it released)
    BinTree<Classic> *classicBST;       // stores all Classic movies (sorted by Release date, then Major actor)
    BinTree<Drama> *dramaBST;           // stores all Drama movies (sorted by Director, then Title)
    Hash *customerHashTable;            // stores all customers information (Encapsulation)
    vector<string> allTransactions;     // no actual purpose or use (just for logging)
};

#endif /* STORE_H */
