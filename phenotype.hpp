#ifndef PHENOTYPE_H
#define PHENOTYPE_H

//needed to define default traits for a char phenotype
#include "chphenotype.hpp"

//default to char phenotype
//RECONSIDER size_t?
template<class T=char, size_t size, class Ttraits=chphenotype> class phenotype {
    //T pdata[size]; //phenotype data
    std::vector<T> pdata;
public:
    phenotype(const T* phenotype_data); //make phenotype using an array of data
    phenotype(const T& a); //make phenotype using a single element, copied to fill pdata
    phenotype(); //make phenotype with random data
    int fitness(const phenotype<T, size, Ttraits>& rhs) const; 
};

template<class T=char, size_t size> phenotype::phenotype(const T* phenotype_data): pdata() {
    pdata.reserve(size); //reserve capacity for at least size elements
    for(size_t i=0; i<size; i++) {
       pdata.push_back(phenotype_data[i]); 
    }
}

template<class T=char, size_t size> phenotype<T, size>::phenotype(const T& a): pdata() {
    pdata.reserve(size);
    for(size_t i=0; i<size; i++) {
        pdata.push_back(a);
    }
}

template<class T=char, size_t size, class Ttraits=chphenotype> phenotype<T, size, Ttraits>::phenotype(): pdata() {
    pdata.reserve(size);
    for(size_t i=0; i<size; i++) {
        pdata.push_back(ttraits::generate_random());
    }
}

template<class T=char, size_t size, class Ttraits=chphenotype> int phenotype<T, size, Ttraits>::fitness(const phenotype<T, size, Ttraits>& rhs) const {

}

//Char form
/*template<int size> class phenotype<char, size> {

};*/

#endif
