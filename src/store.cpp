//
// Created by alexa on 6/6/2019.
//
#include "store.h"

using namespace std;

//Constructor
Store::Store()
{
    comedyBST = new BinTree<Comedy>();
    classicBST = new BinTree<Classic>();
    dramaBST = new BinTree<Drama>();
    customerHashTable = new Hash(10);
}

//Destructor
Store::~Store()
{
    // mem garbage collection
    delete dramaBST;
    delete comedyBST;
    delete classicBST;
    delete customerHashTable;
}

// Comedies: Title,
// Classic: Month Year Major Actor
// Drama: Director, Title,


// ------------------------------------combineV-----------------------------
// Description: Combines parts of a string vector into a single string
// Precondition: None
// Postcondition: None
string Store::combineV(vector<string> v){
    string result;
    for(int i = 4; i < v.size(); i++){
        result += (v[i] + " ");
    }
    return result;
}

// ------------------------------------buildMovies-----------------------------
// Description: Creates the movie database based on the contents of infile
// Precondition: None
// Postcondition: BSTs for each of the movie types exist
void Store::buildMovies(ifstream& infile) {
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    for(;;){
        if(infile.eof()) { break; }

        string data;
        getline(infile, data);

        if(data.empty() || data == "\r") { continue; }

        // comedy
        if(data[0] == 'F'){
            auto *f = new Comedy(data);
            comedyBST->insert(f);
        }
            // drama
        else if (data[0] == 'D') {
            auto *d = new Drama(data);
            dramaBST->insert(d);
        }
            // classic
        else if (data[0] == 'C') {
            auto *c = new Classic(data);
            classicBST->insert(c);
        }
    }
    cout << endl;

}

// ------------------------------------buildCustomers-----------------------------
// Description: Creates a customer database based on the contents of infile
// Precondition: None
// Postcondition: customerHashTable exists and is filled with customers
void Store::buildCustomers(ifstream& infile){
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    for(;;){
        if(infile.eof()) { break; }
        if(infile.bad()) { continue; }
        string last, first;
        int id = -1;
        infile >> id >> last >> first;

        // valid Customer ID
        if (id > 999 && id <= 9999) {
            Customer *c = new Customer(last, first, id);
            customerHashTable->insert(*c);
        }
    }
}

// ------------------------------------processCommands-----------------------------
// Description: Processes and executes each of the transactions in infile
// Precondition: Customer and movie databases have been constructed
// Postcondition: None
void Store::processCommands(ifstream &infile)
{
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    for(;;)
    {
        if(infile.eof())
        {
            break;
        }
        if(infile.bad())
        {
            continue;
        }
        string line;
        getline(infile, line);
        char commandType = line[0];

        // Cross-Platform check (removes \r from temp)
        int length = line.length();
        if(line[length-1] == '\r')
            line = line.substr(0, length-1);

        string token;
        // parse entire string s
        stringstream s1(line);
        vector<string> result;
        // add to result vector
        while(getline(s1, token, ' ')){
            result.push_back(token);
        }

        switch(commandType) {
            case 'I': {
                cout << endl << "------------------------------------"
                                "Current Inventory"
                                "------------------------------------" << endl;
                displayAll();
                break;
            }
            case 'H': {
                customerHashTable->find(stoi(result[1]))->displayHistory();
                break;
            }
            case 'B': {
                int custID = stoi(result[1]);
                char genre = result[3][0];
                string data = combineV(result);

                if(result[2] == "D"){
                    switch(genre){
                        case 'F': {
                            data = "F, -1, XXX, "+data;
                            Comedy *ptr = nullptr;
                            comedyBST->manageMovie(custID, data, ptr, -1);
                            addTransaction("Borrowed", custID, ptr);
                            break;
                        }
                        case 'C': { // 3 1971 Ruth Gordon
                            Classic *ptr = nullptr;
                            classicBST->manageClassic(custID, data, ptr, -1);
                            addTransaction("Borrowed", custID, ptr);
                            break;
                        }
                        case 'D': {
                            data = "D, -1, "+data+"0000";
                            Drama *ptr = nullptr;
                            dramaBST->manageMovie(custID, data, ptr, -1);
                            addTransaction("Borrowed", custID, ptr);
                            break;
                        }
                        default: {cout << "ERROR: " << genre << " is not a valid genre!" << endl; break;}
                    }
                }
                else{
                    cout << "ERROR: " << result[2] << " is not a valid media type!" << endl;
                }
                break;
            }
            case 'R': {
                int custID = stoi(result[1]);
                char genre = result[3][0];
                string data = combineV(result);

                if(result[2] == "D"){
                    switch(genre){
                        case 'F': {
                            data = "F, +1, XXX, "+data;
                            Comedy *ptr = nullptr;
                            comedyBST->manageMovie(custID, data, ptr, 1);
                            addTransaction("Returned", custID, ptr);
                            break;
                        }
                        case 'C': { // 3 1971 Ruth Gordon
                            Classic *ptr = nullptr;
                            classicBST->manageClassic(custID, data, ptr, 1);
                            addTransaction("Returned", custID, ptr);
                            break;
                        }
                        case 'D': {
                            data = "D, +1, "+data+"0000";
                            Drama *ptr = nullptr;
                            dramaBST->manageMovie(custID, data, ptr, 1);
                            addTransaction("Returned", custID, ptr);
                            break;
                        }
                        default: {cout << "ERROR: " << genre << " is not a valid genre!" << endl; break;}
                    }
                }
                else{
                    cout << "ERROR: " << result[2] << " is not a valid media type!" << endl;
                }
                break;
            }
            default:
                break;
        }
    }
}

// ------------------------------------addTransaction-----------------------------
// Description: Adds a transaction to a customer's transaction history
// Precondition: None
// Postcondition: None
void Store::addTransaction(string action, int custID, Movie *ptr) {
    if(customerHashTable->find(custID) && ptr){
        customerHashTable->find(custID)->addHistory(action + " "+ ptr->getTitle());
        allTransactions.push_back(to_string(custID) + " " +action+ " " + ptr->getTitle());
    }

}

// ------------------------------------displayAll-----------------------------
// Description: Displays the inventory of movies
// Precondition: None
// Postcondition: None
void Store::displayAll() const
{
    classicBST->display();
    comedyBST->display();
    dramaBST->display();
}

//main method
int main() {
    //ifstream infileC("/home/jeffmur/UWB/343/AS4/data/data4customers.txt");
    Store *store = new Store();
    ifstream infileC("data/data4customers.txt");
    store->buildCustomers(infileC);
    ifstream infileM("data/data4movies.txt");
    store->buildMovies(infileM);
    ifstream infileT("data/data4commands.txt");
    store->processCommands(infileT);

    delete store;

    return 0;
}
