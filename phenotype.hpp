#ifndef PHENOTYPE_H
#define PHENOTYPE_H

#include <cmath>
#include <vector>
#include <iostream>
#include "ranum.hpp"

//RECONSIDER size_t?
//CONSIDER USING TYPEDEF TO MAKE LIFE EASIER
template<class T, size_t size, class Tpolicy> class phenotype {
    T pdata[size]; //phenotype data
public:
    phenotype(const T& a); //make phenotype using a single element, copied to fill pdata
    phenotype(); //make phenotype with random data
    phenotype(const phenotype<T, size, Tpolicy>& rhs);
    phenotype(const T data[size]);
    phenotype<T, size, Tpolicy>& operator=(const phenotype<T, size, Tpolicy>& rhs);
    int fitness(const phenotype<T, size, Tpolicy>& rhs) const;
    char& operator[](const size_t& index);
    const char& operator[](const size_t& index) const;
    void mutate(const float& rate);
    phenotype<T, size, Tpolicy> operator+(const phenotype<T, size, Tpolicy>& rhs) const;
};

template<class T, size_t size, class Tpolicy> inline phenotype<T, size, Tpolicy>::phenotype(const phenotype<T, size, Tpolicy>& rhs) {
    operator=(rhs);
}

template<class T, size_t size, class Tpolicy> phenotype<T, size, Tpolicy>::phenotype(const T& a) {
    for(size_t i=0; i<size; i++) {
        pdata[i] = a;
    }
}

template<class T, size_t size, class Tpolicy> phenotype<T, size, Tpolicy>::phenotype() {
    for(size_t i=0; i<size; i++) {
        pdata[i] = Tpolicy::random();
    }
}

//NEEDS MORE RESTRICTION FOR DATA'S SIZE
template<class T, size_t size, class Tpolicy> phenotype<T, size, Tpolicy>::phenotype(const T data[size]) {
    for(int i=0; i<size; i++) {
        pdata[i] = data[i];
    }
}

template<class T, size_t size, class Tpolicy> inline char& phenotype<T, size, Tpolicy>::operator[](const size_t& index) {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}

template<class T, size_t size, class Tpolicy> inline const char& phenotype<T, size, Tpolicy>::operator[](const size_t& index) const {
    //CHECK BOUNDS
    //ADD EXCEPTION
    return pdata[index];
}


template<class T, size_t size, class Tpolicy> int phenotype<T, size, Tpolicy>::fitness(const phenotype<T, size, Tpolicy>& rhs) const {
    size_t fitness = 0;
    for(int i=0; i<size; i++) {
        fitness += abs(rhs[i] - pdata[i]);
    }
    return fitness;
}

template<class T, size_t size, class Tpolicy> phenotype<T, size, Tpolicy>& phenotype<T, size, Tpolicy>::operator=(const phenotype<T, size, Tpolicy>& rhs) {
    if(this==&rhs) return *this;
    for(size_t i=0; i<size; i++) {
       pdata[i] = rhs[i];
    }
    return *this;
}

template<class T, size_t size, class Tpolicy> void phenotype<T, size, Tpolicy>::mutate(const float& rate) {
    adl::ranum &t = adl::ranum::get();
    size_t mutate_count = floor(rate*t.generate(0, size));
    for(size_t i=0; i<mutate_count; i++) {
        pdata[t.generate(0, size-1)] = Tpolicy::random();
    }
}

//MAY NEED IMPROVEMENT
template<class T, size_t size, class Tpolicy> phenotype<T, size, Tpolicy> phenotype<T, size, Tpolicy>::operator+(const phenotype<T, size, Tpolicy>& rhs) const {
    T tmp[size];
    int half = ceil((float)size/2);
    for(int i=0; i<half; i++) {
        tmp[i] = pdata[i];
    }
    for(int i=half; i<size; i++) {
        tmp[i] = rhs[i];
    }
    return tmp;
}

//global overload for output to ostream
template<class T, size_t size, class Tpolicy> std::ostream& operator<<(std::ostream& out, const phenotype<T, size, Tpolicy>& rhs) {
    for(size_t i=0; i<size; i++) {
        out<<rhs[i];
    }
    return out;
}

#endif
