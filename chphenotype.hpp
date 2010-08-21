#ifndef _CHPHENOTYPE_
#define _CHPHENOTYPE_

//#include <cstdlib>
#include "ranum.hpp"

class chphenotype {
public:
    static char random(); //generate a random character between 'a' and 'z'
};

inline char chphenotype::random() {
    adl::ranum &t = adl::ranum::get();
    return t.generate('a', 'z');
}

#endif
