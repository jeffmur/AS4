//
// Created by alexa on 6/6/2019.
//
#include "store.h"

using namespace std;


Store::Store()
{
    comedyBST = new BinTree<Comedy>();
    classicBST = new BinTree<Classic>();
    dramaBST = new BinTree<Drama>();
    customerHashTable = new Hash(10);
    //allTransactions = new vector<Transaction>();
}

Store::~Store()
{
    // mem garbage collection
    delete dramaBST;
    delete comedyBST;
    delete classicBST;
    delete customerHashTable;
    //delete allTransactions;
}

// Comedies: Title,
// Classic: Month Year Major Actor
// Drama: Director, Title,

string Store::combineV(vector<string> v){
    string result;
    for(int i = 4; i < v.size(); i++){
        result += (v[i] + " ");
    }
    return result;
}


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

    /*
    comedyBST->display();
    classicBST->display();
    dramaBST->display();
     */

    // ADD TRANSACTIONS HERE?


}

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
    customerHashTable->display();

    bool found = customerHashTable->find(4444);
    cout << "Found 4444? " << ( found ? "True" : "False") << endl;

    bool deleted = customerHashTable->remove(2000);
    cout << "Deleted 2000? " << ( deleted ? "True" : "False") << endl;

    customerHashTable->display();
}

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
                cout << endl;
                classicBST->display();
                comedyBST->display();
                dramaBST->display();
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
                            comedyBST->returnMovie(data, ptr);
                            addTransaction(custID, ptr);
                            break;
                        }
                        case 'C': { // 3 1971 Ruth Gordon
//                            Classic *ptr = nullptr;
//                            classicBST->returnMovie(data, ptr);
//                            addTransaction(custID, ptr);
                            break;
                        }
                        case 'D': {
                            data = "D, -1, "+data+"0000";
                            Drama *ptr = nullptr;
                            dramaBST->returnMovie(data, ptr);
                            addTransaction(custID, ptr);
                            break;
                        }
                        default: {cout << genre << " is not a valid genre!" << endl; break;}
                    }
                }
                else{
                    cout << "Not a valid media type!" << endl;
                }
                break;
            }
            case 'R': {
//                Return *returnAction = new Return(this, infile);
//                allTransactions->push_back((*returnAction));
//                returnAction->process();
//                break;
                cout << "Return: " << line << endl;
                break;
            }
            default:
                break;
        }
    }


}

void Store::addTransaction(int custID, Movie *ptr) {
    if(customerHashTable->find(custID) && ptr){
        customerHashTable->find(custID)->addHistory("Borrowed " + ptr->getTitle());
        allTransactions.push_back(to_string(custID) + " Borrowed " + ptr->getTitle());
    }

}

void Store::displayAll() const
{
    comedyBST->display();
    classicBST->display();
    dramaBST->display();
}

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
