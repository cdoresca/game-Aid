
include(FetchContent)
FetchContent_Declare(json 
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)
file(GLOB FILES CONFIGURE_DEPENDS 
    *.cpp 
)

add_library(Core ${FILES})

add_library(${PROJECT_NAME}::Core ALIAS Core)

target_include_directories(Core
    PUBLIC  ${INCLUDE_DIR}/Core
    PRIVATE ${SOURCE_DIR}/Core
)

target_link_libraries(Core PUBLIC nlohmann_json::nlohmann_json)

target_compile_features(Core PUBLIC cxx_std_17)