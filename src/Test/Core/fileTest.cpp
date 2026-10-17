#include "Core/file.h"
#include <string>

#include "gtest/gtest.h"

namespace Test{

std::string buffer = "Hello World!\n Wow!!";
const size_t size = 20;

TEST(fileTest,write){
    core::file f("HelloWord.txt",core::FileMode::WRITE);
    
   ASSERT_EQ(f.write(buffer.c_str(),size), size);
}

TEST(fileTest,read){
    core::file f("HelloWord.txt");
    char buf[size];
    f.read(buf,size);
    ASSERT_STREQ(buf, buffer.c_str());
}

TEST(fileTest, readAll){
    core::file f("HelloWord.txt");
    
    ASSERT_STREQ(f.readAll().data(), buffer.c_str());
}
}