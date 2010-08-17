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

//ADD CROSSOVER
class member {
    phenotype<char, 10, chphenotype> phen;
public:
    //void random_range(siterator& it1, siterator& it2);
    member(); //generates random phenotype
    //member(const std::string& phenotype);
    member(const member& rhs); //copies phenotype of another member
    member(const phenotype<char, 10, chphenotype>& data);
    member& operator=(const member& rhs); //copies phenotype of another member
    //size_t calculate_fitness(const member& alpha) const; //calculate fitness based on the alpha
    int fitness(const member& alpha);
    //void mutate(const size_t& max_percent); //randomly apply mutations to phenotype
    //std::string first_half() const; //return phenotype's first half
    //std::string second_half() const; //return phenotype's second half
    //member generate(const size_t& size) const; //generate a random member
    member mate(const member& rhs) const;
    //member breed(const member& rhs) const;
    //void crossover(member& rhs); //MODIFY TO APPLY RANDOM RANGE CROSS
    const phenotype<char, 10, chphenotype>& get_phenotype() const;
    phenotype<char, 10, chphenotype>& get_phenotype();
    void set_phenotype(const phenotype<char, 10, chphenotype>& pheno);
    //unsigned int fitness();
    //bool operator<(const member& rhs) const; //compare fitness
};

//inline member::member(const std::string& phenotype): phen(phenotype) {}

inline member::member(): phen() {}

inline member::member(const member& rhs): phen() {
    //srand(time(0));
    operator=(rhs);
}

inline member::member(const phenotype<char, 10, chphenotype>& data): phen(data) {}

inline const phenotype<char, 10, chphenotype>& member::get_phenotype() const {
    return phen;
}

inline phenotype<char, 10, chphenotype>& member::get_phenotype() {
    return phen;
}

/*inline unsigned int member::fitness() {
    return ft;
}*/

/*inline char member::random_char(const char& a, const char& b) const {
    return rand()%(b-a+1) + a;
}*/

/*size_t member::calculate_fitness(const member& alpha) const {
    //if(alpha.phen.size() != phen.size())
        //throw exception
        size_t ft = 0; //must become 0 when recalculating fitness
        for(size_t i=0; i<phen.size(); i++) {
            ft += abs(phen.at(i)-alpha.phen.at(i));
        }
        return ft;
}*/

inline int member::fitness(const member& alpha) const {
    return phen.fitness(alpha.get_phenotype());
}

/*inline void member::mutate(const size_t& max_percent) {
    size_t mutate_count = floor( float(rand()%max_percent)/100*phen.size() );
    for(size_t i=0; i<mutate_count; i++) {
        phen.at( rand()%phen.size() ) = random_char('a', 'z'); //assign random value to random index
    }
}*/

inline member& member::operator=(const member& rhs) {
    if(this==&rhs) return *this;
    phen = rhs.get_phenotype();
    return *this;
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

inline void member::set_phenotype(const phenotype<char, 10, chphenotype>& pheno) {
    phen = pheno;
}

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

inline member member::mate(const member& rhs) const {
    return phen.mix(rhs.get_phenotype());
}

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
