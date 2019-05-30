#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include <fstream>
#include "movies.h"
using namespace std;

class Classic : Movies {
    friend ostream & operator<<(ostream &, const Movies &);

public:
    virtual ~Classic();
    Classic(const string &);      // data is set equal to parameter

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
    string director, title, actorFirst, actorLast;
    int releaseYear;
    int releaseMonth;
};

#endif
