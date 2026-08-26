#pragma once 
#include <string>

template <typename T>
class resourceManager{

    std::unordered_map<std::string, T*> m_cache;
    public:
        resourceManager();
        ~resourceManager();
        T* load(std::string path);
        void cleanup();
};