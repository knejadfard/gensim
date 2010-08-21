#ifndef _RANUM_
#define _RANUM_

#include <cstdlib>

namespace adl {
//***
    class ranum {
        ranum() { srand(time(0)); } //private constructor, only used inside ::get()
        ranum(const ranum& rhs); //disable copy constructor
        void operator=(const ranum& rhs); //disable assignment
    public:
        static ranum& get(); //get a reference-handle
        int generate(const int& min, const int& max); //return random number between min and max
    };
//***
}

inline adl::ranum& adl::ranum::get() {
    static ranum sngl;
    return sngl;
}

inline int adl::ranum::generate(const int& min, const int& max) {
    return rand()%(max-min+1) + min;
}

#endif
