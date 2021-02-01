cmake_minimum_required(VERSION 3.17)
project(SwarmRay-jsonserver)
set(CMAKE_CXX_STANDARD 11)

set(ENV{PKG_CONFIG_PATH} /usr/lib/pkgconfig)
find_package(PkgConfig)
pkg_search_module(Pistache REQUIRED pistache)

message(STATUS "=== LIBRARIES: ${Pistache_LIBRARIES}")
message(STATUS "=== INCLUDE_DIRS: ${Pistache_INCLUDE_DIRS}")