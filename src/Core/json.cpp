#include "json.h"
#include "file.h"
#include <string>

namespace core{
  
    template<typename T>
    bool writeJson(const char* path, const T& object){
        file f(path,FileMode::WRITE | FileMode::BINARY | FileMode::TRUCATE);
        if (!f.isOpen()) return false;

        json data = object;
        std::string text = data.dump();
        return f.write(text.c_str(), text.size()) == text.size();
    }

    template<typename T>
    bool readJson(const char* path, T& object){
        file f(path);
        if (!f.isOpen()) return false;

        std::vector<char> bytes = f.readAll();
        json data = json::parse(bytes.begin(),bytes.end());
        object = data.get<T>();
        return true;
    }
}