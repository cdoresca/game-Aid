#pragma once 
#include <cstdlib>
#include <memory>
#include <mutex>
#include <vector> 

namespace core{

    template<typename T>
    class objectPool{

        private:

            struct Deleter{
                objectPool* obj;
                void operator()(T*);
            };

            void release(T* ptr);

            std::mutex mtx;
            std::vector<std::unique_ptr<T>> pool;
        public:
            explicit objectPool(std::size_t size);
            ~objectPool() = default;

            std::unique_ptr<T,Deleter> acquire();
    };
}