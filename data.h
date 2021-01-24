#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include <fstream>

#include <iostream>



class DNA{
    std::string DNA_sequence;
    char value;                 // specifies if this sequence is a donor / acceptor
    char predict = -1;
public:
    DNA();
    DNA(std::string seq, char val);
    std::string getDNA_sequence(){ return DNA_sequence; }
    char getValue(){ return value; }
    int getDNA_seqSize() { return DNA_sequence.size(); }
    char getDNA_seqAt(int i){ return DNA_sequence.at(i); };
    bool allAttrUsed(std::string used_attr);
    void setPredict(char pred_val){ predict=pred_val; }
    char getPredict(){ return predict; }
    bool correctPredict() { return value==predict; }
};

class Data{
    public:
    std::vector<DNA> data;
    int boundary_e_i;   // where is ekson 

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