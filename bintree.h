/*
 * Tomomi Nakamura
 * Balanced BST
 * file @ bintree.h
 */

#include "nodedata.h"


#ifndef PROJECT2_BINTREE_H
#define PROJECT2_BINTREE_H


class BinTree {
    //Overloaded Assignment Operator<< for BinTree
    friend ostream & operator<<(ostream &, const BinTree &);
public:


    BinTree();
    // constructor
    BinTree(const BinTree &);
    // copy constructor
    ~BinTree();
    // destructor, calls makeEmpty
    bool isEmpty() const;
    // true if tree is empty, otherwise false
    void makeEmpty();
    // make the tree empty so isEmpty returns true
    BinTree& operator=(const BinTree &);
    //Overloaded Assignment Operator= for BinTree
    bool operator==(const BinTree &) const;
    //Overloaded Assignment Operator== for BinTree
    bool operator!=(const BinTree &) const;
    //Overloaded Assignment Operator!= for BinTree
    bool insert(NodeData*);
    // insert NodeData into bintree
    bool retrieve(const NodeData &, NodeData* &) const;
    //retrieve NodeData from BinTree
    void displaySideways() const;
    //displays the tree sideways...
    int getHeight(const NodeData&) const;
    //get high of Node which has a specified node data
    void bstreeToArray(NodeData* []);
    //convert bstree to array
    void arrayToBSTree(NodeData*[]);
    //convert array to bstree

private:

    struct Node {
        NodeData* data;
        // pointer to data object
        Node* left;
        // left subtree pointer
        Node* right;
        // right subtree pointer
    };

    //root of BinTree
    Node* root;
    //Number of Nodes
    int size;

    // helper for displaySideways()
    void sideways(Node*, int) const;

    //private methods to help public functions
    bool insert(NodeData* newData, Node* curr);
    void makeEmpty(Node*& curr);
    bool retrieve(const NodeData &, NodeData* &, Node* curr) const;
    int getHeight(Node* curr) const;
    void search(const NodeData &, Node* &) const;
    Node* copyTree(Node* curr);
    void checkEqualTo(Node*, Node*, bool&) const;
    Node* arrayToBSTree(NodeData* [], int l, int r);


};
#endif //PROJECT2_BINTREE_H
