#include <iostream>
#include <exception>

#include "member.hpp"
#include "population.hpp"

using namespace std;

int main() {
    try {
        population p(member("genetics"), 10);
        p.print();
        p.evolve(100000);
        p.print();
        cout<<"Size: "<<p.size()<<endl;
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
