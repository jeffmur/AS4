#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "store.h"
using namespace std;

class Inventory : public Transaction
{
public:
    virtual ~Inventory();
    Inventory(Store * storePointer, ifstream& infile);

    void process();
};

#endif