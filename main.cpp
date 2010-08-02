#include <iostream>
#include <exception>
#include <sstream>
#include <memory>

#include "member.hpp"
#include "population.hpp"

using namespace std;

int main(int argc, char **argv) {
    try {
        //Changed to dynamic allocation to be able to release before heavy operation
        auto_ptr<stringstream> i = auto_ptr<stringstream>(new stringstream);
        (*i)<<argv[2]<<" "<<argv[3];
        int cycles, size;
        (*i)>>size>>cycles;
        i.reset(); //destruct the allocated memory
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
