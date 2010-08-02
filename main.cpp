#include <iostream>
#include <exception>

#include "member.hpp"
#include "population.hpp"

using namespace std;

int main() {
    try {
        population p(member("hello world"), 5);
        p.print();
        p.evolve(2000);
        p.print();
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
