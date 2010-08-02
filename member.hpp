#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>					// for cout etc.
#include <string>					// for string class
#include <cstdlib>
#include <ctime>					// for random seed
#include <cmath>					// for abs()

typedef std::string::iterator siterator;

//ADD CROSSOVER
class member {
    std::string phen; //phenotype
    //unsigned int ft; //fitness
    char random_char(const char& a, const char& b) const;
    member() {} //no default constructor allowed
public:
    void random_range(siterator& it1, siterator& it2);
    member(const size_t& size); //generates random phenotype
    member(const std::string& phenotype);
    member(const member& rhs); //copies phenotype of another member
    member& operator=(const member& rhs); //copies phenotype of another member
    size_t cfitness(const member& alpha) const; //calculate fitness based on the alpha
    void mutate(const size_t& max_percent); //randomly apply mutations to phenotype
    std::string first_half(); //return phenotype's first half
    std::string second_half(); //return phenotype's second half
    member generate(const size_t& size) const; //generate a random member
    member mate(const member& rhs) const;
    //member breed(const member& rhs) const;
    //void crossover(member& rhs); //MODIFY TO APPLY RANDOM RANGE CROSS
    const std::string& get_phenotype() const;
    std::string& get_phenotype();
    void set_phenotype(const std::string& phenotype);
    //unsigned int fitness();
    //bool operator<(const member& rhs) const; //compare fitness
};

inline member::member(const std::string& phenotype): phen(phenotype) {}

inline member::member(const size_t& size): phen() {
    operator=(generate(size));
}

inline member::member(const member& rhs): phen() {
    //srand(time(0));
    operator=(rhs);
}

inline const std::string& member::get_phenotype() const {
    return phen;
}

inline std::string& member::get_phenotype() {
    return phen;
}

/*inline unsigned int member::fitness() {
    return ft;
}*/

inline char member::random_char(const char& a, const char& b) const {
    return rand()%(b-a+1) + a;
}

size_t member::cfitness(const member& alpha) const {
    //if(alpha.phen.size() != phen.size())
        //throw exception
        size_t ft = 0; //must become 0 when recalculating fitness
        for(size_t i=0; i<phen.size(); i++) {
            ft += abs(phen.at(i)-alpha.phen.at(i));
        }
        return ft;
}

inline void member::mutate(const size_t& max_percent) {
    size_t mutate_count=floor(float(rand()%max_percent)/100*phen.size()); //NEEDS SOME CLEANUP
    for(size_t i=0; i<mutate_count; i++) {
        int index = rand()%phen.size(); //generate random index
        phen.at(index) = random_char('a', 'z'); //assign random value to random index
    }
}

inline member& member::operator=(const member& rhs) {
    if(this==&rhs) return *this;
    phen = rhs.get_phenotype();
    //ft = rhs.fitness();
    return *this;
}

member member::generate(const size_t& size) const {
    std::string rstr;
    for(size_t i=0; i<size; i++) {
        rstr += random_char('a', 'z');
    }
    return member(rstr);
}

/*inline bool member::operator<(const member& rhs) const {
    return cfitness()<rhs.cfitness();
}*/

inline void member::set_phenotype(const std::string& phenotype) {
    phen = phenotype;
}

/*void member::crossover(member& rhs) {
    //siterator it1=rhs.get_phenotype().begin(), it2=it1+5;
    //siterator it3=phen.begin()+2;
    siterator it1, it2;
    //random_range(it1, it2);
    swap_ranges(it1, it2, phen.begin());
}*/

std::string member::first_half() {
    size_t index = ceil((float)phen.size()/2);
    std::string tmp;
    for(size_t i=0; i<index; i++) {
        tmp += phen.at(i);
    }
    return tmp;
}

std::string member::second_half() {
    size_t index = ceil((float)phen.size()/2);
    std::string tmp;
    for(; index<phen.size(); index++) {
        tmp += phen.at(index);
    }
    return tmp;
}

member member::mate(const member& rhs) {
    std::string tstr = first_half()+rhs.second_half();
    
}

void member::random_range(siterator& it1, siterator& it2) {
    it1 = phen.begin();
    size_t i1 = rand()%(phen.size()), i2 = rand()%(phen.size()-i1) + i1;
    for(;i1>1;i1--) {
        it1++;
    }
    it2 = it1;
    for(;i2>1;i2--) {
        it2++;
    }
}

#endif //MEMBER_H
