#include "comedy.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// ------------------------------------operator<<-----------------------------
// Description: Operator overload for <<
// Precondition: None
// Postcondition: None
ostream &operator<<(ostream &output, const Movie &m) {
    if(&m != nullptr){
        cout << m.getGenre() << ", " << m.getQuantity() << ", " <<
             m.getDirector() << ", " << m.getTitle() << ", " << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}

//Constructor
Comedy::Comedy(){ }

//Destructor
Comedy::~Comedy() { }

//Constructor, accepts a string
Comedy::Comedy(const string &s) : Movie(){
    setData(s);
}

//   comedy movie (‘F’) sorted by Title, then Year it released
// ------------------------------------operator<-----------------------------
// Description: Operator overload for <
// Precondition: None
// Postcondition: None
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

// ------------------------------------operator>-----------------------------
// Description: Operator overload for >
// Precondition: None
// Postcondition: None
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

// ------------------------------------operator<=-----------------------------
// Description: Operator overload for <=
// Precondition: None
// Postcondition: None
bool Comedy::operator<=(const Comedy &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

// ------------------------------------operator>=-----------------------------
// Description: Operator overload for >=
// Precondition: None
// Postcondition: None
bool Comedy::operator>=(const Comedy &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

// ------------------------------------operator<<-----------------------------
// Description: Operator overload for <<
// Precondition: None
// Postcondition: None
ostream &operator<<(ostream &output, const Comedy &m) {
    if(&m != nullptr){
        cout << "Comedy"
             << setw(9) << m.getQuantity() << " "
             << setw(35) << m.getTitle()
             << setw(25) << m.getDirector()
             << setw(12) << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}