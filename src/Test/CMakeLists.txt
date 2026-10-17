

if(ENABLE_TESTS)
else()
return()
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE FILES CONFIGURE_DEPENDS 
    *.cpp 
)

add_library(Test ${FILES})

target_include_directories(Test
    PUBLIC  ${INCLUDE_DIR}
)
target_link_libraries(Test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(Test)
target_compile_features(Test PUBLIC cxx_std_17)
