#include "customer.h"
#include <string>

Customer::Customer(string last, string first, int id) {
    this->name = new NodeData(first + " " + last);
    this->ID = id;
}

Customer::~Customer(){
    delete name;
    name = NULL;
}

ostream& operator<<(ostream& output, const Customer& nd) {
    if(&nd != nullptr)
        output << nd.ID << " " << *nd.name << " ";
    else
        output << "NULL";
    return output;
}

void Customer::addHistory(const string s){
    history.push_back(s);
}

void Customer::displayHistory(){
    int length = history.size();
    cout << "----" << ID << "-----" << endl;
    if(length != 0){
        for(int i = 0; i < length; i++){
            cout << history[i] << endl;
        }
    }
    else
        cout << "No History!" << endl;
    cout << endl;
}