cmake_minimum_required(VERSION 3.17)
project(SwarmRay)

# SETTING
set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

# search for BOOST
find_package(Boost REQUIRED COMPONENTS program_options filesystem)
include_directories(${Boost_INCLUDE_DIR})

# Target
add_library(inireader src/libs/inih/ini.cpp src/libs/inih/INIReader.cpp)
add_library(easylogging src/libs/easyloggingpp/easylogging++.cc)
add_executable(
        SwarmRay
        src/main.cpp src/app/App.cpp
        src/utils/CmdParser.cpp src/utils/PathGenerator.cpp src/utils/ExtFilter.cpp src/utils/ExtFilter.h
        src/conf/ConfigReader.cpp src/conf/ConfigReader.h
        src/log/ezlog.cpp
        src/core/Command/Command.cpp src/core/Task/Task.cpp
        src/scanner/ScannerFactory.cpp
)


# link Boost libraries to the new target
target_link_libraries(SwarmRay ${Boost_LIBRARIES})
target_link_libraries(SwarmRay inireader easylogging)

# Test Units
add_subdirectory(test/)