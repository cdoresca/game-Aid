

include(FetchContent)

find_package(Vulkan REQUIRED)

find_package(glfw3 3.3 CONFIG QUIET)
if(NOT glfw3_FOUND)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
    )

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(glfw)
endif()

file(GLOB FILES CONFIGURE_DEPENDS 
    *.cpp 
)

add_library(Renderer ${FILES})

add_library(${PROJECT_NAME}::Renderer ALIAS Renderer)

target_include_directories(Renderer
    PUBLIC  ${INCLUDE_DIR}/Renderer
    PRIVATE ${SOURCE_DIR}/Renderer
)

target_link_libraries(Renderer PRIVATE glfw Vulkan::Vulkan)
target_compile_features(Renderer PUBLIC cxx_std_17)