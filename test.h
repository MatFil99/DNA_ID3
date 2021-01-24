#ifndef _TEST_H
#define _TEST_H

#include "data.h"
#include "test_data.h"
#include "tree.h"

class Test{
public:
    void TestClassifySorted(const std::string path_file, int divs);
    void TestClassifyMixed(const std::string path_file, int divs);

};

#endif