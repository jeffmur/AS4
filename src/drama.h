#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class Drama : Movie {
    friend ostream & operator<<(ostream &, const Movie &);

public:
    virtual ~Drama();
    Drama(const string &);      // data is set equal to parameter

    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;

    int quanity;

private:
    char genre;
    string director, title;
    int releaseYear;
};

#endif
