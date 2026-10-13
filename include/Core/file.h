#pragma once
#include <bits/stdc++.h>
#include <vector>

namespace core{

    enum class FileMode{
        READ = 1 << 0,
        WRITE = 1 << 1,
        BINARY = 1 << 2,
        AT_END = 1 << 3,
        APPEND =  1 << 4,
        TRUCATE = 1 << 5
    };

    constexpr FileMode operator|(FileMode a, FileMode b);
    constexpr bool hasFlag(FileMode a, FileMode b);

    class file
    {
        public:
            file() = default;
            ~file() = default;

            file(const char* path, FileMode mode = FileMode::READ | FileMode::BINARY);

            file(const file&) = delete;
            file& operator=(const file&) = delete;
            file(file&&) = default;
            file& operator=(file&&) = default;

            std::size_t read(char* buffer, size_t size);
            std::size_t write(char* buffer, size_t size);

            bool open(const char* path, FileMode mode);
            bool isOpen();

            void close();

            std::vector<char> readAll();

        private:

            std::fstream m_file;
        
    };


}