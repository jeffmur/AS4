// Jeffrey Murray CSS 343 B SP19
// Created: 4/16/19
// Last Modified:

#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "classic.h"

using namespace std;

template <class M>
class BinTree {
    //------------------------- operator<< ---------------------------------
    // Calls printInOrder() to print out all of the data in the tree
    // Overloads operator<< to take in BinTrees and prints in order
    friend ostream& operator<<(ostream& output, const BinTree<M>& rhs) {
        if(rhs.isEmpty())
            output << "Empty!" << endl;
        else{ //print in order (Left, Root, Right)
            rhs.printInOrder();
        }
        output << endl;
        return output;
    }

public:
    BinTree();								// constructor
    ~BinTree();								// destructor, calls makeEmpty
    bool isEmpty() const;					// true if tree is empty, otherwise false
    void makeEmpty();						// Make the tree empty so isEmpty returns true
    bool insert(M* iteM);

    void manageMovie(int custID, string data, M* &pointer, int amount);
    void manageClassic(int custID, string data, M* &pointer, int amount);
    bool retrieve(M* targetData, M* &pointer) const;
    void printInOrder() const;
    void display() const;

private:
    struct Node {
        virtual ~Node();

        M* data;						    // pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
        //Node* duplicate = NULL;           // points to duplicate movie Node
                                            // (same title and director - different Major Actor)
    };
    Node* root;								// root of the tree

