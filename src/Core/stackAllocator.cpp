#include "stackAllocator.h"
#include <cstdlib>

using namespace std;

namespace core{

    stackAllocator::stackAllocator(size_t size):capacity(size),offset(0){}

    stackAllocator::~stackAllocator(){ free(memory);}

    void* stackAllocator::allocate(size_t size) noexcept{

        if(size == 0 || size > capacity - offset) return nullptr;

        void* ptr = memory + offset;
        offset += size;
        headers.push(size);
        return ptr;
    }

    void stackAllocator::deallocate() noexcept{

        if(headers.empty()) return;

        size_t size = headers.top();
        headers.pop();

        offset -= size;
    }
}