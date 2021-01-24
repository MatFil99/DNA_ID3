#include "tree.h"

Node::Node():
A(nullptr), C(nullptr), G(nullptr), T(nullptr), attr(-1), value(-1)
{
    // std::cout << "Constructor Node\n";
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

void Node::printNode(std::string align="  "){
    std::cout << (int)attr << ":" << (int)value << "\n";
    if(A!=nullptr) { 
        std::cout << align << "A";
        align.append("  ");
        A->printNode(align);
        align.erase(std::max((int)align.size(), 0), 2);
    }
    if(C!=nullptr) { 
        std::cout << align << "C";
        align.append("  ");
        C->printNode(align);
        align.erase(std::max((int)align.size() - 3, 0), 2);
    }
    if(G!=nullptr) { 
        std::cout << align << "G";
        align.append("  ");
        G->printNode(align);
        align.erase(std::max((int)align.size() - 3, 0), 2);
    }
    if(T!=nullptr) { 
        std::cout << align << "T";
        align.append("  ");
        T->printNode(align);
        align.erase(std::max((int)align.size() - 3, 0), 2);
    }
}

char Node::classify(std::string trial){
    char act = attr;
    if(act==-1) return value;
    if(trial.at((int)act)=='A'){
        if( A!=nullptr )
            return A->classify(trial);
    }
    if(trial.at((int)act)=='C'){
        if( C!=nullptr )
            return C->classify(trial);
    }
    if(trial.at((int)act)=='G'){
        if( G!=nullptr )
            return G->classify(trial);
    }
    if(trial.at((int)act)=='T'){
        if( T!=nullptr )
            return T->classify(trial);
    }
    return -1;
}

Tree::Tree(){
    root = new Node();
    // std::cout << "Constructor Tree\n";
}

Tree::Tree(Data* dat):
data(dat)
{
    root = new Node();
}

Tree::~Tree(){
    delete root;
}

void Tree::makeTree(){
    std::string used_attr=".";// initialize used_attr
    making(root, data, used_attr);
}

void Tree::making(Node* root, Data* set, std::string used_attrs){
    Entropy entropy(set);
    entropy.calculateEntropy(used_attrs);
    char attr_lowest = entropy.getLowestEntropyAttr(used_attrs);
    used_attrs.append(std::to_string((int)attr_lowest));
    used_attrs.push_back('.');
    root->setAttr(attr_lowest);
    Data setA(set, attr_lowest, 'A');
    Data setC(set, attr_lowest, 'C');
    Data setG(set, attr_lowest, 'G');
    Data setT(set, attr_lowest, 'T');
    makeBranch(root, set, &setA, used_attrs, 'A');
    makeBranch(root, set, &setC, used_attrs, 'C');
    makeBranch(root, set, &setG, used_attrs, 'G');
    makeBranch(root, set, &setT, used_attrs, 'T');

}

void Tree::makeBranch(Node* root, Data* supset, Data* set, std::string used_attrs, char branch){
    Node* b_node=nullptr;
    bool stop = true;
    if(set->getAmountData()==0){
        // std::cout << "make branch 1\n";
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, supset->getMostComVal());
    }
    else if(set->dataOneVal()){
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, set->getData()->begin()->getValue());
        // std::cout << "make branch 2\n";
    }else if(set->allAttrUsed(used_attrs)){
        b_node = new Node(nullptr, nullptr, nullptr, nullptr, -1, set->getMostComVal());
        // std::cout << "make branch 3\n";
    }else{
        // std::cout << "make branch 4\n";
        stop=false;
        b_node = new Node();
    }

    switch(branch){
        case 'A':
            root->A = b_node;
            // std::cout << "A";
            break;
        case 'C':
            root->C = b_node;
            // std::cout << "C";
            break;
        case 'G':
            root->G = b_node;
            // std::cout << "G";
            break;
        case 'T':
            root->T = b_node;
            // std::cout << "T";
            break;
        default: delete b_node;
            // std::cout << "null";
    }
    if( !stop ){
       making(b_node, set, used_attrs);
    }
}

void Tree::printTree(){
    root->printNode();
}

char Tree::classify(std::string trial){
    char act = root->attr;
    if(act==-1) return root->value;
    if(trial.at((int)act)=='A'){
        if( root->A!=nullptr )
            return root->A->classify(trial);
    }
    if(trial.at((int)act)=='C'){
        if( root->C!=nullptr )
            return root->C->classify(trial);
    }
    if(trial.at((int)act)=='G'){
        if( root->G!=nullptr )
            return root->G->classify(trial);
    }
    if(trial.at((int)act)=='T'){
        if( root->T!=nullptr )
            return root->T->classify(trial);
    }
    return -1;
}