    struct Node* setData(M *item) const{
        Node *temp = new Node();
        temp->data = item;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

// utility functions
    void deleteRecursive(Node*);
    bool setRecursive(Node *base, M *data) const;
    bool findRecursive(Node *base, M *target, M* &ptr) const;
    bool compareRecur(Node *lhs, Node *rhs ) const;
    void inorderHelper(Node *cur) const;
    string removeSpace(string s);

};

#endif  /* BINTREE_HPP */

//------------------------- BinTree ---------------------------------
// Constructor for BinTree
template <class M>
BinTree<M>::BinTree() {
    root = nullptr;
}

//------------------------- ~BinTree ---------------------------------
// Deconstructor for BinTree
template <class M>
BinTree<M>::~BinTree<M>() {
    // delete all data in tree
    makeEmpty();
    // delete root
    delete root;
    // set to NULL
    root = NULL;
}
//------------------------- ~Node ---------------------------------
// Deconstructor for Node - deletes all data and pointers
template <class M>
BinTree<M>::Node::~Node() {
    delete data;
    delete left;
    delete right;
}
//------------------------- isEmpty ---------------------------------
template <class M>
bool BinTree<M>::isEmpty() const {
    return(root == nullptr);
}

//------------------------- makeEmpty ---------------------------------
// deletes all data in the tree, then assigns all pointers to NULL
template <class M>
void BinTree<M>::makeEmpty() {
    deleteRecursive(root);
    root = nullptr;
}

//------------------------- deleteRecursive ---------------------------
// Recursively traverses tree until hitting null ptr (left or right)
// deletes the pointer then assigns pointer to NULL
// returns to previous level
template <class M>
void BinTree<M>::deleteRecursive(Node *current) {
    if(current == NULL)
        return;
    // if left isn't empty set to NULL
    // recurse until hit child
    if(current->left != NULL)
        deleteRecursive(current->left);

    // if right isn't empty set to NULL
    // recurse until hit child
    if(current->right != NULL)
        deleteRecursive(current->right);

    // set both children to NULL
    current->left = nullptr;
    current->right = nullptr;

    delete current->data;
    current->data = NULL;

    delete current;
    current = NULL;

    return;
}
// end of makeEmpty

//------------------------- compareRecur ---------------------------------
// Returns true if no exception is found, otherwise, return false;
// Note: Will return false if both trees are empty.
template <class M>
bool BinTree<M>::compareRecur( Node* lhs, Node* rhs ) const{
    if(lhs != nullptr && rhs != nullptr) {
        if (*lhs->data != *rhs->data)
            return false;
        else { // continue traversing the tree
            compareRecur(lhs->right, rhs->right);
            compareRecur(lhs->left, lhs->left);
            return true;
        }
    }
    return false;
}
// end of operators

//------------------------- insert ---------------------------------
// inserts M in to the BST and points to the new Node
// Postconditions: M added to the tree
template <class M>
bool BinTree<M>::insert(M *item){

    // bad data check
    if (item == nullptr)
        return false;
    else {
        // assign root
        if (root == nullptr){
            root = setData(item);
            return true;
        }
        else // traverse the tree
            return setRecursive(root, item);
    }
}
//------------------------- setRecursive ---------------------------------
// Returns true if insertion is successful, otherwise returns false.
// For each recusive check, the pointer must be NULL before adding
// M to the tree.
// Postconditions: New node added to the tree containing desired M
template <class M>
bool BinTree<M>::setRecursive(Node *base, M *toAdd) const{
    // base case
    if(base == nullptr){
        base = setData(toAdd);
        return true;
    }

    // recursive case - right
    if(*toAdd > *base->data){
        if(base->right == NULL){
            Node* rightPtr = setData(toAdd);
            base->right = rightPtr;
            return true;
        }
        else
            return setRecursive(base->right, toAdd);
    }
    // recursive case - left
    if (*toAdd < *base->data){
        if(base->left == NULL){
            Node* leftPtr = setData(toAdd);
            base->left = leftPtr;
            return true;
        }
        else
            return setRecursive(base->left, toAdd);
    }
    return false;
}
// end of insert

template <class M>
void BinTree<M>::manageMovie(int custID, string data, M *&pointer, int amount){
    M *MovieData = new M(data);
    if(retrieve(MovieData, pointer))
        if(pointer->quantity > 0)
            pointer->quantity = pointer->quantity+amount;
        else
            cout << "OUT OF STOCK: " << custID << " cannot borrow " << pointer->getTitle() << endl;
    delete MovieData;
}


template <class M>
void BinTree<M>::manageClassic(int custID, string data, M *&pointer, int amount){
    // flip data
    string actor = removeSpace(data.substr(7, data.length()));
    int month = stoi(data.substr(0, 2));
    int year = stoi(data.substr(2,4));
    // assign data to flipped
    Classic *MovieData = new Classic();
    MovieData->setGenre('C');
    MovieData->setMajorActor(actor);
    MovieData->setReleaseYear(year);
    MovieData->setReleaseMonth(month);

    if(retrieve(MovieData, pointer))
        if(pointer->quantity > 0)
            pointer->quantity = pointer->quantity+amount;
        else {
            cout << "OUT OF STOCK: " << custID << " cannot borrow " << pointer->getTitle() << endl;
        }

    delete MovieData;
}

//------------------------- retrieve ---------------------------------
// Returns true if targetData is found, otherwise return false.
// Postconditions: pointer is assigned to the memory address of the M if found
// otherwise, nullptr
// Modified operator<< in M.cpp to take in nullptr -> "NULL"
template <class M>
bool BinTree<M>::retrieve(M* targetData, M* &pointer) const{

    if(findRecursive(root, targetData, pointer))
        return true;

    pointer = nullptr;
    cout << "ERROR: Could not locate that movie!" << endl;
    return false;

}
//------------------------- findRecursive ---------------------------------
// Recursive function that returns true if target M is found,
// otherwise, return false.
// Postconditions: BinTree is unchanged
template <class M>
bool BinTree<M>::findRecursive(Node *current, M *target, M* &ptr) const{
    // rainy day
    if(current == nullptr)
        return false;
    // base case
    if(*target == *current->data){
        ptr = current->data;
        return true;
    }
        // greater than (right subtree)
    else if(*target > *current->data)
        findRecursive(current->right, target, ptr);
    else
        // less than (left subtree)
        findRecursive(current->left, target, ptr);
}
// end of retrieve


template <class M>
void BinTree<M>::display() const{
    if(!isEmpty()){
        char genre = this->root->data->getGenre();
        // Comedy == 'F'
        if(genre == 'F'){
            cout << "Genre "
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(37) << "Director"
                 << setw(14) << "Year\n";
            cout << *this << endl;
        }
            // Drama == 'D'
        else if(genre == 'D'){
            cout << "Genre "
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(36) << "Director"
                 << setw(15) << "Year\n";
            cout << *this << endl;
        }
            // Classic == 'C'
        else if(genre == 'C'){
            cout << " Genre"
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(36) << "Major Actor"
                 << setw(15) << "Year\n";
            cout << *this << endl;
        }
    }
    // bad input
    else
        cout << "Empty Tree!" << endl;
}


//------------------------- printInOrder ---------------------------------
// Displays NodeData via in-order traversal (Left, Root, Right)
// Preconditions: NONE
template <class M>
void BinTree<M>::printInOrder() const{
    inorderHelper(root);
}


//------------------------- inorderHelper ---------------------------------
// Recursive function to perform in-order traversal of the tree
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
template <class M>
void BinTree<M>::inorderHelper(BinTree::Node *current) const {
    if (current == nullptr)
        return;
    inorderHelper(current->left);
    cout << *current->data << endl;
    inorderHelper(current->right);
}
// end of printInOrder

template <class M>
string BinTree<M>::removeSpace(string old){
    string result;
    int l = old.length();
    if(old[0] == *" "){
        result = old.substr(1, l);
    }
    if(old[l-1] == *" "){
        result = old.substr(0, l-1);
    }
    return result;
}






