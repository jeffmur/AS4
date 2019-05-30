#include "comedy.h"
#include <vector>
#include <sstream>

Comedy::~Comedy() { }

Comedy::Comedy(const string &s) : Movie(){
    stringstream ss(s);
    vector<string> result;
    string token;
    char del = ',';
    while(getline(ss, token, del)){
        result.push_back(token);
    }
    setGenre(result[0][0]);
    setQuantity(stoi(result[1]));
    setDirector(result[2]);
    setTitle(result[3]);
    setReleaseYear(stoi(result[4]));
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
