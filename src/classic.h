#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

//   classics (‘C’) are sorted by Release date, then Major actor

class Classic : Movie {

public:
    virtual ~Classic();
    Classic(const string &);      // data is set equal to parameter

    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Classic &) const;
    bool operator>=(const Classic &) const;

    void setReleaseMonth(int releaseMonth);
    int getReleaseMonth() const;

private:
    int releaseMonth;
    string majorFirst;
    string majorLast;
};

#endif
