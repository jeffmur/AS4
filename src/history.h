#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "store.h"
using namespace std;

class History : public Transaction
{
public:
    virtual ~History();
    History(Store * storePointer, ifstream& infile);

    void process();
};

#endif