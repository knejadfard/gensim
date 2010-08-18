#ifndef _CHPHENOTYPE_
#define _CHPHENOTYPE_

#include <cstdlib>

class chphenotype {
public:
    char random(); //generate a random character between 'a' and 'z'
};

static inline char chphenotype::random() {
    return rand()%('z'-'a'+1) + 'a';
}

#endif
