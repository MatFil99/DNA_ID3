#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include <fstream>

#include <iostream>

class DNA{
    std::string DNA_sequence;
    char value;                 // specifies if this sequence is a donor / acceptor

public:
    DNA();
    DNA(std::string seq, char val);
    std::string getDNA_sequence(){ return DNA_sequence; }
    char getValue(){ return value; }
};

class Data{
    public:
    std::vector<DNA> data;
    int boundary_e_i;

    Data();
    Data(std::string seq, char val);
    int loadDataFromFile(const std::string path_file);
    void printData();
    int getAmountData(){ data.size(); }
};

#endif //