#include "tree.h"

Node::Node(){
    std::cout << "Constructor Node\n";
}



Tree::Tree(){
    std::cout << "Constructor Tree\n";
}

Tree::Tree(Data* dat):
data(dat)
{}

void Tree::makeTree(){
    std::string used_attr="";
    making(data, used_attr);
}

void Tree::making(Data* set, std::string used_attrs){
    Entropy entropy(set);
    entropy.calculateEntropy(used_attrs);
    char attr_lowest = entropy.getLowestEntropyAttr();
    Data setA(set, attr_lowest, 'A');
    Data setC(set, attr_lowest, 'C');
    Data setG(set, attr_lowest, 'G');
    Data setT(set, attr_lowest, 'T');

    setC.printData();

}