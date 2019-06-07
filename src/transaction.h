#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <fstream>
#include "store.h"

using namespace std;

class Transaction
{
public:
    Transaction();
    ~Transaction();

    virtual void setData(fstream& infile);
    virtual void process();
    virtual void display() const;


private:
    int transactionID;
    int customerID;
    char transType;
    char mediaType;
    char movieType;
    string movieData;
    string movieName;
    int releaseYear;
    int releaseMonth;
    string majorActor;
    Store * store;

};

#endif