#ifndef POPULATION_H
#define POPULATION_H

#include <iostream> //for output about cycles in evolve function
#include <vector>
#include <algorithm>
#include "member.hpp"

class population {
    std::vector<member> pvec;
    member alpha;
public:
    class compare_members {
        member mem;
    public:
        compare_members(const member& alpha_member): mem(alpha_member) {}
        bool operator()(const member& lhs, const member& rhs) {
            return lhs.cfitness(mem)<rhs.cfitness(mem);
        }
    };
    typedef std::vector<member>::iterator miterator;
    population(const member& alpha_member, const size_t& size);
    void evolve(const size_t& cycles);
    void print();
};

population::population(const member& alpha_member, const size_t& size): pvec(), alpha(alpha_member) {
    //generate random population
    srand(time(0));
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member(11));
    }
}

void population::evolve(const size_t& cycles) {
    compare_members cmp(alpha);
    for(size_t i=0; i<cycles; i++) {
        for(miterator it1=pvec.begin(); it1!=pvec.end(); it1++) {
            //it1->crossover(*it2);
            it1->mutate(70);
        }
        std::sort(pvec.begin(), pvec.end(), cmp);
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



#endif // POPULATION_H
