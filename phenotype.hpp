#ifndef PHENOTYPE_H
#define PHENOTYPE_H

#include <cmath>
#include "chphenotype.hpp"

//default to char phenotype
//RECONSIDER size_t?
template<class T, size_t size, class Ttraits> class phenotype {
    T pdata[size]; //phenotype data
    //std::vector<T> pdata;
public:
    //phenotype(const T* phenotype_data); //make phenotype using an array of data
    phenotype(const T& a); //make phenotype using a single element, copied to fill pdata
    phenotype(); //make phenotype with random data
    phenotype(const phenotype<T, size, Ttraits>& rhs);
    phenotype<T, size, Ttraits>& operator=(const phenotype<T, size, Ttraits>& rhs);
    int fitness(const phenotype<T, size, Ttraits>& rhs) const;
    char& operator[](const size_t& index);
    const char& operator[](const size_t& index) const;
};

template<class T, size_t size, class Ttraits> inline phenotype::phenotype(const phenotype<T, size, Ttraits>& rhs): pdata() {
    operator=(rhs);
}

template<class T, size_t size, class Ttraits> phenotype<T, size, Ttraits>::phenotype(const T& a): pdata() {
    for(size_t i=0; i<size; i++) {
        pdata[i] = a;
    }
}

template<class T, size_t size, class Ttraits> phenotype<T, size, Ttraits>::phenotype(): pdata() {
    for(size_t i=0; i<size; i++) {
        pdata[i] = Ttraits::random();
    }
}

template<class T, size_t size, class Ttraits> inline char& phenotype<T, size, Ttraits>::operator[](const size_t& index) {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}

template<class T, size_t size, class Ttraits> inline const char& phenotype<T, size, Ttraits>::operator[](const size_t& index) const {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}


template<class T, size_t size, class Ttraits> int phenotype<T, size, Ttraits>::fitness(const phenotype<T, size, Ttraits>& rhs) const {
    size_t fitness = 0;
    for(int i=0; i<size; i++) {
        fitness += abs(rhs[i] - pdata[i]);
    }
    return fitness;
}

template<class T, size_t size, class Ttraits> phenotype<T, size, Ttraits> operator=(const phenotype<T, size, Ttraits>& rhs) {
    if(this==&rhs) return *this;
    for(size_t i=0; i<size; i++) {
       pdata[i] = rhs[i];
    }
    return *this;
}

#endif
