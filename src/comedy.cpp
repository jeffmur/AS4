#include "comedy.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

ostream &operator<<(ostream &output, const Movie &m) {
    if(&m != nullptr){
        cout << m.getGenre() << ", " << m.getQuantity() << ", " <<
             m.getDirector() << ", " << m.getTitle() << ", " << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}
Comedy::~Comedy() { }

Comedy::Comedy(const string &s) : Movie(){
    setData(s);
}

//   comedy movie (‘F’) sorted by Title, then Year it released
bool Comedy::operator<(const Movie &rhs) const {
    // compare by Title
    if(getTitle() < rhs.getTitle())
        return true;

    // else compare year if titles' are equal
    else if(getTitle() == rhs.getTitle()){
        if(getReleaseYear() < rhs.getReleaseYear())
            return true;
    }
    // otherwise false
    return false;
}

bool Comedy::operator>(const Movie &rhs) const {
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

bool Comedy::operator<=(const Comedy &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Comedy::operator>=(const Comedy &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

ostream &operator<<(ostream &output, const Comedy &m) {
    if(&m != nullptr){
        cout << "Comedy"
             << setw(9) << m.getQuantity() << " "
             << setw(35) << m.getTitle()
             << setw(15) << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}