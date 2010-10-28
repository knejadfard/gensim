#ifndef _RANUM_
#define _RANUM_

#include <cstdlib>
#include <ctime>

class ranum {
    ranum() {
        srand(time(0));    //private constructor, only used inside ::get()
    }
    ranum(const ranum& rhs){} //disable copy constructor
    ranum& operator=(const ranum& rhs){} //disable assignment
public:
    static ranum& object(); //get a reference to the static ranum object
    int generate(const int& min, const int& max); //return random number between min and max
};

#endif
