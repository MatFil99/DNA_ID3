#include "data.h"

DNA::DNA(){
    // std::cout << "DNA constructor\n";
}

DNA::DNA(std::string seq, char val):
DNA_sequence(seq),
value(val)
{
}

Data::Data(){
    // std::cout << "Data constructor\n";
}

int Data::loadDataFromFile(const std::string path_file){
    std::fstream file;
    file.open(path_file, std::ios::in);

    if( file.good() ){
        int i = 0;
        if( !file.eof() ){
            file >> boundary_e_i;
        }
        std::string seq;
        char val;
        while( file>>val>>seq ){
            val = val-48;   // change character of '0' and '1' to number 0 or 1
            DNA dna(seq, val);
            data.push_back(dna);
        }
        std::cout << "Successful opening file\n";
        file.close();
    }else{
        std::cout << "Couldn't open file\n";
    }
}

Data::Data( Data* dat, std::string attr, char val){
    // create new Data as a set grouped by attr=val
}

void Data::printData(){
    std::vector<DNA>::iterator it = data.begin();
    for( it; it != data.end(); it++){
        std::cout << it->getDNA_sequence() << "\t" << (int)it->getValue() << "\n";
    }
}