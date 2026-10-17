#include "poolAllocator.h"

namespace core {

PoolAllocator::PoolAllocator(std::size_t blockSize, std::size_t numBlock): m_blockSize(blockSize),m_capacity(numBlock),m_pool(nullptr),m_freeList(nullptr)
{
    if(m_blockSize < sizeof(void*)) 
        m_blockSize = sizeof(void*); 
    m_pool = static_cast<char*>(::operator new(m_blockSize * m_capacity));
    buildFreeList();
}

PoolAllocator::~PoolAllocator(){
    ::operator delete (m_pool);
}


void* PoolAllocator::allocator() noexcept{
    if(!m_freeList) return nullptr;
    void* block = m_freeList;
    m_freeList = *static_cast<void**>(m_freeList);
    return block;
}

void PoolAllocator::deallocate(void * block) noexcept{
    *static_cast<void **>(block) = m_freeList;
    m_freeList = block;
}

void PoolAllocator::buildFreeList() noexcept{
    m_freeList = m_pool;
    char* current = m_pool;
    for(std::size_t i = 0; i < m_capacity - 1; i++){
        char* next = current + m_blockSize;
        *reinterpret_cast<void **>(current) = next;
        current = next;
    }
    *reinterpret_cast<void**>(current) = nullptr;
}

}