#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movies.h"
using namespace std;

class Drama : Movies {
    friend ostream & operator<<(ostream &, const Movies &);

public:
    virtual ~Drama();
    Drama(const string &);      // data is set equal to parameter

    // set class data from data file
    // returns true if the data is set, false when bad data, i.e., is eof

    bool operator==(const Movies &) const;
    bool operator!=(const Movies &) const;
    bool operator<(const Movies &) const;
    bool operator>(const Movies &) const;
    bool operator<=(const Movies &) const;
    bool operator>=(const Movies &) const;

    int quanity;

private:
    char genre;
    string director, title;
    int releaseYear;
};

#endif
