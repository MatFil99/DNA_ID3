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

    class Parameters{
    public:
        int A_OFFSET, C_OFFSET, G_OFFSET, T_OFFSET, ATTR_VALS, ATTRS, OFFSET_1=1;
        void setParams(int a_of, int c_of, int g_of, int t_of, int attr_vals, int attrs, int of_1 ){
            A_OFFSET=a_of; C_OFFSET=c_of; G_OFFSET=g_of; T_OFFSET=t_of; ATTR_VALS=attr_vals; ATTRS=attrs; OFFSET_1=of_1;
        }
    }PARAMS;

public:
    Entropy();
    Entropy(Data* dat);
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