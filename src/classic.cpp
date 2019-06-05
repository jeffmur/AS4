#include "classic.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

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
    if(temp[length-1] == '\r')
        temp = temp.substr(0, length-1);
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
