#include "gtest/gtest.h"
#include "file.h"

namespace Test {

class FileTest : public ::testing::Test {
protected:
    const char* path = "HelloWord.txt";
    const std::string expected = "Hello World!\n Wow!!";

    void SetUp() override {
        core::file f(path, core::FileMode::WRITE | core::FileMode::BINARY);
        ASSERT_TRUE(f.isOpen());
        ASSERT_EQ(f.write(expected.data(), expected.size()), expected.size());
    }   // f est détruit ici : le fichier est fermé et vidé

    void TearDown() override { std::remove(path); }
};

TEST_F(FileTest, read) {
    core::file f(path, core::FileMode::READ | core::FileMode::BINARY);
    ASSERT_TRUE(f.isOpen());

    char buf[64] = {};
    std::size_t n = f.read(buf, sizeof(buf));

    EXPECT_EQ(n, expected.size());
    EXPECT_EQ(std::string(buf, n), expected);
}

TEST_F(FileTest, readAll) {
    core::file f(path, core::FileMode::READ | core::FileMode::BINARY);
    ASSERT_TRUE(f.isOpen());

    std::vector<char> data = f.readAll();
    EXPECT_EQ(std::string(data.begin(), data.end()), expected);
}

} // namespace Test