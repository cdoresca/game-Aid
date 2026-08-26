#include"resourceManager.h"

template<typename T>
resourceManager<T>::resourceManager(){}
        
template<typename T>
resourceManager<T>::~resourceManager(){
    cleanup();
}

template<typename T>
T* resourceManager<T>::load(std::string path){
    auto it = m_cache.find(path);
    if (it != m_cache.end()) {
        return it->second;
    }
    auto resource = new T(path);
    m_cache.emplace(path, resource);
    return resource;
}


template<typename T>
void resourceManager<T>::cleanup(){
    for(auto& pair: m_cache){
        delete pair.second;
    }
}

