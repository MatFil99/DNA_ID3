#ifndef _ENTROPY_H
#define _ENTROPY_H

#include "data.h"
#include <array>
#include <cmath>

class AttrClassEntropy{
    char attr;
    char attr_class;
    double value;
public:
    AttrClassEntropy(char a, char a_c, double v): attr(a), attr_class(a_c), value(v){} 
    void printEntropy(){ std::cout << (int)attr << "\t" << attr_class << "\t" << value << "\n";}
};

class AttrEntropy{
    char attr;
    double value;

public:
    AttrEntropy(char a, double v): attr(a), value(v){}
    void printEntropy(){ std::cout << (int)attr << "\t" << value << "\n";}
    double getValue(){ return value; }
    char getAttr(){ return attr; }
};

class Entropy{
    
    Data* data;
    std::vector<AttrEntropy> attr_entropy;
    std::vector<AttrClassEntropy> attr_class_entropy;

public:
    Entropy();
    Entropy(Data* dat): data(dat){};
    void calculateEntropy(std::string used_attrs);
    void processSeq(int*, std::string used_attrs );
    void calcValEntropy(int*);
    double countAttrEntr(int n1, int n2);

    void printEntropyAVal();
    void printEntropyAttr();
    char getLowestEntropyAttr(std::string used_attrs);
};

void initZero(int*, int);

#endif //