#include "generatorRandom.h"
#include <random>

namespace core
{

    
    std::mt19937& engine(){
        thread_local std::mt19937 gen{std::random_device{}()};
        return gen;
    }

    void seedRandom(int32_t seed){ engine().seed(seed); }

    double random_double(){
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(engine());
    }
    double random_double(double min, double max){
        std::uniform_real_distribution<double> dist(min, max);
        return dist(engine());
    }
    /*int random_int(int min, int max){
        std::uniform_real_distribution<int> dist(min, max);
        return dist(engine());
    }*/

} // namespace core
