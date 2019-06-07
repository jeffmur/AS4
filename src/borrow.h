#ifndef BORROW_H
#define BORROW_H

#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "store.h"
using namespace std;

class Borrow : public Transaction
{
public:
    virtual ~Borrow();
    Borrow(Store * storePointer, ifstream& infile);

    void process();
};

#endif