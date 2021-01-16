#include "tree.h"

Node::Node():
A(nullptr), C(nullptr), G(nullptr), T(nullptr), attr(-1), value(-1)
{
    std::cout << "Constructor Node\n";
}

Node::Node(Node* node){
    A=nullptr; C=nullptr; G=nullptr; T=nullptr;
    if(node!=nullptr){
        attr=node->attr;
        value=node->value;
    }else{
        attr=-1;
        value=-1;
    }
}

Node::Node(Node* a, Node* c, Node* g, Node* t, char at, char val):
A(a), C(c), G(g), T(t), attr(at), value(val)
{ }

Node::~Node(){
    if(A!=nullptr) delete A;
    if(C!=nullptr) delete C;
    if(G!=nullptr) delete G;
    if(T!=nullptr) delete T;
}

Tree::Tree():
root()
{
    std::cout << "Constructor Tree\n";
}

Tree::Tree(Data* dat):
data(dat), root()
{}

Tree::~Tree(){

}

void Tree::makeTree(){
    std::string used_attr=".";// initialize used_attr
    making(&root, data, used_attr);
}

void Tree::making(Node* root, Data* set, std::string used_attrs){
    Entropy entropy(set);
    entropy.calculateEntropy(used_attrs);
    char attr_lowest = entropy.getLowestEntropyAttr(used_attrs);
    used_attrs.append(std::to_string((int)attr_lowest));
    used_attrs.push_back('.');
    Data setA(set, attr_lowest, 'A');
    Data setC(set, attr_lowest, 'C');
    Data setG(set, attr_lowest, 'G');
    Data setT(set, attr_lowest, 'T');

    std::cout << used_attrs <<"\n";

    //entropy.printEntropyAttr();
    
std::cout << "\n * * * * * * * * * * * * * * * * * *\n - - - - - - - - - - - - - - - - -\n\n";

    setA.printData();
std::cout << "\n * * * * * * * * * * * * * * * * * *\n - - - - - - - - - - - - - - - - -\n\n";

    setC.printData();

    makeBranch(root, set, &setA, used_attrs, 'A');
        
    
    makeBranch(root, set, &setC, used_attrs, 'C');
    
    makeBranch(root, set, &setG, used_attrs, 'G'); // tu jest jakis blad
    makeBranch(root, set, &setT, used_attrs, 'T');

}

void Tree::makeBranch(Node* root, Data* supset, Data* set, std::string used_attrs, char branch){
    Node* b_node;
    bool stop = true;
    if(set->getAmountData()==0){
        std::cout << "make branch 3\n";
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, supset->getMostComVal());
    }
    else if(set->dataOneVal()){
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, set->getData()->begin()->getValue());
        // std::cout << "Nie uruchomiono tego\n";
        std::cout << "make branch 1\n";
    }else if(set->allAttrUsed(used_attrs)){
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, set->getMostComVal());
        std::cout << "make branch 2\n";
    }else{
        std::cout << "make branch 4\n";
        stop=false;
        b_node = new Node();
    }

    switch(branch){
        case 'A':
            root->A = b_node;
            break;
        case 'C':
            root->C = b_node;
            break;
        case 'G':
            root->G = b_node;
            break;
        case 'T':
            root->T = b_node;
            break;
    }
    if( !stop ){
       making(b_node, set, used_attrs);
    }
}