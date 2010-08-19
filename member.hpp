#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

template<class P> class member {
    P phen;
public:
    member(); //initialize member with random phenotype
    member(const member& rhs);
    member(const P& data); //initialize member from a given phenotype, should stay implicit
    member& operator=(const member& rhs); //self-wise
    int fitness(const member& alpha) const;
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

template<class P> inline member<P> member<P>::operator+(const member<P>& rhs) const {
    return phen + rhs.get_phenotype();
}

#endif //MEMBER_H
