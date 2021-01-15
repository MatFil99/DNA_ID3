#ifndef _TREE_H
#define _TREE_H

#include "data.h"
#include <iostream>

struct Node{
    Node* A;
    Node* C;
    Node* G;
    Node* T;
    char attr;
    char value;

    Node();
};

class Tree{

    Node root;
    Data* data;
public:
    Tree();
    Tree(Data* dat);
    void makeTree();
    Data* getData(){ return data; }
};


#endif //