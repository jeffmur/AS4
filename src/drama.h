#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

//   dramas (‘D’) are sorted by Director, then Title

class Drama : public Movie {

public:
    virtual ~Drama();
    Drama(const string &);      // data is set equal to parameter

    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Drama &) const;
    bool operator>=(const Drama &) const;
};

#endif