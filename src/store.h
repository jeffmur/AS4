//
// Created by alexa on 6/6/2019.
//

#ifndef STORE_H
#define STORE_H


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
// include header files to test functionality

#include "customer.h"
#include "hash.h"
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "bst.hpp"
#include "transaction.h"
#include "history.h"
#include "inventory.h"
#include "borrow.h"
#include "return.h"

using namespace std;
class Store
{
public:
    Store();
    ~Store();

    void buildCustomers(ifstream& infile);
    void buildMovies(ifstream& infile);
    void processCommands(ifstream& infile);
    void displayAll() const;
    string combineV(vector<string> data);
    void addTransaction(int custID, Movie* ptr);

private:
    BinTree<Comedy> *comedyBST;
    BinTree<Classic> *classicBST;
    BinTree<Drama> *dramaBST;
    Hash *customerHashTable;
    vector<string> allTransactions;
};

#endif //AS4_STORE_H
