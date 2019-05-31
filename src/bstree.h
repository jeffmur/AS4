#include <string>
#include "movie.h"

using namespace std;


template <class Movie>
class BSTree
{
public:
    BSTree();
    ~BSTree();

    bool insert(Movie * m);
    //bool remove(string key);
    Movie * find(string key) const;

private:
    struct Node {
        Movie* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    Node* root;								// root of the tree

    bool insertRecur(Node * & cur, Movie * m);
    //bool removeRecur(Node * & cur, string key);
    Movie * findRecur(Node * & cur, string key) const;


};

// constructs the bstree
template <class Movie>
BSTree<Movie>::BSTree()
{
    root = nullptr;
}

//destructor for BSTree
template <class Movie>
BSTree<Movie>::~BSTree()
{

}

template <class Movie>
bool BSTree<Movie>::insert(Movie * m)
{
    return insertRecur(root, m);
}

template <class Movie>
bool BSTree<Movie>::insertRecur(Node * & cur, Movie * m)
{
    if(cur->data == nullptr)
    {
        cur = new Node{m, nullptr, nullptr};
        return true; //movie was successfully inserted
    }
    if((*cur->data) == (*m))
    {
        return false; //movie is already in tree
    }
    if((*cur->data) > (*m))
    {
        insertRecur(cur->left, m);
    }
    else
    {
        insertRecur(cur->right, m);
    }
}

template <class Movie>
Movie * BSTree<Movie>::find(string key) const
{
    return findRecur(root, key);
}

template <class Movie>
Movie * BSTree<Movie>::findRecur(Node * & cur, string key) const
{
    if(cur == nullptr)
    {
        return false;
    }
    if(key == (*cur->data).getComparable())
    {
        return cur->data;
    }

}