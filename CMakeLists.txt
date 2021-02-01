cmake_minimum_required(VERSION 3.17)
project(SwarmRay)

# SETTING
set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

# ================= search for BOOST =============
find_package(Boost REQUIRED COMPONENTS program_options filesystem)
include_directories(${Boost_INCLUDE_DIR})

# ================== search for Python ==============
find_package(PythonLibs REQUIRED)
if(PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIR})
else(PYTHONLIBS_FOUND)
    message(FATAL_ERROR ”Python libs not found”)
endif(PYTHONLIBS_FOUND)


# ****************** Compile Process *****************
# Target
add_library(inireader src/libs/inih/ini.cpp src/libs/inih/INIReader.cpp)
add_library(easylogging src/libs/easyloggingpp/easylogging++.cc)
add_executable(
        SwarmRay
        src/main.cpp src/app/App.cpp
        src/utils/CmdParser.cpp src/utils/PathGenerator.cpp src/core/Task/ExtFilter.cpp
        src/conf/ConfigReader.cpp src/conf/Config.cpp
        src/log/ezlog.cpp
        src/core/Command/Command.cpp src/core/Task/Task.cpp
        src/core/Task/TaskManger.cpp src/core/Scheduler/Scheduler.cpp src/core/ProcManager/ProcManager.cpp
        src/scanner/scanner-search/search_engine.cpp
        src/scanner/ScannerFactory.cpp src/scanner/CppScanner.cpp src/scanner/JavascriptScanner.cpp
        src/scanner/scanner-syntax/cpp_syntax_functions.cpp src/scanner/scanner-syntax/js_syntax_funtions.cpp
)

# ****************** Link Process *****************
# ================== 3rd libs contained in this proj ===============
target_link_libraries(SwarmRay inireader easylogging)
target_link_libraries(SwarmRay ${Boost_LIBRARIES})
target_link_libraries(SwarmRay ${PYTHON_LIBRARIES})


# Test Units
add_subdirectory(test/)
add_subdirectory(jsonserver/)