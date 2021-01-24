#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"
#include "test_data.h"

#include "test.h"

int main(){

    Test tests;

    tests.TestClassifyMixed("dane/spliceATrainKIS.dat", 5);
    tests.TestClassifySorted("dane/spliceATrainKIS.dat", 5);




    return 0;
}