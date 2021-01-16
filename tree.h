#ifndef _TREE_H
#define _TREE_H

#include "data.h"
#include "entropy.h"

#include <iostream>

struct Node{
public:
    Node* A;
    Node* C;
    Node* G;
    Node* T;
    char attr;  // define which attribute grouped data by 
    char value;

    Node();
    Node(Node* node);
    Node(Node* a, Node* c, Node* g, Node* t, char at, char val);
    ~Node();
};

class Tree{
    Node root;
    Data* data;
public:
    Tree();
    Tree(Data* dat);
    ~Tree();
    void makeTree();
    void making(Node* root, Data* set, std::string used_attrs);
    Data* getData(){ return data; }
    void makeBranch(Node* root, Data* supset, Data* set, std::string used_attrs, char branch);
};


#endif //