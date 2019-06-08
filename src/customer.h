// Jeffrey Murray CSS 343 B SP19
// Created: 5/25/19
// Last Modified:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "nodedata.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Customer {
    friend ostream & operator<<(ostream &, const Customer &);
public:
    int ID;
    Customer(string last, string first, int ID);		// constructor from strings to NodeData
    ~Customer();								        // destructor
    vector<string> history;
    void displayHistory();
    void addHistory(string s);

private:
    NodeData* name;

};

#endif  /* CUSTOMER_H */

//----Expected Input----
//  3333 Witch Wicked
//  8888 Pig Porky
//  4444 Moose Bullwinkle
//  9999 Duck Daffy
//  6666 Donkey Darrell
//  7777 Spider Sammy
//  1111 Mouse Mickey
//  1000 Mouse Minnie
//  9000 Lizard Larry
//  8000 Wacky Wally
//  5000 Frog Freddie
//  2000 Duck Donald