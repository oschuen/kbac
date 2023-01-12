cmake_minimum_required(VERSION 3.22)

project (GTest_Usage)

set (CMAKE_BUILD_TYPE "Debug")

enable_testing()

add_subdirectory(ext/googletest)
add_subdirectory(my_library)


