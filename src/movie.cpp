#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"

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
        //Drama *d = new Drama(s);
        cout << "Drama:   " << s << endl;
    }
    // classic
    else if (s[0] == 'C') {
        //Classic *c = new Classic(s);
        cout << "Classic: " << s << endl;
    } else return;
}

//   comedy movie (‘F’) sorted by Title, then Year it released
//   dramas (‘D’) are sorted by Director, then Title
//   classics (‘C’) are sorted by Release date, then Major actor

void Movie::setDirector(string director) { Movie::director = director; }

void Movie::setTitle(string title) { Movie::title = title; }

void Movie::setQuantity(int quantity) { Movie::quantity = quantity; }

void Movie::setGenre(char genre) { Movie::genre = genre; }

void Movie::setReleaseYear(int releaseYear) { Movie::releaseYear = releaseYear; }

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
