#include "classic.h"
#include <vector>
#include <sstream>
#include <string>

Classic::~Classic() { }

Classic::Classic(const string &s) : Movie() {
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
    string temp = result[4];
    int length = temp.length();
    setReleaseYear(stoi(temp.substr(length-5, length)));
    setReleaseMonth(stoi(temp.substr(length-8, length-6)));
    setMajorActor(removeSpace(temp.substr(0, length-8)));
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

    // same year then compare month
    else if(getReleaseYear() == rhs.getReleaseYear()){
        if(getReleaseMonth() < rhs.getReleaseMonth())
            return true;
    }
    // then compare Major Actor
    else if(getMajorActor() < rhs.getMajorActor()){
        return true;
    }
    // otherwise false (equal or greater than)
    return false;
}

bool Classic::operator>(const Classic &rhs) const {

    // compare by Release Date
    if (getReleaseYear() > rhs.getReleaseYear())
        return true;

    // same year then compare month
    else if (getReleaseYear() == rhs.getReleaseYear()) {
        if (getReleaseMonth() > rhs.getReleaseMonth())
            return true;
    }
    // then compare Major Actor
    else if (getMajorActor() > rhs.getMajorActor()) {
        return true;
    }
    // otherwise false (equal or greater than)
    return false;
}

bool Classic::operator<=(const Classic &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Classic::operator>=(const Classic &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

ostream &operator<<(ostream &output, const Classic &m) {
    if(&m != nullptr){
        cout << "Classic, " << m.getQuantity() << ", " <<
                m.getTitle() << ", " << m.getMajorActor();
    }
    else
        output << "NULL";
    return output;
}
