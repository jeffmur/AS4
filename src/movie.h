#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//   comedy movie (‘F’) sorted by Title, then Year it released
//   dramas (‘D’) are sorted by Director, then Title
//   classics (‘C’) are sorted by Release date, then Major actor

class Movie {
public:
    virtual ~Movie();
    Movie();

    int getQuantity() const;
    char getGenre() const;
    const string &getDirector() const;
    const string &getTitle() const;
    int getReleaseYear() const;

    void setData(const string &);
    string removeSpace(string);

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
