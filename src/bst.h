// Jeffrey Murray CSS 343 B SP19
// Created: 4/16/19
// Last Modified:

#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <iostream>
#include <fstream>

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
    bool retrieve(M &targetData, M* &pointer) const;
    void printInOrder() const;
    void display() const;

private:
    struct Node {
        virtual ~Node();

        M* data;						    // pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
        Node* duplicate = NULL;             // points to duplicate movie Node
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
    bool findRecursive(Node *base, M *target) const;
    bool compareRecur(Node *lhs, Node *rhs ) const;
    void inorderHelper(Node *cur) const;

};

#endif  /* BINTREE_H */

//------------------------- BinTree ---------------------------------
// Constructor for BinTree
template <class M>
BinTree<M>::BinTree() {
    root = nullptr;
}

//------------------------- ~BinTree ---------------------------------
// Deconstructor for BinTree
template <class M>
BinTree<M>::~BinTree() {
    // delete all data in tree
    makeEmpty();
    // delete root
    delete root;
    // set to NULL
    root = nullptr;
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
    current->left = NULL;
    current->right = NULL;

    delete current->data;
    current->data = NULL;

    delete current;
    current = NULL;

    return;
}
// end of makeEmpty

//------------------------- compareRecur ---------------------------------
// Returns true if no execption is found, otherise, return false;
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
    //// recursive case - duplicate data
//    if(*toAdd == *base->data){
//        bool found = true;
//        Node *dup = *base;
//    }

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

//------------------------- retrieve ---------------------------------
// Returns true if targetData is found, otherwise return false.
// Postconditions: pointer is assigned to the memory address of the M if found
// otherwise, nullptr
// Modified operator<< in M.cpp to take in nullptr -> "NULL"
template <class M>
bool BinTree<M>::retrieve(M &targetData, M* &pointer) const{

    pointer = nullptr;

    if(findRecursive(root, &targetData)){
        pointer = &targetData;
        return true;
    }
    return false;

}
//------------------------- findRecursive ---------------------------------
// Recursive function that returns true if target M is found,
// otherwise, return false.
// Postconditions: BinTree is unchanged
template <class M>
bool BinTree<M>::findRecursive(Node *current, M *target) const{
    // rainy day
    if(current == nullptr)
        return false;
    // base case
    if(*target == *current->data)
        return true;
        // greater than (right subtree)
    else if(*target > *current->data)
        findRecursive(current->right, target);
    else
        // less than (left subtree)
        findRecursive(current->left, target);
}
// end of retrieve
template <class M>
void BinTree<M>::display() const{
    if(!isEmpty()){
        char genre = this->root->data->getGenre();
        // Comedy == 'F'
        if(genre == 'F'){
            cout << " Genre"
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(29) << "Year\n";
            cout << *this << endl;
        }
            // Drama == 'D'
        else if(genre == 'D'){
            cout << " Genre"
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(38) << "Director"
                 << setw(13) << "Year\n";
            cout << *this << endl;
        }
            // Classic == 'C'
        else if(genre == 'C'){
            cout << " Genre"
                 << setw(12) << "Quantity"
                 << setw(20) << "Title"
                 << setw(38) << "Major Actor"
                 << setw(13) << "Year\n";
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







