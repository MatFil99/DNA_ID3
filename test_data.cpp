#include "test_data.h"

TestData::TestData(){
    std::cout << "TestData constructor\n";
}

TestData::TestData( Data d ):
Data(d), learning_set(data.size())
{
}

TestData::TestData( Tree* c ):
classifier(c)
{
}

TestData::TestData( Data d, Tree* t):
Data(d), classifier(t), learning_set(data.size())
{
}

void TestData::classify(){
    if( classifier==nullptr ){
        std::cout << "Firstly set classifier!"; return ;
    }
    std::vector<DNA>::iterator trial = data.begin();
    for( trial; trial<data.end(); ++trial ){
        trial->setPredict(classifier->classify(trial->getDNA_sequence()));
    }
}

void TestData::printData(){
    std::vector<DNA>::iterator it = data.begin();
    for( it; it != data.end(); it++){
        std::cout << it->getDNA_sequence() << "\tv = " << (int)it->getValue() << "\tp = " << (int)it->getPredict() << "\n";
    }
}

double TestData::checkEfficiency(){
    int correct_predictions=0;
    std::vector<DNA>::iterator dna = data.begin();
    for( dna; dna<data.end(); ++dna ){
        if(dna->correctPredict()) ++correct_predictions;
    }
    return correct_predictions/(getAmountData()+0.0);
}



