#ifndef _TEST_DATA_H
#define _TEST_DATA_H

// #include "data.h"
#include "tree.h"

class TestData: public Data{
public:
    Tree* classifier;

    TestData();
    TestData( Data d );
    TestData( Tree* c );
    TestData( Data d, Tree* c );
    void setClassifier( Tree* c ){ classifier = c; }
};

#endif