// Jeffrey Murray CSS 343 B SP19
// Created: 4/16/19
// Last Modified:

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class BinTree {				// you add class/method comments and assumptions
    friend ostream& operator<< (ostream& output, const BinTree& n); // output tree data in order
public:
    BinTree();								// constructor
    ~BinTree();								// destructor, calls makeEmpty
    bool isEmpty() const;					// true if tree is empty, otherwise false
    void makeEmpty();						// make the tree empty so isEmpty returns true
    BinTree& operator=(const BinTree &rhs);
    bool operator==(const BinTree &rhs) const;
    bool operator!=(const BinTree &rhs) const;
    bool insert(NodeData* item);
    bool retrieve(NodeData &targetData, NodeData* &pointer) const;


private:
    struct Node {
        virtual ~Node();

        NodeData* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    Node* root;								// root of the tree

    struct Node* setData(NodeData *item) const{
        Node *temp = new Node();
        temp->data = item;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }


// utility functions
    void deleteRecursive(Node*);
    bool setRecursive(Node *base, NodeData *data) const;
    bool findRecursive(Node*, NodeData*) const;
    bool compareRecur( Node* lhs, Node* rhs ) const;
    void printInOrder() const;
    void inorderHelper(BinTree::Node *current) const;

};

#endif  /* BINTREE_H */