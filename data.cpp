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
        return 0;
    }else{
        std::cout << "Couldn't open file\n";
        return -1;
    }
}

bool Data::allAttrUsed(std::string used_attr){
    if( data.size()!=0){
        return data.begin()->allAttrUsed(used_attr);
    }
    return false;
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

Data::Data(std::vector<DNA> dna ):
    data(dna)
{
}

// Data::Data ( Data& d ){
//     data = *d.getData();
//     boundary_e_i = d.getBoundaryEI();
// }

void Data::printData(){
    std::vector<DNA>::iterator it = data.begin();
    for( it; it != data.end(); it++){
        std::cout << it->getDNA_sequence() << "\t" << (int)it->getValue() << "\n";
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

void Data::mixData(){
    std::vector<int> indexes(data.size());
    std::vector<DNA> mixed_data(data.size());
    for( int i=0; i<data.size(); ++i ){
        indexes[i] = i;   // initialize pom indexes
    }
    std::default_random_engine generator;
    for( int i=0; i<data.size(); ++i ){
        std::uniform_int_distribution<int> distribution(0, data.size()-i-1);
        int number = distribution(generator);
        mixed_data.at(i).setDNA( data.at(indexes[number]).getDNA_sequence(), data.at(indexes[number]).getValue());
        indexes.erase(indexes.begin() + number);
    }
    data = mixed_data;
}

std::vector<DNA> Data::getLearningSet(int idx, int nr_divs ){
    std::vector<DNA> learning_set(0);
    if ( idx >= nr_divs ) {std::cout << "Error getLearningSet() idx>=nr_divs"; return learning_set; }
    int nr_data = data.size()/nr_divs;
    int set_size=nr_data;
    int rest = data.size()%nr_divs;
    if ( rest>=(idx+1) ) set_size+=1;
    learning_set.resize( data.size() - set_size );

    if(idx!=0){
        std::copy(data.begin(), data.begin() + idx*nr_data + std::min(idx, rest), learning_set.begin());
    }
    if(idx!=nr_divs-1){
        std::copy( data.begin() + idx*nr_data + std::min(idx, rest) + set_size, data.end(), learning_set.begin() + idx*nr_data + std::min(idx, rest) );
    }
    return learning_set;
}

std::vector<DNA> Data::getTestSet(int idx, int nr_divs){
        std::vector<DNA> test_set;
    if ( idx > nr_divs ) {std::cout << "Error getTestSet() idx>=nr_divs"; return test_set; }
    int nr_data = data.size()/nr_divs;
    int set_size=nr_data;
    int rest = data.size()%nr_divs;
    if ( rest>=(idx+1) ) set_size+=1;
    test_set.resize( set_size );
    std::copy(data.begin() + idx*nr_data + std::min(idx, rest), data.begin() + idx*nr_data + std::min(idx, rest) + set_size, test_set.begin() );
    return test_set;
}
