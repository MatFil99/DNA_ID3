#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"

int main(){

    Data data;

    data.loadDataFromFile("dane/spliceDTrainKIS.dat");

    Tree tree(&data);

    tree.makeTree();

    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node2 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node3 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);


    // Node node = Node(node1, node2, nullptr, node3, 0, 0);

    // delete node;



    return 0;
}