#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"
#include "test_data.h"

#include "test.h"

int main(){

    // Test tests;

    

    // tests.TestClassifyMixed("dane/spliceDTrainKIS.dat", 5);
    // tests.TestClassifySorted("dane/spliceDTrainKIS.dat", 5);


    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,9);

    for(int i = 0; i<10; i++ ){
        std::cout << distribution(generator) << "\n";
    }


    return 0;
}