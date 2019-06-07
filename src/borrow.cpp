//
// Created by alexa on 6/6/2019.
//

#include "borrow.h"

Borrow::Borrow(Store *storePointer, ifstream &infile)
{
    store = storePointer;
    infile >> customerID;
    infile >> mediaType;
    infile >> movieType;
    infile->getline(movieData); //separate out into relevant data later
}