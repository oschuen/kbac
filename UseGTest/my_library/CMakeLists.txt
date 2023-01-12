cmake_minimum_required(VERSION 3.22)

project (my_library)

add_library(my_library STATIC
	src/my_fancy_library_class.cpp 
)

target_include_directories(my_library PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
) 

add_library(examples::my_library ALIAS my_library)

add_subdirectory(test)
