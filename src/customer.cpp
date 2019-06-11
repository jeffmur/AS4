#include "customer.h"
#include <string>

// Constructor, accepts a name and id
Customer::Customer(string last, string first, int id) {
    this->name = new NodeData(first + " " + last);
    this->ID = id;
}

// Destructor
Customer::~Customer(){
    delete name;
    name = NULL;
}


// -----------------------------operator<<-----------------------------
ostream& operator<<(ostream& output, const Customer& nd) {
    if(&nd != nullptr)
        output << nd.ID << " " << *nd.name << " ";
    else
        output << "NULL";
    return output;
}

// -----------------------------addHistory-----------------------------
// Description: Adds the given string to this customer's history
// Post condition: This customer has string s as part of its history
//
void Customer::addHistory(const string s){
    history.push_back(s);
}

// -----------------------------displayHistory-----------------------------
// Description: prints history (transactions) per customer
//
void Customer::displayHistory(){
    int length = history.size();
    cout << "---- " << ID << " - " << *name << " -----" << endl;
    if(length != 0){
        for(int i = 0; i < length; i++){
            cout << history[i] << endl;
        }
    }
    else
        cout << "No History!" << endl;
    cout << endl;
}