#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"

int main(){

    Data data;

    data.loadDataFromFile("dane/spliceDTrainKIS.dat");
    // data.printData();

    Entropy entropy;
    

    return 0;
}