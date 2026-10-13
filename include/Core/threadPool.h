#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <atomic>
#include <future>

namespace core{

class threadPool{
     
    public: 

        explicit threadPool( std::size_t threads = std::thread::hardware_concurrency() - 1);
        ~threadPool();

        template<typename F,typename... Args>
        auto enqueue(F&& f, Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>;

    private:
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::mutex taskMutex;
        std::condition_variable taskCV;
        std::atomic<bool> stop;
};

}
