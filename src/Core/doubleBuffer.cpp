#include "doubleBuffer.h"
#include <stdexcept>

using namespace std;

namespace core{

    doubleBuffer::doubleBuffer(size_t size):size_(size),current(0){
        if( size == 0) throw invalid_argument("size must be > 0");
        buffer[0] = make_unique<char[]>(size);
        buffer[1] = make_unique<char[]>(size);
    }

    void* doubleBuffer::write() noexcept{
        return buffer[current].get();
    }

    const void* doubleBuffer::read() const noexcept{
        return buffer[1 - current].get();
    }

    void doubleBuffer::swap() noexcept{ current = 1 - current; }

    size_t doubleBuffer::size() const noexcept{
        return size_;
    }

}