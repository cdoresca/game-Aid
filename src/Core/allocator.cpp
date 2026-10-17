#include "allocator.h"

namespace core{

Allocator::Allocator(std::size_t size):m_size(size),m_used(0),m_memory(static_cast<char*>(malloc(size))){}

Allocator::~Allocator(){ free(m_memory);}

void* Allocator::allocate(std::size_t size) noexcept{
    if(size == 0 || size > m_size - m_used)
        return nullptr;
    void* ptr = m_memory + m_used;
    m_used += size;

    return ptr;
}

void Allocator::reset() noexcept{ m_used = 0; }

}