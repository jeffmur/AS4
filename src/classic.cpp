#include "classic.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

Classic::Classic() { }

Classic::~Classic() { }

Classic::Classic(const string &s) : Movie() {
    string token;
    // parse entire string s
    stringstream s1(s);
    vector<string> result;
    // add to result vector
    while(getline(s1, token, ',')){
        result.push_back(token);
    }
    // set values (Genre, Quantity, Director and Title)
    setGenre(result[0][0]);
    setQuantity(stoi(result[1]));
    setDirector(removeSpace(result[2]));
    setTitle(removeSpace(result[3]));
    string temp = result[4];

    // Cross-Platform check (removes \r from temp)
    int length = temp.length();
    if(temp[length-1] == '\r')
        temp = temp.substr(0, length-1);

    // parse classic ending data with ' ' decimeter
    vector<string> end;
    stringstream s2(temp);
    while(getline(s2, token, ' ')){
        end.push_back(token);
    }
    setMajorActor(end[1] + " " + end[2]);
    setReleaseMonth(stoi(end[3]));
    setReleaseYear(stoi(end[4]));
}

void Classic::setReleaseMonth(int releaseMonth) { Classic::releaseMonth = releaseMonth; }

int Classic::getReleaseMonth() const { return releaseMonth; }

const string &Classic::getMajorActor() const { return majorActor; }

void Classic::setMajorActor(const string &majorActor) { Classic::majorActor = majorActor; }

//   classics (‘C’) are sorted by Release date, then Major actor
bool Classic::operator<(const Classic &rhs) const {

    // compare by Release Date
    if(getReleaseYear() < rhs.getReleaseYear())
        return true;
    else if(getReleaseYear() == rhs.getReleaseYear()) {
        if(getReleaseMonth() < rhs.getReleaseMonth())
            return true;

        if(getMajorActor() < rhs.getMajorActor())
            return true;
    }

    // otherwise false (equal or greater than)
    return false;
}

bool Classic::operator>(const Classic &rhs) const {
    return !(*this < rhs) && (*this != rhs);
}

bool Classic::operator<=(const Classic &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Classic::operator>=(const Classic &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

bool Classic::operator==(const Classic &rhs) const {
    if(getGenre() == rhs.getGenre()){
        if(majorActor == rhs.majorActor || getTitle() == rhs.getTitle())
            return true;
    }
    return false;
}

bool Classic::operator!=(const Classic &rhs) const {
    return !(*this == rhs);
}


ostream &operator<<(ostream &output, const Classic &m) {
    if(&m != nullptr){
        cout << "Classic"
             << setw(8) << m.getQuantity() << " "
             << setw(35) << m.getTitle()
             << setw(25) << m.getMajorActor()
             << setw(8) << m.getReleaseMonth() << " " << m.getReleaseYear();
    }
    else
        output << "NULL";
    return output;
}
