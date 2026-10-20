#include "gtest/gtest.h"
#include "Core/allocator.h"

namespace Test {

TEST(allocatorTest, allocateZero){
    core::Allocator allocate(16);

    char * ptr = static_cast<char *>(allocate.allocate(0));

    EXPECT_EQ(ptr,nullptr);
}

TEST(allocatorTest, allocateMoreThanMax){
    core::Allocator allocate(16);

    char * ptr = static_cast<char *>(allocate.allocate(64));

    EXPECT_EQ(ptr,nullptr);
}

TEST(allocatorTest, allocateNormal){
    core::Allocator allocate(16);

    char * ptr = static_cast<char *>(allocate.allocate(8));

    ASSERT_NE(ptr,nullptr);
}

}