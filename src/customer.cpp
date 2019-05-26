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