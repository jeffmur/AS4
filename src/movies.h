#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Movies {
    friend ostream & operator<<(ostream &, const Movies &);

public:
    virtual ~Movies();
    Movies(const string &);      // data is set equal to parameter

    bool operator==(const Movies &) const;
    bool operator!=(const Movies &) const;
    bool operator<(const Movies &) const;
    bool operator>(const Movies &) const;
    bool operator<=(const Movies &) const;
    bool operator>=(const Movies &) const;

    int quanity;

private:
    char genre;
    string director;
    string title;
    int releaseYear;
};

#endif
