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
        p.evolve(20);
        p.print();
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
