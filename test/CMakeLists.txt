project(test)
add_subdirectory(googletest_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)

add_executable(
        Google_Tests_run
        CompileTest.cpp
        utils_tests/ExtFilter_Test.cpp ../src/utils/ExtFilter.cpp
        utils_tests/PathGenerator_Test.cpp )

target_link_libraries(Google_Tests_run gtest gtest_main)