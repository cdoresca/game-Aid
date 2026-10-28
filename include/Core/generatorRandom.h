#pragma once
#include <cstdint>

namespace core{

    void seedRandom(int32_t seed);
    double random_double();
    double random_double(double min, double max);
}