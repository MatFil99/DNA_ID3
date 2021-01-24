#include "data.h"

DNA::DNA(){
    // std::cout << "DNA constructor\n";
}

DNA::DNA(std::string seq, char val):
DNA_sequence(seq),
value(val)
{
}

bool DNA::allAttrUsed(std::string used_attr){
    int counter=0;
    for(int i=0; i<used_attr.length(); i++){
        if(used_attr[i]=='.') ++counter;
    }
    return counter==DNA_sequence.length();
}

bool Data::allAttrUsed(std::string used_attr){
    if( data.size()!=0){
        return data.begin()->allAttrUsed(used_attr);
    }
    return false;
}

Data::Data(){
    // std::cout << "Data constructor\n";
}

char Data::getMostComVal(){
    int count_0=0, count_1=0;
    std::vector<DNA>::iterator it = data.begin();
    for(it; it<data.end(); it++){
        if( it->getValue()==0 ) ++count_0;
        else if( it->getValue()==1) ++count_1;
    }
    if(count_0<count_1) return 1;
    else return 0;
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

Data::Data( Data* dat, char attr, char val){
    // create new Data as a set grouped by attr=val

    std::vector<DNA>::iterator it = dat->getData()->begin();
    for( it; it<dat->getData()->end(); it++ ){
        if(it->getDNA_sequence()[(int)attr] == val ){
            DNA dna(it->getDNA_sequence(), it->getValue());
            data.push_back(dna);
        }
    }

}

void Data::printData(){
    std::vector<DNA>::iterator it = data.begin();
    for( it; it != data.end(); it++){
        // std::cout << it->getDNA_sequence() << "\t" << (int)it->getValue() << "\n";
    }
}

bool Data::dataOneVal(){
    std::vector<DNA>::iterator it = data.begin();
    char val = it->getValue();
    for( it; it<data.end(); it++){
        if(it->getValue()!=val){
            return false;
        }
    }
    return true;
}