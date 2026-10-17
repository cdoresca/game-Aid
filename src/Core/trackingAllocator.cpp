#include "trackingAllocator.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace core{

    trackAllocator::~trackAllocator(){
        for(const auto& [ptr, size] : allocate){
            cout << "Leak detected: "<< size << "bytes"<< endl;
        }
    }

    void* trackAllocator::allocator(size_t size){
        void* ptr = malloc(size);
        if(!ptr) throw bad_alloc();

        lock_guard lg{lock};
        allocate[ptr] = size;
        return ptr;
    }

    void trackAllocator::deallocator(void* ptr)noexcept{
        if(!ptr) return;

        lock_guard lg{lock};
        allocate.erase(ptr);
        free(ptr);
    }
}