cmake_minimum_required(VERSION 3.17)
project(SwarmRay-jsonserver)
set(CMAKE_CXX_STANDARD 14)

set(ENV{PKG_CONFIG_PATH} /usr/lib/pkgconfig)
find_package(PkgConfig)
pkg_search_module(Pistache REQUIRED libpistache)

add_executable(SwarmRay-jsonserver main.cpp)
target_link_libraries(SwarmRay-jsonserver ${Pistache_LIBRARIES})

