#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "phenotype.hpp"
#include "chphenotype.hpp"

//typedef std::string::iterator siterator;

template<class P> class member {
    P phen;
public:
    //void random_range(siterator& it1, siterator& it2);
    member(); //initialize member with random phenotype
    member(const member& rhs);
    member(const P& data); //initialize member from a given phenotype, should stay implicit
    member& operator=(const member& rhs); //self-wise
    int fitness(const member& alpha) const;
    //std::string first_half() const; //return phenotype's first half
    //std::string second_half() const; //return phenotype's second half
    //member mate(const member& rhs) const;
    const P& get_phenotype() const;
    P& get_phenotype();
    void set_phenotype(const P& pheno);
    member<P> operator+(const member<P>& rhs) const; //generate a newborn
};

template<class P> inline member<P>::member(): phen() {}

template<class P> inline member<P>::member(const member<P>& rhs): phen() {
    operator=(rhs);
}

template<class P> inline member<P>::member(const P& data): phen(data) {}

template<class P> inline const P& member<P>::get_phenotype() const {
    return phen;
}

template<class P> inline P& member<P>::get_phenotype() {
    return phen;
}

template<class P> inline int member<P>::fitness(const member<P>& alpha) const {
    return phen.fitness(alpha.get_phenotype());
}

template<class P> inline member<P>& member<P>::operator=(const member<P>& rhs) {
    if(this==&rhs) return *this;
    phen = rhs.get_phenotype();
    return *this;
}

template<class P> inline void member<P>::set_phenotype(const P& pheno) {
    phen = pheno;
}

/*template<class P> inline member<P> member<P>::mate(const member<P>& rhs) const {
    return phen + rhs.get_phenotype();
}*/

template<class P> inline member<P> member<P>::operator+(const member<P>& rhs) const {
    return phen + rhs.get_phenotype();
}

/*member member::generate(const size_t& size) const {
    std::string rstr;
    for(size_t i=0; i<size; i++) {
        rstr += random_char('a', 'z');
    }
    return member(rstr);
}*/

/*inline bool member::operator<(const member& rhs) const {
    return calculate_fitness()<rhs.calculate_fitness();
}*/

/*void member::crossover(member& rhs) {
    //siterator it1=rhs.get_phenotype().begin(), it2=it1+5;
    //siterator it3=phen.begin()+2;
    siterator it1, it2;
    //random_range(it1, it2);
    swap_ranges(it1, it2, phen.begin());
}*/

/*std::string member::first_half() const {
    size_t index = ceil((float)phen.size()/2);
    std::string tmp;
    for(size_t i=0; i<index; i++) {
        tmp += phen.at(i);
    }
    return tmp;
}

std::string member::second_half() const {
    size_t index = ceil((float)phen.size()/2);
    std::string tmp;
    for(; index<phen.size(); index++) {
        tmp += phen.at(index);
    }
    return tmp;
}*/

/*void member::random_range(siterator& it1, siterator& it2) {
    it1 = phen.begin();
    size_t i1 = rand()%(phen.size()), i2 = rand()%(phen.size()-i1) + i1;
    for(;i1>1;i1--) {
        it1++;
    }
    it2 = it1;
    for(;i2>1;i2--) {
        it2++;
    }
}*/

#endif //MEMBER_H
