#include <iostream>
#include <exception>
#include <algorithm>

#include "member.hpp"
#include "population.hpp"

using namespace std;

int main() {
    try {
        population p(5);
        p.print();
        cout<<"--- After Crossingover ---"<<endl;
        /*p.evolve(20);
        p.print();*/
        // TEST
        member m1("12345");
        cout<<"<"<<m1.get_phenotype()<<"> to <";
        string::iterator it1, it2;
        m1.random_range(it1, it2);
        string tmp = m1.get_phenotype();
        //iter_swap(it1, it2);
        swap_ranges(it1, it2, tmp.begin());
        cout<<tmp<<">"<<endl;
        //
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
