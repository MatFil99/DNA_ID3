#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"

int main(){

    Data data;

    data.loadDataFromFile("dane/spliceDTrainKIS.dat");
    // data.printData();

    std::cout << data.getAmountData() << "\n\n\n";
    // Tree tree(&data);
    // tree.getData()->printData();
    std::string un_attrs="";

    Entropy e(&data);

    e.calculateEntropy(un_attrs);

    e.printEntropyAttr();
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    e.printEntropyAVal();



    return 0;
}