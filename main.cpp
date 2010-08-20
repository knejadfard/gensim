#include <iostream>
#include <exception>
#include <sstream>

#include "member.hpp"
#include "population.hpp"
#include "phenotype.hpp"
#include "chphenotype.hpp"

typedef phenotype<char, 10, chphenotype> phen_t;

using namespace std;

int main(int argc, char **argv) {
    try {
        //Changed to dynamic allocation to be able to release before heavy operation
        stringstream *i = new stringstream;
        (*i)<<argv[1]<<" "<<argv[2];
        int cycles, size;
        (*i)>>size>>cycles;
        delete i;
        //
        population<phen_t> p(member<phen_t>('a'), size);
        p.print();
        p.evolve(cycles);
        p.print();
        cout<<"Size: "<<p.size()<<endl;
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
