#pragma once 
#include <cstdlib>

namespace core{

    class Allocator{
        public:
            explicit Allocator(std::size_t size);
            ~Allocator();

            Allocator(const Allocator&) = delete;
            Allocator& operator=(const Allocator&) = delete;
            Allocator(Allocator&&) = delete;
            Allocator& operator=(Allocator&&)= delete;

            void* allocate(std::size_t size) noexcept;
            void reset() noexcept;

        private:

            std::size_t m_size;
            std::size_t m_used;

            char* m_memory;
    };

}