#ifndef PHENOTYPE_H
#define PHENOTYPE_H

//needed to define default traits for a char phenotype
#include <cmath>
#include "chphenotype.hpp"

//default to char phenotype
//RECONSIDER size_t?
template<class T=char, size_t size, class Ttraits=chphenotype> class phenotype {
    T pdata[size]; //phenotype data
    //std::vector<T> pdata;
public:
    //phenotype(const T* phenotype_data); //make phenotype using an array of data
    phenotype(const T& a); //make phenotype using a single element, copied to fill pdata
    phenotype(); //make phenotype with random data
    phenotype(const phenotype<T, size, Ttraits>& rhs);
    int fitness(const phenotype<T, size, Ttraits>& rhs) const;
    char& operator[](const size_t& index);
    const char& operator[](const size_t& index);
};

template<class T=char, size_t size, class Ttraits=chphenotype> phenotype::phenotype(const phenotype<T, size, Ttraits>& rhs): pdata() {
    //pdata.reserve(size); //reserve capacity for at least size elements
    for(size_t i=0; i<size; i++) {
       //pdata.push_back(phenotype_data[i]); 
       pdata[i] = rhs[i];
    }
}

template<class T=char, size_t size> phenotype<T, size>::phenotype(const T& a): pdata() {
    //pdata.reserve(size);
    for(size_t i=0; i<size; i++) {
        pdata.push_back(a);
    }
}

template<class T=char, size_t size, class Ttraits=chphenotype> phenotype<T, size, Ttraits>::phenotype(): pdata() {
    //pdata.reserve(size);
    for(size_t i=0; i<size; i++) {
        //pdata.push_back(Ttraits::generate_random());
        pdata[i] = Ttraits::generate_random();
    }
}

template<size_t size> inline char& phenotype::operator[](const size_t& index) {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}

template<size_t size> inline const char& phenotype::operator[](const size_t& index) {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}


template<class T=char, size_t size, class Ttraits=chphenotype> int phenotype<T, size, Ttraits>::fitness(const phenotype<T, size, Ttraits>& rhs) const {
    size_t fitness = 0;
    for(int i=0; i<size; i++) {
        fitness += abs(rhs[i] - pdata[i]);
    }
    return fitness;
}

//Char form
/*template<int size> class phenotype<char, size> {

};*/

#endif
