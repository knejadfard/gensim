#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "member.hpp"

template <class Phenotype> class population {
    typedef member< Phenotype > member_t;
    typedef typename std::vector<member_t>::iterator miterator;
    std::vector<member_t> pvec;
    member_t a;
    void advance();

    class compare_members {
        member_t a;
    public:
        compare_members(const member_t& alpha): a(alpha) {}
        bool operator()(const member_t& lhs, const member_t& rhs) {
            return lhs.get_phenotype().fitness(a.get_phenotype())<rhs.get_phenotype().fitness(a.get_phenotype());
        }
    } cmp;
public:

    population(const member_t& alpha, const size_t& size);
    void evolve(const size_t& cycles);
    void print();
    size_t size() const;
};

template <class Phenotype> population<Phenotype>::population(const member_t& alpha, const size_t& size): pvec(), a(alpha), cmp(alpha) {
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member_t());
    }
}
template <class Phenotype> size_t population<Phenotype>::size() const{
    return pvec.size();
}
template <class Phenotype> void population<Phenotype>::evolve(const size_t& cycles) {
    for(size_t i=0; i<cycles; i++) {
        std::sort(pvec.begin(), pvec.end(), cmp);
        advance();
        std::cout<<"\rCycle "<<i+1<<" Completed.";
    }
    std::cout<<std::endl;
}
template <class Phenotype> void population<Phenotype>::print() {
    for(miterator it=pvec.begin(); it!=pvec.end(); it++) {
        std::cout<<"Phenotype: <"<<it->get_phenotype()<<"> Fitness: <"<<it->get_phenotype().fitness(a.get_phenotype())<<">"<<std::endl;
    }
}
template <class Phenotype> void population<Phenotype>::advance() {
    std::vector<member_t> nvec;
    nvec.push_back(pvec.at(0));
    nvec.push_back(pvec.at(1));
    nvec.push_back(pvec.at(0)+pvec.at(1));
    for(int i=2;i<pvec.size()-1; i++) {
        nvec.push_back(pvec.at(i)+pvec.at(i+1));
        nvec.back().get_phenotype().mutate(0.1);
    }
    pvec = nvec;
    std::sort(pvec.begin(), pvec.end(), cmp);
}

#endif // POPULATION_H
