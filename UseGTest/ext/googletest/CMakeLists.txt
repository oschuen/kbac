cmake_minimum_required(VERSION 3.14)
project(Test_Infrastructure)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

option (BUILD_GMOCK "Build shared libraries" ON)
set(BUILD_GMOCK ON)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)
