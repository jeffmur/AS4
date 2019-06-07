//
// Created by alexa on 6/6/2019.
//

#include "return.h"
#include <sstring>
#include <string>


Return::Return(Store * storePointer, ifstream * infile)
{
    store = storePointer;
    infile >> customerID;
    infile >> mediaType;
    infile >> movieType;


    string token;
    infile->getline(movieData); //separate out into relevant data later
    stringstream ss(movieData);
    vector<string> result;
    while(getline(s1, token, ','))
    {
        result.push_back(token);
    }
    switch(mediaType): {
        case 'F': {
            movieName = result.at(0);
            break;
        }
    }



}

void Return::process()
{

}