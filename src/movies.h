#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class Movies {
    friend ostream & operator<<(ostream &, const Movies &);

public:
    Movies();          // default constructor, data is set to an empty string
    ~Movies();
    Movies(const string &);      // data is set equal to parameter
    Movies(const Movies &);    // copy constructor
    Movies& operator=(const Movies &);

    // set class data from data file
    // returns true if the data is set, false when bad data, i.e., is eof
    bool setData(istream&);

    bool operator==(const Movies &) const;
    bool operator!=(const Movies &) const;
    bool operator<(const Movies &) const;
    bool operator>(const Movies &) const;
    bool operator<=(const Movies &) const;
    bool operator>=(const Movies &) const;

private:
    string data;
};

#endif
