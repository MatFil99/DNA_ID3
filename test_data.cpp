#include "test_data.h"

TestData::TestData(){
    std::cout << "TestData constructor\n";
}

TestData::TestData( Data d ):
Data(d)
{
}

TestData::TestData( Tree* c ):
classifier(c)
{
}

TestData::TestData( Data d, Tree* t):
Data(d), classifier(t)
{
}