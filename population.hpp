#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "member.hpp"
#include "phenotype.hpp"
#include "chphenotype.hpp"

class population {
    typedef member< phenotype<char, 10, chphenotype> > member_t;
    typedef std::vector<member_t>::iterator miterator;
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

population::population(const member_t& alpha, const size_t& size): pvec(), a(alpha), cmp(alpha) {
    //generate random population
    srand(time(0));
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member_t());
    }
}

size_t population::size() const{
    return pvec.size();
}

void population::evolve(const size_t& cycles) {
    for(size_t i=0; i<cycles; i++) {
        /*for(miterator it1=pvec.begin(); it1!=pvec.end(); it1++) {
            //it1->crossover(*it2);
            it1->mutate(20);
        }*/
        std::sort(pvec.begin(), pvec.end(), cmp);
        advance();
        //usleep(1000);
        std::cout<<"\rCycle "<<i+1<<" Completed.";
    }
    std::cout<<std::endl;
}

void population::print() {
    for(miterator it=pvec.begin(); it!=pvec.end(); it++) {
        std::cout<<"Phenotype: <"<<it->get_phenotype()<<"> Fitness: <"<<it->get_phenotype().fitness(a.get_phenotype())<<">"<<std::endl;
    }
}

void population::advance() {
    //remove last quarter, must be sorted
    //int count = ceil(float(pvec.size())/4);
    /*for(int i=0; i<count; i++) {
        pvec.pop_back();
    }*/
    std::vector<member_t> nvec;
    //add best quarter to new population
    /*for(int i=0; i<count; i++) {
        nvec.push_back(pvec.at(i));
    }*/
    nvec.push_back(pvec.at(0));
    nvec.push_back(pvec.at(1));

    nvec.push_back(pvec.at(0)+pvec.at(1));
    for(int i=2;i<pvec.size()-1; i++) {
        nvec.push_back(pvec.at(i)+pvec.at(i+1));
        //mutate new member
        nvec.back().get_phenotype().mutate(0.1);
    }
    pvec = nvec;
    std::sort(pvec.begin(), pvec.end(), cmp);
}

#endif // POPULATION_H
