cmake_minimum_required(VERSION 3.8)

project (HelloWorld)

add_executable(hello
	main.cpp
	ClassA.cpp
	)

target_compile_features(hello PUBLIC cxx_std_11)

target_include_directories(hello PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)
	

