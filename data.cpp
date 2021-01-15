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
        while( !file.eof() ){
            std::string seq;
            char val;
            file >> seq;
            file >> val;
            DNA dna(seq, val);
            data.push_back(dna);
        }
        std::cout << "Successful opening file\n";
        file.close();
    }else{
        std::cout << "Couldn't open file\n";
    }
}

void Data::printData(){
    std::vector<DNA>::iterator it = data.begin();
    for( it; it != data.end(); it++){
        std::cout << it->getDNA_sequence() << "\t" << it->getValue() << "\n";
    }
}