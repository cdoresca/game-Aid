include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE FILES CONFIGURE_DEPENDS *.cpp)

add_executable(Test ${FILES})

target_include_directories(Test PRIVATE ${INCLUDE_DIR})
target_link_libraries(Test PRIVATE Core GTest::gtest_main)
target_compile_features(Test PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(Test)