#include "gtest/gtest.h"
#include "generatorRandom.h"

namespace Test{

TEST(Random, SameSeedSameSequence) {
    core::seedRandom(42);
    double a = core::random_double();
    core::seedRandom(42);
    EXPECT_EQ(a, core::random_double());
}

TEST(Random, StaysInRange) {
    for (int i = 0; i < 1000; ++i) {
        double d = core::random_double(-2.0, 3.0);
        EXPECT_GE(d, -2.0);
        EXPECT_LT(d, 3.0);
    }
}

}