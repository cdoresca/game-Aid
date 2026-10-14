#pragma once 
#include <cstddef>
#include <unordered_map>
#include <mutex>

namespace core
{
    class trackAllocator{

        public:

            trackAllocator() = default;
            ~trackAllocator();

            void* allocator(std::size_t size);
            void deallocator(void* ptr) noexcept;
        
            private:
            std::unordered_map<void*,std::size_t> allocate;
            std::mutex lock; 

    };

} 
