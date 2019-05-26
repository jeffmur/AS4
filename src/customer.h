// Jeffrey Murray CSS 343 B SP19
// Created: 5/25/19
// Last Modified:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "nodedata.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Customer {

public:
    Customer(string first, string last, int ID);		// constructor from string to nodeData
    ~Customer();								        // destructor


private:
    string firstName;
    string lastName;
    int ID;

    //vector<Transactions*> customerHistory;

};

#endif  /* CUSTOMER_H */