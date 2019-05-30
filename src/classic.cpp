#include "classic.h"
#include <vector>
#include <sstream>
#include <string>

Classic::~Classic() { }

Classic::Classic(const string &s) : Movie(){
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
    string temp = result[4];
    
}

//   classics (‘C’) are sorted by Release date, then Major actor
bool Classic::operator<(const Movie &rhs) const {
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

bool Classic::operator>(const Movie &rhs) const {
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

bool Classic::operator<=(const Classic &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Classic::operator>=(const Classic &rhs) const {
    return (*this > rhs) || (*this == rhs);
}
