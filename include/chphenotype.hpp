#ifndef _CHPHENOTYPE_
#define _CHPHENOTYPE_

#include "ranum.hpp"

class chphenotype {
public:
    static char random(); //generate a random character between 'a' and 'z'
};

inline char chphenotype::random() {
    return ranum::object().generate('a', 'z');
}

#endif
