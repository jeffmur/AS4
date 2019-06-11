#include "store.h"

using namespace std;

// Constructor
Store::Store()
{
    comedyBST = new BinTree<Comedy>();
    classicBST = new BinTree<Classic>();
    dramaBST = new BinTree<Drama>();
    customerHashTable = new Hash(57);
}

// Destructor
Store::~Store()
{
    // mem garbage collection calls each Data Structures' destructor
    delete dramaBST;
    delete comedyBST;
    delete classicBST;
    delete customerHashTable;
}

// ----------------------------- combineV -----------------------------
// Description: extracts Movie Data (excluding genre)
// Returns string ready for Movie Object (Drama and Comedy only)
//
string Store::combineV(vector<string> v){
    string result;
    for(int i = 4; i < v.size(); i++){
        result += (v[i] + " ");
    }
    return result;
}

// -----------------------------buildMovies -----------------------------
// Description: Creates the Movie objects based on the contents of infile
// Post condition: BSTs for each of the movie types (Comedy, Classic, Drama)
//
void Store::buildMovies(ifstream& infile) {
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    for(;;){
        if(infile.eof()) { break; }

        // parse line -> data
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

// ----------------------------- buildCustomers -----------------------------
// Description: Creates customer objects based on contents of infile
// Post condition: Customers are inserted in the Hash Table
// Note: No collision possible
//
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

// ----------------------------- processCommands -----------------------------
// Description: Directs via switch method to desired action
// Handles bad input (invalid customerID, no matching command, no matching movie)
// Post Condition: Customer's history and Movie Quantities have been changed
//
void Store::processCommands(ifstream &infile)
{
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    // keep count of line numbers
    int lineNum = 0;

    for(;;)
    {
        if(infile.eof()) { break; }
        if(infile.bad()) { continue; }

        string line;
        getline(infile, line);
        lineNum++;
        char commandType = line[0];

        // Cross-Platform check (removes \r from temp)
        int length = line.length();
        if(line[length-1] == '\r')
            line = line.substr(0, length-1);

        // parse entire string s
        string token;
        stringstream s1(line);
        vector<string> result;

        // add to result vector
        while(getline(s1, token, ' ')){
            result.push_back(token);
        }
        switch(commandType) {
            // inventory
            case 'I': {
                cout << endl << "-----------------------------------"
                                " Current Inventory "
                                "-----------------------------------" << endl;
                displayAll();
                break;
            }
            // history
            case 'H': {
                customerHashTable->find(stoi(result[1]))->displayHistory();
                break;
            }
            // borrow movie
            case 'B': {
                int custID = stoi(result[1]);
                char genre = result[3][0];
                string data = combineV(result);

                // checks for valid media type
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
                        default: {
                            cout << "ERROR at line: " << lineNum << " : "
                            << genre << " is not a valid genre!" << endl;
                            break;
                        }
                    }
                }
                else{
                    cout << "ERROR at line: " << lineNum << " : "
                    << result[2] << " is not a valid media type!" << endl;
                }
                break;
            }
            // return movie
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
                        case 'C': {
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
                        default: {
                            cout << "ERROR at line: " << lineNum << " : "
                            << genre << " is not a valid genre!" << endl;
                            break;
                        }
                    }
                }
                else{
                    cout << "ERROR at line: " << lineNum << " : "
                    << result[2] << " is not a valid media type!" << endl;
                }
                break;
            }
            default:
                // skip empty lines
                if(commandType != 0)
                    cout << "ERROR at line: " << lineNum << " : "
                    << commandType << " is not a valid command!" << endl;
                break;
        }
    }
}

// ----------------------------- addTransaction -----------------------------
// Description: Adds a transaction to a customer's transaction history
//
void Store::addTransaction(string action, int custID, Movie *ptr) {

    // customer is found && valid movie data
    if(customerHashTable->find(custID) && ptr){

        // Borrow or Return Movie Title
        customerHashTable->find(custID)->addHistory(action + " "+ ptr->getTitle());

        // adds to global transaction log
        allTransactions.push_back(to_string(custID) + " " +action+ " " + ptr->getTitle());
    }

}

// ------------------------------------displayAll-----------------------------
// Description: Displays the inventory of movies
//
void Store::displayAll() const
{
    comedyBST->display();
    dramaBST->display();
    classicBST->display();
}

//
int main() {
    auto *store = new Store();

    // Hash Table
    ifstream infileC("data/data4customers.txt");
    store->buildCustomers(infileC);

    // BSTs
    ifstream infileM("data/data4movies.txt");
    store->buildMovies(infileM);

    // Process
    ifstream infileT("data/data4commands.txt");
    store->processCommands(infileT);

    delete store;

    return 0;
}
