#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include <vector>
#include <sstream>

//------------------- constructors/destructor  -------------------------------
Movie::Movie(){ }
Movie::~Movie() { }                       // needed so data is deleted properly

void Movie::setData(const string &s){
    stringstream ss(s);
    vector<string> result;
    string token;
    char del = ',';
    while(getline(ss, token, del)){
        result.push_back(token);
    }
    setGenre(result[0][0]);
    setQuantity(stoi(result[1]));
    setDirector(removeSpace(result[2]));
    setTitle(removeSpace(result[3]));
    setReleaseYear(stoi(result[4]));
}
// -------------------- Setter ----------------
void Movie::setDirector(string director) { Movie::director = director; }

void Movie::setTitle(string title) { Movie::title = title; }

void Movie::setQuantity(int quantity) { Movie::quantity = quantity; }

void Movie::setGenre(char genre) { Movie::genre = genre; }

void Movie::setReleaseYear(int releaseYear) { Movie::releaseYear = releaseYear; }

// -------------- Getter ------------------------

int Movie::getQuantity() const { return quantity; }

char Movie::getGenre() const { return genre; }

const string &Movie::getDirector() const { return director; }

const string &Movie::getTitle() const { return title; }

int Movie::getReleaseYear() const { return releaseYear; }

//------------------------- operator==,!= ------------------------------------
bool Movie::operator==(const Movie& rhs) const {
    if(genre == rhs.genre){
        if(title == rhs.title)
            return true;
    }
    return false;
}
bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}

string Movie::removeSpace(string old){
    string result;
    int l = old.length();
    if(old[0] == *" "){
        result = old.substr(1, l);
    }
    if(old[l-1] == *" "){
        result = old.substr(0, l-1);
    }
    return result;
}
