#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"
#include "test_data.h"

class A{
public:
    virtual void fun1(){
        std::cout << "Funkcja wirtualna klasy A\n";
    };
};

class B: public A{
    public:
    void fun1(){
        std::cout << "Nadpisana wirtualna funkcja\n";
    }
};

int main(){

    Data data;

    data.loadDataFromFile("dane/spliceATrainKIS.dat");

    Tree tree(&data);

    // std::cout << data.getData()->at(0).getDNA_sequence().length();

    tree.makeTree();

    // data.printData();

    // tree.getRoot();

    TestData tdata(data, &tree);

    tdata.classify();

    // tdata.printData();

    std::cout << "Efficiency:\t" << tdata.checkEfficiency() << "\n";

    // tree.printTree();
    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node2 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node3 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);


    // Node node = Node(node1, node2, nullptr, node3, 0, 0);

    // delete node;



    return 0;
}