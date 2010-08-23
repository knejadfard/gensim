#include <iostream>
#include <exception>
#include <sstream>

#include "member.hpp"
#include "population.hpp"
#include "phenotype.hpp"
//#include "chphenotype.hpp"
#include "ranum.hpp"

class int_policy {
public:
    static int random() {
        adl::ranum &r = adl::ranum::get();
        return r.generate(0, 9);
    }
};

typedef phenotype<int, 5, int_policy> iphen_t;

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
        int alpha[] = {5,2,0,0,5};
        population<iphen_t> p(member<iphen_t>(alpha), size);
        p.print();
        p.evolve(cycles);
        p.print();
        cout<<"Size: "<<p.size()<<endl;
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
