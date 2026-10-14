#pragma once
#include <cstddef>
#include <memory>

namespace core{
//why char[]
class doubleBuffer{

    public:
        explicit doubleBuffer(std::size_t size);
        ~doubleBuffer() = default;

        void* write() noexcept;

        const void* read() const noexcept;

        void swap() noexcept;

        std::size_t size() const noexcept;
    
    private:
        std::unique_ptr<char[]> buffer[2];
        std::size_t size_;
        int current;
};

}