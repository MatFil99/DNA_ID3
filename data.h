#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include <fstream>

#include <iostream>

#define ATTR_VALS 4 // amount values of attributes 
#define ATTRS 15    // amount of attributes

class DNA{
    std::string DNA_sequence;
    char value;                 // specifies if this sequence is a donor / acceptor

public:
    DNA();
    DNA(std::string seq, char val);
    std::string getDNA_sequence(){ return DNA_sequence; }
    char getValue(){ return value; }
    int getDNA_seqSize() { return DNA_sequence.size(); }
    char getDNA_seqAt(int i){ return DNA_sequence.at(i); };
    bool allAttrUsed(std::string used_attr);
};

class Data{
    public:
    std::vector<DNA> data;
    int boundary_e_i;

    Data();
    Data(std::string seq, char attr, char val);
    Data( Data* dat, char attr, char val);
    int loadDataFromFile(const std::string path_file);
    void printData();
    int getAmountData(){ data.size(); }
    std::vector<DNA>* getData(){ return &data; }
    bool dataOneVal();
    bool allAttrUsed(std::string used_attr);
    char getMostComVal();
};

#endif //