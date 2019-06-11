#include "comedy.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// Constructor
Comedy::Comedy(){ }

// Destructor
Comedy::~Comedy() { }

// Constructor, accepts a constant string
Comedy::Comedy(const string &s) : Movie(){
    setData(s);
}

// -----------------------------operator<-----------------------------
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

// -----------------------------operator>----------------------------
bool Comedy::operator>(const Movie &rhs) const {
    return !(*this < rhs) && (*this != rhs);
}

// -----------------------------operator<=-----------------------------
bool Comedy::operator<=(const Comedy &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

// -----------------------------operator>=-----------------------------
bool Comedy::operator>=(const Comedy &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

// -----------------------------operator<<-----------------------------
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
// end of operators