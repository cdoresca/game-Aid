#pragma once 
#include <cstdlib>

namespace core{

    class PoolAllocator{

        public:
            PoolAllocator(std::size_t blockSize, std::size_t numBlock);
            ~PoolAllocator();

            PoolAllocator(const PoolAllocator&) = delete;
            PoolAllocator& operator=(const PoolAllocator&) = delete;

            void* allocator() noexcept;
            void deallocate(void* block) noexcept;

        private:

            std::size_t m_blockSize;
            std::size_t m_capacity;
            
            char* m_pool;
            void* m_freeList;

            void buildFreeList() noexcept;

    };

}