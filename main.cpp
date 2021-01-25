#include <iostream>

#include "tree.h"
#include "data.h"
#include "entropy.h"
#include "test_data.h"

#include "test.h"

int main(){

    Test tests;

    tests.TestsRun("dane/spliceDTrainKIS.dat", "spliceDresults.txt");
    tests.TestsRun("dane/spliceATrainKIS.dat", "spliceAresults.txt");

    return 0;
}
