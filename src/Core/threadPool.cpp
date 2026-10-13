#include "threadPool.h"

using namespace std;

namespace core{

    threadPool::threadPool(size_t threads):stop(false){
        for(size_t i = 0; i < threads; i++){
            workers.emplace_back([this]{
                
                while(true){
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(taskMutex);
                        taskCV.wait(lock, [this] { return stop || !tasks.empty();});
                        if(stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    threadPool::~threadPool(){
        {
            unique_lock<mutex>(taskMutex);
            stop = true;
        }
        taskCV.notify_all();
        for(thread& worker : workers) worker.join();
    }

    template<typename F,typename... Args>
    auto threadPool::enqueue(F&& f, Args&&... args)
    -> future<typename result_of<F(Args...)>::type>{
        using return_type = typename result_of<F(Args...)>::type;
        auto task = make_shared<packaged_task<return_type()>>(
            bind(forward<F>(f), forward<Args>(args)...)
        );

        future<return_type> res = task->get_future();
        {
            unique_lock<mutex> lock(taskMutex);
            if(stop) throw runtime_error("enqueue on stopped threadPool");

            tasks.emplace([task] (){ (*task)();});
        }

        taskCV.notify_one();
        return res;
    }
}