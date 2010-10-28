#include <iostream>
#include <exception>
#include <sstream>

#include "member.hpp"
#include "population.hpp"
#include "phenotype.hpp"
#include "ranum.hpp"

class int_policy {
public:
    static int random() {
        return ranum::object().generate(0, 9);
    }
};

typedef phenotype<int, 5, int_policy> iphen_t;

/*class pop: public population<iphen_t> {
public:
    pop(const member_t& alpha, const size_t& size): pvec(), a(alpha) {
        for(size_t i=0; i<size; i++) {
            pvec.push_back(member_t());
        }
    }
    void evolve() {
        sort();
        population<iphen_t>::vector_t nvec;
        size_t middle = pvec.size()/2;
        //nvec.push_back(pvec.at(0));
        //nvec.push_back(pvec.at(1));
        for(iterator_t i=pvec.begin(); (*i)!=pvec.at(middle); i++) {
            nvec.push_back(*i);
        }
        for(size_t i=middle; i<pvec.size(); i++) {
            nvec.push_back(pvec.at(i-middle)+pvec.at(i-middle+1));
        }
        pvec = nvec;
    }
};*/

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
