#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Movie {
public:
    virtual ~Movie();
    Movie();
    Movie(const string &);      // data is set equal to parameter

    int getQuantity() const;
    char getGenre() const;
    const string &getDirector() const;
    const string &getTitle() const;
    int getReleaseYear() const;

    void setGenre(char genre);
    void setQuantity(int quanity);
    void setTitle(string);
    void setDirector(string);
    void setReleaseYear(int releaseYear);

    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;

    int quantity;

private:
    char genre;
    string director;
    string title;
    int releaseYear;
};

#endif
