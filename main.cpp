#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"

int main(){

    Data data;

    data.loadDataFromFile("dane/spliceDTrainKIS.dat");
    // data.printData();

    // std::cout << data.getAmountData() << "\n\n\n";
    Tree tree(&data);
    // tree.getData()->printData();
    std::string u_attr="";
    tree.making(&data, u_attr);
    
    std::string un_attrs="01";


    Entropy e(&data);

    e.calculateEntropy(un_attrs);

    e.printEntropyAttr();
    // std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    // e.printEntropyAVal();
    // std::cout << "\n\n";



    return 0;
}