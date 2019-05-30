#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include <vector>
#include <sstream>

//------------------- constructors/destructor  -------------------------------
Movie::Movie(){ }
Movie::~Movie() { }                       // needed so data is deleted properly

Movie::Movie(const string& s) {           // creating movie - comedy, drama, classic
    // comedy
    if(s[0] == 'F'){
        Comedy *c = new Comedy(s);
        cout << "Comedy:  " << c << endl;
    }
    // drama
    else if (s[0] == 'D') {
        Drama *d = new Drama(s);
        cout << "Drama:   " << d << endl;
    }
    // classic
    else if (s[0] == 'C') {
        Classic *c = new Classic(s);
        cout << "Classic: " << c << endl;
    } else return;
}

//   comedy movie (‘F’) sorted by Title, then Year it released
//   dramas (‘D’) are sorted by Director, then Title
//   classics (‘C’) are sorted by Release date, then Major actor

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
    setDirector(result[2]);
    setTitle(result[3]);
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
        if(title == rhs.title && director == rhs.director)
            return true;
    }
    return false;
}
bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}
