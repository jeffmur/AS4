// Jeffrey Murray CSS 343 B SP19
// Created: 4/16/19
// Last Modified: 4/27/19

#include "bst.h"
#include <array>
using namespace std;

//------------------------- BinTree ---------------------------------
// Constructor for BinTree
BinTree::BinTree() {
    root = nullptr;
}
//------------------------- ~BinTree ---------------------------------
// Deconstructor for BinTree
BinTree::~BinTree() {
    // delete all data in tree
    makeEmpty();
    // delete root
    delete root;
    // set to NULL
    root = nullptr;
}
//------------------------- ~Node ---------------------------------
// Deconstructor for Node - deletes all data and pointers
BinTree::Node::~Node() {
    delete data;
    delete left;
    delete right;
}
//------------------------- isEmpty ---------------------------------
bool BinTree::isEmpty() const {
    return(root == nullptr);
}
//------------------------- makeEmpty ---------------------------------
// deletes all data in the tree, then assigns all pointers to NULL
void BinTree::makeEmpty() {
    deleteRecursive(root);
    root = nullptr;
}

//------------------------- deleteRecursive ---------------------------
// Recursively traverses tree until hitting null ptr (left or right)
// deletes the pointer then assigns pointer to NULL
// returns to previous level
void BinTree::deleteRecursive(Node *current) {
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

//------------------------- operator<< ---------------------------------
// Calls printInOrder() to print out all of the data in the tree
// Overloads operator<< to take in BinTrees and prints in order
ostream& operator<<(ostream& output, const BinTree& rhs) {
    if(rhs.isEmpty())
        output << "Empty!" << endl;
    else{ //print in order (Left, Root, Right)
        rhs.printInOrder();
    }
    output << endl;
    return output;
}

//------------------------- operator== ---------------------------------
bool BinTree::operator==(const BinTree &rhs) const {
    return compareRecur( root, rhs.root );
}
//------------------------- operator!= ---------------------------------
bool BinTree::operator!=(const BinTree &rhs) const {
    return !(*this == rhs);
}
//------------------------- compareRecur ---------------------------------
// Returns true if no execption is found, otherise, return false;
// Note: Will return false if both trees are empty.
bool BinTree::compareRecur( Node* lhs, Node* rhs ) const{
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
// inserts NodeData in to the BST and points to the new Node
// Postconditions: NodeData added to the tree
bool BinTree::insert(NodeData *item){

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
// NodeData to the tree.
// Postconditions: New node added to the tree containing desired NodeData
bool BinTree::setRecursive(Node *base, NodeData *toAdd) const{
    // base case
    if(base == nullptr){
        base = setData(toAdd);
        return true;
    }
    // recusive case - duplicate data
    if(*toAdd == *base->data){
        return false;
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

//------------------------- retrieve ---------------------------------
// Returns true if targetData is found, otherwise return false.
// Postconditions: pointer is assigned to the memory address of the NodeData if found
// otherwise, nullptr
// Modified operator<< in NodeData.cpp to take in nullptr -> "NULL"
bool BinTree::retrieve(NodeData &targetData, NodeData* &pointer) const{

    pointer = nullptr;

    if(findRecursive(root, &targetData)){
        pointer = &targetData;
        return true;
    }
    return false;

}
//------------------------- findRecursive ---------------------------------
// Recursive function that returns true if target NodeData is found,
// otherwise, return false.
// Postconditions: BinTree is unchanged
bool BinTree::findRecursive(Node *current, NodeData *target) const{
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


//------------------------- printInOrder ---------------------------------
// Displays NodeData via in-order traversal (Left, Root, Right)
// Preconditions: NONE
void BinTree::printInOrder() const{
    inorderHelper(root);
}


//------------------------- inorderHelper ---------------------------------
// Recursive function to perform in-order traversal of the tree
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::inorderHelper(BinTree::Node *current) const {
    if (current == nullptr)
        return;
    inorderHelper(current->left);
    cout << *current->data << " ";
    inorderHelper(current->right);
}
// end of printInOrder




