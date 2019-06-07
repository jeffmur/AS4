//
// Created by alexa on 6/6/2019.
//

#include "history.h"



History::History(Store * storePointer, fstream & infile)
{
    store = storePointer;
    infile >> customerID;

}

void History::process()
{
    //get customer
    //print out customer's transaction history
    store->customerHashTable->find(customerID.displayHistory());
}