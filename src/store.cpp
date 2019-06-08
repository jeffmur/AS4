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
        char commandType;
        infile >> commandType;

        switch(commandType)
        {
            case 'I': {
//                Inventory *inventoryAction = new Inventory(this, infile);
//                allTransactions->push_back((*inventoryAction));
//                inventoryAction->process();
//                break;
            }
            case 'H': {
//                History *historyAction = new History(this, infile);
//                allTransactions->push_back((*historyAction));
//                historyAction->process();
//                break;
            }
            case 'B': {
//                Borrow *borrowAction = new Borrow(this, infile);
//                allTransactions->push_back((*borrowAction));
//                borrowAction->process();
//                break;
            }
            case 'R': {
//                Return *returnAction = new Return(this, infile);
//                allTransactions->push_back((*returnAction));
//                returnAction->process();
//                break;
            }
            default: {
                break;
            }
        }
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
    //ifstream infileT("data/data4commands.txt");
    //store->processCommands(infileT);
    store->displayAll();

    delete store;

    return 0;
}
