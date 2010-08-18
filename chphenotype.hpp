#ifndef _CHPHENOTYPE_
#define _CHPHENOTYPE_

#include <cstdlib>

class chphenotype {
public:
    static char random(); //generate a random character between 'a' and 'z'
};

inline char chphenotype::random() {
    return rand()%('z'-'a'+1) + 'a';
}

#endif
