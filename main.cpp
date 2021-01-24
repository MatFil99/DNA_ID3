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

    data.mixData();

    // data.printData();

    /* Test chosing learning set */

    std::vector<DNA> learning_set = data.getLearningSet(4, 5);
    std::cout << "\n * - * - * - * - * - * - * - * - * - * - * - * \n";
    std::vector<DNA>::iterator it = learning_set.begin();
    for( it; it<learning_set.end(); ++it ){
        std::cout << it->getDNA_sequence() << "\t" << (int)it->getValue() << "\n";
    }

    Data testData(data.getTestSet(4, 5));
    testData.printData();
    
    std::cout << "\n\n" << data.getAmountData() << "\n" << learning_set.size() << "\n" << testData.getAmountData() << "\n";

    /* test building tree and classification based on it */

    // Tree tree(&data);
    // tree.makeTree();
    // TestData tdata(data, &tree);
    // tdata.classify();
    // std::cout << "Efficiency:\t" << tdata.checkEfficiency() << "\n";

    // tree.printTree();
    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node2 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node3 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);
    // Node* node1 = new Node(nullptr, nullptr, nullptr, nullptr, 0, 0);


    // Node node = Node(node1, node2, nullptr, node3, 0, 0);

    // delete node;



    return 0;
}