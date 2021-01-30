project(test)
add_subdirectory(googletest_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)

#boost
set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking
# search for BOOST
find_package(Boost REQUIRED COMPONENTS program_options filesystem)
include_directories(${Boost_INCLUDE_DIR})

add_executable(
        Google_Tests_run
        CompileTest.cpp
        utils_tests/ExtFilter_Test.cpp ../src/utils/ExtFilter.cpp
        utils_tests/PathGenerator_Test.cpp ../src/utils/PathGenerator.cpp ../src/core/Command/Command.cpp ../src/core/Command/Command.h)

target_link_libraries(Google_Tests_run ${Boost_LIBRARIES})
target_link_libraries(Google_Tests_run gtest gtest_main)