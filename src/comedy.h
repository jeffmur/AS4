// ------------------------------------------------ comedy.h -------------------------------------------------------
// Jeffrey Murray CSS 343 B
// Creation: 5/29/19
// Modified: 6/1/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Child class of Movie
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//       - Contains Movie Object
//       - (‘F’) sorted by Title, then Year it released
// -----------------------------------------------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
    friend ostream & operator<<(ostream &, const Comedy &);
public:
    Comedy();
    ~Comedy() override;
    explicit Comedy(const string &);      // data is set equal to parameter

    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Comedy &) const;
    bool operator>=(const Comedy &) const;
};

#endif /* COMEDY_H */
