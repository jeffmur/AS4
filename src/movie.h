// ------------------------------------------------ movie.h -------------------------------------------------------
// Jeffrey Murray CSS 343 B
// Creation: 5/29/19
// Modified: 6/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Parent Class (interface)
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//       - Contains Genre, Director, Title, Year
//       - Parent class of Comedy, Drama, and Classic
//
// Input: data4movies.txt
// -----------------------------------------------------------------------------------------------------------------

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

#endif /* MOVIES_H */
