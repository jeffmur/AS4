// ------------------------------------------------ classic.h ------------------------------------------------------
// Jeffrey Murray CSS 343 B
// Creation: 5/29/19
// Modified: 6/1/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Child class of Movie
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//       - Contains Movie Object
//       - (‘C’) are sorted by Release date, then Major actor
// -----------------------------------------------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class Classic : public Movie {
    friend ostream & operator<<(ostream &, const Classic &);
public:
    Classic();
    ~Classic() override;
    explicit Classic(const string &);      // data is set equal to parameter

    bool operator<(const Classic &) const;
    bool operator>(const Classic &) const;
    bool operator<=(const Classic &) const;
    bool operator>=(const Classic &) const;

    bool operator==(const Classic &) const;
    bool operator!=(const Classic &) const;

    void setReleaseMonth(int releaseMonth);
    void setMajorActor(const string &majorActor);

    int getReleaseMonth() const;
    const string &getMajorActor() const;

private:
    int releaseMonth;
    string majorActor;
};

#endif /* CLASSIC_H */
