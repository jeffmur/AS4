#include "drama.h"
#include <vector>
#include <sstream>

Drama::~Drama() { }

Drama::Drama(const string &s) : Movie(){
    setData(s);
}

//   dramas (‘D’) are sorted by Director, then Title
bool Drama::operator<(const Movie &rhs) const {
    // compare by Title
    if(getDirector() < rhs.getDirector())
        return true;

        // else compare year if titles' are equal
    else if(getDirector() == rhs.getDirector()){
        if(getTitle() < rhs.getTitle())
            return true;
    }
    // otherwise false
    return false;
}

bool Drama::operator>(const Movie &rhs) const {
    // compare by Title
    if(getTitle() > rhs.getTitle())
        return true;

        // else compare year if titles' are equal
    else if(getTitle() == rhs.getTitle()){
        if(getReleaseYear() > rhs.getReleaseYear())
            return true;
    }
    // otherwise false
    return false;
}

bool Drama::operator<=(const Drama &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Drama::operator>=(const Drama &rhs) const {
    return (*this > rhs) || (*this == rhs);
}
