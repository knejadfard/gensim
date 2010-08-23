#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "member.hpp"

template <class Phenotype> class population {
protected:
    class compare_members {
        member< Phenotype > &al;
    public:
        compare_members(member< Phenotype >& alpha): al(alpha) {}
        bool operator()(const member< Phenotype >& lhs, const member< Phenotype >& rhs) {
            return lhs.get_phenotype().fitness(al.get_phenotype())<rhs.get_phenotype().fitness(al.get_phenotype());
        }
    };
    //virtual void filter(); //select certain members to remain in next generation
    void sort();
public:
    typedef member< Phenotype > member_t;
    typedef std::vector<member_t> vector_t;
    typedef typename vector_t::iterator iterator_t;
    vector_t pvec; //members of population are held here
    member_t a; //alpha member of population
    population(const member_t& alpha, const size_t& size);
    virtual void evolve(const size_t& cycles); //take members to the next generation
    void print();
    size_t size() const;
};

template <class Phenotype> population<Phenotype>::population(const member_t& alpha, const size_t& size): pvec(), a(alpha) {
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member_t());
    }
}

template <class Phenotype> inline size_t population<Phenotype>::size() const{
    return pvec.size();
}

template <class Phenotype> void population<Phenotype>::evolve(const size_t& cycles) {
    compare_members cmp(a);
    for(size_t i=0; i<cycles; i++) {
        sort();
        vector_t nvec;
        nvec.push_back(pvec.at(0));
        nvec.push_back(pvec.at(1));
        nvec.push_back(pvec.at(0)+pvec.at(1));
        for(int i=2;i<pvec.size()-1; i++) {
            nvec.push_back(pvec.at(i)+pvec.at(i+1));
            nvec.back().get_phenotype().mutate(0.1);
        }
        pvec = nvec;
    }
}

template <class Phenotype> void population<Phenotype>::print() {
    for(iterator_t it=pvec.begin(); it!=pvec.end(); it++) {
        std::cout<<"Phenotype: <"<<it->get_phenotype()<<"> Fitness: <"<<it->get_phenotype().fitness(a.get_phenotype())<<">"<<std::endl;
    }
}

template <class Phenotype> inline void population<Phenotype>::sort() {
    compare_members cmp(a);
    std::sort(pvec.begin(), pvec.end(), cmp);
}

#endif // POPULATION_H
