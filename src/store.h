//
// Created by alexa on 6/6/2019.
//

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

#ifndef STORE_H
#define STORE_H

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

private:
    BinTree<Comedy> * comedyBST;
    BinTree<Classic> * classicBST;
    BinTree<Drama> * dramaBST;
    Hash * customerHashTable;
    vector<Transaction> * allTransactions;
};

#endif //AS4_STORE_H
