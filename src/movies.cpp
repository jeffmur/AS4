#include "movies.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"

//------------------- constructors/destructor  -------------------------------
Movies::~Movies() { }                       // needed so data is deleted properly

Movies::Movies(const string& s) {           // creating movies - comedy, drama, classic
    // comedy
    if(s[0] == 'F'){
        //Comedy *c = new Comedy(s);
    }
    // drama
    else if (s[0] == 'D') {
        //Drama *d = new Drama(s);
    }
    // classic
    else if (s[0] == 'C') {
        //Classic *c = new Classic(s);
    } else return;
}

//   comedy movies (‘F’) sorted by Title, then Year it released
//   dramas (‘D’) are sorted by Director, then Title
//   classics (‘C’) are sorted by Release date, then Major actor

//------------------------- operator==,!= ------------------------------------
bool Movies::operator==(const Movies& rhs) const {
    if(genre == rhs.genre){
        if(title == rhs.title && director == rhs.director)
            return true;
    }
    return false;
}
bool Movies::operator!=(const Movies& rhs) const {
    return !(*this == rhs);
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool Movies::operator<(const Movies& rhs) const { }
bool Movies::operator>(const Movies& rhs) const { }
bool Movies::operator<=(const Movies& rhs) const { }
bool Movies::operator>=(const Movies& rhs) const { }

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const Movies& nd) {
//    if(&nd != nullptr)
//        output << nd.data;
//    else
//        output << "NULL";
//    return output;
}
