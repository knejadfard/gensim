#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

template<class Phenotype> class member {
    Phenotype phen;
public:
    member(); //initialize member with random phenotype
    member(const member& rhs);
    member(const Phenotype& data); //initialize member from a given phenotype, should stay implicit
    member& operator=(const member& rhs); //self-wise
    int fitness(const member& alpha) const;
    const Phenotype& get_phenotype() const;
    Phenotype& get_phenotype();
    void set_phenotype(const Phenotype& pheno);
    member<Phenotype> operator+(const member<Phenotype>& rhs) const; //generate a newborn
};

template<class Phenotype> inline member<Phenotype>::member(): phen() {}

template<class Phenotype> inline member<Phenotype>::member(const member<Phenotype>& rhs): phen() {
    operator=(rhs);
}

template<class Phenotype> inline member<Phenotype>::member(const Phenotype& data): phen(data) {}

template<class Phenotype> inline const Phenotype& member<Phenotype>::get_phenotype() const {
    return phen;
}

template<class Phenotype> inline Phenotype& member<Phenotype>::get_phenotype() {
    return phen;
}

template<class Phenotype> inline int member<Phenotype>::fitness(const member<Phenotype>& alpha) const {
    return phen.fitness(alpha.get_phenotype());
}

template<class Phenotype> inline member<Phenotype>& member<Phenotype>::operator=(const member<Phenotype>& rhs) {
    if(this==&rhs) return *this;
    phen = rhs.get_phenotype();
    return *this;
}

template<class Phenotype> inline void member<Phenotype>::set_phenotype(const Phenotype& pheno) {
    phen = pheno;
}

template<class Phenotype> inline member<Phenotype> member<Phenotype>::operator+(const member<Phenotype>& rhs) const {
    return phen + rhs.get_phenotype();
}

#endif //MEMBER_H
