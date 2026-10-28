#pragma once
#include "nlohmann/json.hpp"

namespace core{

    using json = nlohmann::json;

    template<typename T>
    bool readJson(const char* path, T&);

    template<typename T>
    bool writeJson(const char* path, const T&);

    const json& getJson(const char* path);
}