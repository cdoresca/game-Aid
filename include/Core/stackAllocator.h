#pragma once 
#include <cstddef>
#include <stack>

namespace core{

    class stackAllocator{
        public :
            explicit stackAllocator(std::size_t size);
            ~stackAllocator();

            stackAllocator(const stackAllocator&) = delete;
            stackAllocator& operator=(const stackAllocator&) = delete;

            void* allocate(std::size_t size) noexcept;
            void deallocate() noexcept;
        
        private:

            std::size_t capacity;
            std::size_t offset;

            char* memory;

            std::stack<std::size_t> headers;

    };
}