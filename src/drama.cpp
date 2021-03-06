#include "drama.h"
#include <vector>
#include <sstream>
#include <iomanip>

// Destructor
Drama::~Drama() { }

// Constructor, accepts a string
Drama::Drama(const string &s) : Movie(){
    setData(s);
}

// -----------------------------operator<-----------------------------
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

// -----------------------------operator>-----------------------------
bool Drama::operator>(const Movie &rhs) const {
    return !(*this < rhs) && (*this != rhs);
}

// -----------------------------operator<=-----------------------------
bool Drama::operator<=(const Drama &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

// -----------------------------operator>=-----------------------------
bool Drama::operator>=(const Drama &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

// -----------------------------operator<<-----------------------------
ostream &operator<<(ostream &output, const Drama &m) {
    if(&m != nullptr){
        cout << "Drama"
             << setw(10) << m.getQuantity() << " "
             << setw(35) << m.getTitle()
             << setw(25) << m.getDirector()
             << setw(12) << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}
