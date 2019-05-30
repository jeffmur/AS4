#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

//   comedy movie (‘F’) sorted by Title, then Year it released

class Comedy : Movie {

public:
    virtual ~Comedy();
    Comedy(const string &);      // data is set equal to parameter

    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Comedy &) const;
    bool operator>=(const Comedy &) const;
};

#endif