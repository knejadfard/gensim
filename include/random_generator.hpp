#ifndef _RANUM_
#define _RANUM_

#include <random>

class random_generator {

    random_generator(const random_generator& rhs)=delete;
    random_generator& operator=(const random_generator& rhs)=delete;

public:

    random_generator() {}

    int generate(const int& min, const int& max) {
        std::random_device _rd{};
        std::mt19937_64 _generator{_rd()};
        std::uniform_int_distribution<> dist{min, max};
        return dist(_generator);
    }

};

#endif
