#include "entropy.h"

#define A_OFFSET 0
#define C_OFFSET 30
#define G_OFFSET 60
#define T_OFFSET 90

#define OFFSET_1 1 

Entropy::Entropy(){
    // std::cout << "Constructor Entropy\n";
}

void Entropy::calculateEntropy(std::string used_attrs){

    int* help_statistics = new int[ATTR_VALS*2*ATTRS];  // array hepling to calculate entropy 
    initZero(help_statistics, ATTR_VALS*2*ATTRS);
    processSeq(help_statistics, used_attrs);

    // for(int i=0; i<ATTR_VALS*2*ATTRS; i++){
    //     std::cout << help_statistics[i] <<" ";
    //     if( (i+1)%30==0) std::cout << "\n"; 
    // }

    calcValEntropy(help_statistics);
    
    delete[] help_statistics;
}

void Entropy::processSeq(int* help_statistics, std::string used_attrs){
    std::vector<DNA>::iterator it = data->getData()->begin();
    for( it; it<data->getData()->end(); it++ ){
        for( int i=0; i<it->getDNA_sequence().size(); i++ ){
            std::string act_attr = std::string(".").append(std::to_string(i).append("."));
            if( used_attrs.find( act_attr )==std::string::npos ){
                // std::cout <<used_attrs << "\n";
                int offset = 0;
                if( it->getValue()==1 ){ ++offset; }// note what is the value of function for this sequence 
                switch(it->getDNA_seqAt(i)){  // this could be universal, but isnt
                    case 'A':
                        ++help_statistics[A_OFFSET+2*i+offset];
                        break;
                    case 'C':
                        ++help_statistics[C_OFFSET+2*i+offset];
                        break;
                    case 'G':
                        ++help_statistics[G_OFFSET+2*i+offset];
                        break;
                    case 'T':
                        ++help_statistics[T_OFFSET+2*i+offset];
                        break;
                }
            }
        }
    }
}

void Entropy::calcValEntropy(int* help_statistics){
    for(int i=0; i<ATTRS; i++){
        // if( used_attrs.find( std::to_string(i) ) )
        int Av0 = help_statistics[A_OFFSET+2*i], Av1 = help_statistics[A_OFFSET+OFFSET_1+2*i];
        int Cv0 = help_statistics[C_OFFSET+2*i], Cv1 = help_statistics[C_OFFSET+OFFSET_1+2*i];
        int Gv0 = help_statistics[G_OFFSET+2*i], Gv1 = help_statistics[G_OFFSET+OFFSET_1+2*i];
        int Tv0 = help_statistics[T_OFFSET+2*i], Tv1 = help_statistics[T_OFFSET+OFFSET_1+2*i];
        int sumACGT = Av0+Av1+Cv0+Cv1+Gv0+Gv1+Tv0+Tv1;
        double entropy=0;

        double entr_attrA=countAttrEntr(Av0, Av1);
        double entr_attrC=countAttrEntr(Cv0, Cv1);
        double entr_attrG=countAttrEntr(Gv0, Gv1);
        double entr_attrT=countAttrEntr(Tv0, Tv1);

        if( sumACGT!=0 ) entropy = (Av0+Av1+0.0)/sumACGT*std::max(entr_attrA, 0.0) 
                                 + (Cv0+Cv1+0.0)/sumACGT*std::max(entr_attrC, 0.0) 
                                 + (Gv0+Gv1+0.0)/sumACGT*std::max(entr_attrG, 0.0) 
                                 + (Tv0+Tv1+0.0)/sumACGT*std::max(entr_attrT, 0.0);
        attr_class_entropy.push_back(AttrClassEntropy((char)i, 'A', entr_attrA));
        attr_class_entropy.push_back(AttrClassEntropy((char)i, 'C', entr_attrC));
        attr_class_entropy.push_back(AttrClassEntropy((char)i, 'G', entr_attrG));
        attr_class_entropy.push_back(AttrClassEntropy((char)i, 'T', entr_attrT));

        attr_entropy.push_back(AttrEntropy((char)i, entropy));
    }
}

double Entropy::countAttrEntr(int n1, int n2){
    if( n1+n2 != 0){
        double p_0 = n1/(n1+n2+0.0);
        double p_1 = n2/(n1+n2+0.0);

        if(p_0==0){
            return p_1*log(1.0/p_1);
        }else if(p_1==0){
            return p_0*log2(1.0/p_0); 
        }
        return p_0*log2(1.0/p_0)+p_1*log(1.0/p_1);
    }else return -1;
}

char Entropy::getLowestEntropyAttr(std::string used_attrs){
    std::vector<AttrEntropy>::iterator it = attr_entropy.begin();
    double lowest=it->getValue();
    char low_attr=it->getAttr();
    for( it; it<attr_entropy.end(); it++ ){
        std::string act_attr = std::string(".").append(std::to_string(it->getAttr()).append("."));
        if( used_attrs.find(act_attr) == std::string::npos ){
            if( (it->getValue()<lowest && it->getValue()!=-1) || (it->getValue()!=-1 && lowest==-1)){
                lowest = it->getValue();
                low_attr = it->getAttr();
            }
        }
    }
    return low_attr;
}

void Entropy::printEntropyAttr(){
    std::vector<AttrEntropy>::iterator it = attr_entropy.begin();
    for(it; it<attr_entropy.end(); it++){
        it->printEntropy();
    }
}

void Entropy::printEntropyAVal(){
    std::vector<AttrClassEntropy>::iterator it = attr_class_entropy.begin();
    for(it; it<attr_class_entropy.end(); it++ ){
        it->printEntropy();
    }
}

void initZero(int* var, int size){
    for(int i=0; i<size; i++){
        var[i]=0;
    }
}