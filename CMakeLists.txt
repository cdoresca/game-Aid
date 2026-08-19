cmake_minimum_required(VERSION 3.28)
project(Game-Aid LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# ============================================================================
# Libraries
# ============================================================================


include(FetchContent)

# ============================================================================
# SFML
# ============================================================================
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# ============================================================================
# GLM
# ============================================================================
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        0.9.9.8 # Specify desired version
)
FetchContent_MakeAvailable(glm)

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
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics glm::glm)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})