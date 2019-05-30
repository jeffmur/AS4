#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class Classic : Movie {
    friend ostream & operator<<(ostream &, const Movie &);

public:
    virtual ~Classic();
    Classic(const string &);      // data is set equal to parameter

    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;

    int quanity;

private:
    char genre;
    string director, title, actorFirst, actorLast;
    int releaseYear;
    int releaseMonth;
};

#endif
