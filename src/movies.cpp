#include "movies.h"

//------------------- constructors/destructor  -------------------------------
Movies::Movies() { }                         // default

Movies::~Movies() { }                       // needed so strings are deleted properly

Movies::Movies(const string& s) {           // creating movies
    // comedy
    if(s[0] == 'F'){

    }
    // drama
    else if (s[0] == 'D') {

    }
    // classic
    else if (s[0] == 'C') {

    }
}

//------------------------- operator= ----------------------------------------
Movies& Movies::operator=(const Movies& rhs) {
//    if (this != &rhs) {
//        data = rhs.data;
//    }
//    return *this;
}

//------------------------- operator==,!= ------------------------------------
bool Movies::operator==(const Movies& rhs) const {
    //return data == rhs.data;
}

bool Movies::operator!=(const Movies& rhs) const {
    //return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool Movies::operator<(const Movies& rhs) const {
    //return data < rhs.data;
}

bool Movies::operator>(const Movies& rhs) const {
    //return data > rhs.data;
}

bool Movies::operator<=(const Movies& rhs) const {
    //return data <= rhs.data;
}

bool Movies::operator>=(const Movies& rhs) const {
    //return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

bool Movies::setData(istream& infile) {
    //getline(infile, data);
    //return !infile.eof();       // eof function is true when eof char is read
}

//-------------------------- operator<< --------------------------------------
// Modified: 4/18 to handle null exception
ostream& operator<<(ostream& output, const Movies& nd) {
//    if(&nd != nullptr)
//        output << nd.data;
//    else
//        output << "NULL";
//    return output;
}
