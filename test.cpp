#include "test.h"

void Test::TestClassifySorted(const std::string path_file, int divs){
    Data data;
    double* results = new double[divs];
    data.loadDataFromFile(path_file);
    for( int i=0; i<divs; ++i ){
        Data l_set(data.getLearningSet(i, divs));
        Tree classifier(&l_set);
        classifier.makeTree();
        TestData test_set(data.getTestSet(i, divs));
        test_set.setClassifier(&classifier);
        test_set.classify();
        results[i] = test_set.checkEfficiency();
    }
    for(int i = 0; i<divs; ++i ){
        std::cout << "TestSet[sorted] - Subset: " << i << "/" << divs << "\t result = " << results[i] << "\n";
    }
    delete results;
}

void Test::TestClassifyMixed(const std::string path_file, int divs){
    Data data;
    double* results = new double[divs];
    data.loadDataFromFile(path_file);
    data.mixData();
    for( int i=0; i<divs; ++i ){
        Data l_set(data.getLearningSet(i, divs));
        Tree classifier(&l_set);
        classifier.makeTree();
        TestData test_set(data.getTestSet(i, divs));
        test_set.setClassifier(&classifier);
        test_set.classify();
        results[i] = test_set.checkEfficiency();
    }
    for(int i = 0; i<divs; ++i ){
        std::cout << "TestSet[mixed] - Subset: " << i << "/" << divs << "\t result = " << results[i] << "\n";
    }

    delete results;
}