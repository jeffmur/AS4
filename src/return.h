#ifndef RETURN_H
#define RETURN_H

#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "store.h"
using namespace std;

class Return : public Transaction
{
public:
    virtual ~Return();
    Return(Store * storePointer, ifstream& infile);

    void process();
};

#endif