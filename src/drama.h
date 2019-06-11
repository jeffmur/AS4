// ------------------------------------------------ drama.h -------------------------------------------------------
// Jeffrey Murray CSS 343 B
// Creation: 5/29/19
// Modified: 6/1/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Child class of Movie
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//       - Contains Movie Object
//       - (‘D’) are sorted by Director, then Title
// -----------------------------------------------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class Drama : public Movie {
    friend ostream & operator<<(ostream &, const Drama &);
public:
    ~Drama() override;
    explicit Drama(const string &);      // data is set equal to parameter

    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Drama &) const;
    bool operator>=(const Drama &) const;
};

#endif /* DRAMA_H */