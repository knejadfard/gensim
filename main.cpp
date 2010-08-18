#include <iostream>
#include <exception>
#include <sstream>

#include "member.hpp"
#include "population.hpp"

using namespace std;

int main(int argc, char **argv) {
    try {
        //Changed to dynamic allocation to be able to release before heavy operation
        stringstream *i = new stringstream;
        (*i)<<argv[2]<<" "<<argv[3];
        int cycles, size;
        (*i)>>size>>cycles;
        delete i;
        //
        population p(member(argv[1]), size);
        p.print();
        p.evolve(cycles);
        p.print();
        cout<<"Size: "<<p.size()<<endl;
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
