cmake_minimum_required(VERSION 3.5)
project(Game-Aid LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# ============================================================================
# Libraries
# ============================================================================


include(FetchContent)
# ============================================================================
# GLFW
# ============================================================================

include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

message(STATUS "GLFW source dir: ${glfw_SOURCE_DIR}")
message(STATUS "GLFW binary dir: ${glfw_BINARY_DIR}")
message(STATUS "GLFW done")

# ============================================================================
# VULKAN
# ============================================================================
find_package(Vulkan REQUIRED)
message(STATUS "Vulkan done")

# ============================================================================
# GLM
# ============================================================================
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.3 # Specify desired version
)
FetchContent_MakeAvailable(glm)
message(STATUS "GLM done")

# ============================================================================
# STB
# ============================================================================
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG master
)
FetchContent_MakeAvailable(stb)
message(STATUS "STB done")


# ============================================================================
# TINYOBJLOADER
# ============================================================================
FetchContent_Declare(
  tinyobjloader
  GIT_REPOSITORY https://github.com/tinyobjloader/tinyobjloader.git
  GIT_TAG release
)

FetchContent_MakeAvailable(tinyobjloader)
message(STATUS "tinyobjloader done")

# ============================================================================
# TINYGTFL
# ============================================================================
FetchContent_Declare(
  tinygltf
  GIT_REPOSITORY https://github.com/syoyo/tinygltf.git
  GIT_TAG release
)
FetchContent_MakeAvailable(tinygltf)
message(STATUS "tinygltf done")

# ============================================================================
# Source Files
# ============================================================================

file(GLOB_RECURSE SOURCE_FILES
    ${SOURCE_DIR}/*.cpp 
    ${SOURCE_DIR}/*.h
)

foreach(SRC IN ITEMS ${SOURCE_FILES})
    get_filename_component(SRC_PATH "${SRC}" PATH)
    file(RELATIVE_PATH SRC_PATH_REL "${SOURCE_DIR}" "${SRC_PATH}")
    string(REPLACE "/" "\\" GROUP_PATH "/${SRC_PATH_REL}")
    source_group("Sources${GROUP_PATH}" FILES "${SRC}")
endforeach()
message("Getting all sources... DONE")

# ============================================================================
# Executable
# ============================================================================


add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME}  PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR} ${stb_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw Vulkan::Vulkan glm::glm tinyobjloader tinygltf)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})