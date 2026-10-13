cmake_minimum_required(VERSION 3.5)

project(GameAid 
  VERSION 1.0
  HOMEPAGE_URL https://github.com/cdoresca/game-Aid 
  LANGUAGES CXX
)

# ====================================
# Global build settings
#=====================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

#======================================
# Output layout
#======================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#======================================
# Path directory
#=======================================
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

#=======================================
# Compiler flags
#=======================================
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#=======================================
# Option
#=======================================
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(ENABLE_TESTS "Build unit tests" ON) #futur

#=======================================
# Sub-projet
#=======================================
add_subdirectory(${SOURCE_DIR}/Core)
#=======================================
# Main executable
#=======================================

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Core
)

#=======================================
# Install rules directory
#=======================================
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)