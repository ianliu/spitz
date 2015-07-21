cmake_minimum_required(VERSION 2.8)
project(spitz C CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(MPI REQUIRED)

find_package(PkgConfig)
pkg_check_modules(NANOMSG libnanomsg REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(spitz)
add_subdirectory(examples)
