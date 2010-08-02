#ifndef POPULATION_H
#define POPULATION_H

#include <iostream> //for output about cycles in evolve function
#include <vector>
#include <algorithm>
#include <cmath>

#include "member.hpp"

class population {
    std::vector<member> pvec;
    member alpha;
    void advance();

    class compare_members {
        member alpha;
    public:
        compare_members(const member& alpha_member): alpha(alpha_member) {}
        bool operator()(const member& lhs, const member& rhs) {
            return lhs.cfitness(alpha)<rhs.cfitness(alpha);
        }
    };

public:
    typedef std::vector<member>::iterator miterator;

    compare_members cmp;

    population(const member& alpha_member, const size_t& size);
    void evolve(const size_t& cycles);
    void print();
    size_t size() const;
};

population::population(const member& alpha_member, const size_t& size): pvec(), alpha(alpha_member), cmp(alpha) {
    //generate random population
    srand(time(0));
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member(alpha.get_phenotype().size()));
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
        std::cout<<"Phenotype: <"<<it->get_phenotype()<<"> Fitness: <"<<it->cfitness(alpha)<<">"<<std::endl;
    }
}

void population::advance() {
    //remove last quarter, must be sorted
    //int count = ceil(float(pvec.size())/4);
    /*for(int i=0; i<count; i++) {
        pvec.pop_back();
    }*/
    std::vector<member> nvec;
    //add best quarter to new population
    /*for(int i=0; i<count; i++) {
        nvec.push_back(pvec.at(i));
    }*/
    nvec.push_back(pvec.at(0));
    nvec.push_back(pvec.at(1));

    nvec.push_back(pvec.at(0).mate(pvec.at(1)));
    for(int i=2;i<pvec.size()-1; i++) {
        nvec.push_back(pvec.at(i).mate(pvec.at(i+1)));
        //mutate new member
        nvec.back().mutate(30);
    }
    pvec = nvec;
    std::sort(pvec.begin(), pvec.end(), cmp);
}

#endif // POPULATION_H
