cmake_minimum_required(VERSION 3.17)
project(SwarmRay)

# SETTING
set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

# search for program options
find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIR})

# Target
add_executable(SwarmRay src/main.cpp src/app/App.cpp src/app/App.h src/utils/CmdParser.cpp src/utils/CmdParser.h)

# link Boost libraries to the new target
target_link_libraries(SwarmRay ${Boost_LIBRARIES})

