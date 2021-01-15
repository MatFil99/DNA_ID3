#include "tree.h"

Node::Node(){
    std::cout << "Constructor Node\n";
}



Tree::Tree(){
    std::cout << "Constructor Tree\n";
}

Tree::Tree(Data dat):
data(&dat)
{}

void Tree::makeTree(){

}