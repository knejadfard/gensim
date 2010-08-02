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
    typedef std::vector<member>::iterator miterator;
    population(const size_t& size);
    void evolve(const size_t& cycles);
    void print();
};

population::population(const size_t& size): pvec(), alpha("hello world") {
    //generate random population
    srand(time(0));
    for(size_t i=0; i<size; i++) {
        pvec.push_back(member(11));
    }
}

void population::evolve(const size_t& cycles) {
    for(size_t i=0; i<cycles; i++) {
        for(miterator it1=pvec.begin(); it1!=pvec.end(); it1++) {
            //it1->crossover(*it2);
            it1->mutate(12); //mutate with 12% chance
        }
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
