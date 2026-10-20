#include "objectPool.h"
#include <stdexcept>

namespace core{

    template <typename T>
    objectPool<T>::objectPool(std::size_t size){
        if(size == 0 ) throw std::invalid_argument("size must be > 0");
        for(std::size_t i = 0; i < size; i++)
            pool.emplace_back(make_unique<T>());
    }

    template <typename T>
    std::unique_ptr<T, typename objectPool<T>::Deleter> objectPool<T>::acquire(){
        std::lock_guard lock(mtx);
        if(pool.empty()) return nullptr;

        std::unique_ptr<T, Deleter> ptr(pool.back().release(),Deleter{this});
        pool.pop_back();
        return ptr;
    }
    template <typename T>
    void objectPool<T>::Deleter::operator()(T* ptr){
        if(obj) obj->release(ptr);
    }

    template <typename T>
    void objectPool<T>::release(T* ptr){
        std::lock_guard lock(mtx);
        pool.emplace_back(ptr);
    }

}