cmake_minimum_required(VERSION 3.8)

project (HelloWorld)

find_package(hello REQUIRED)

add_executable(hello
	main.cpp
	)

target_compile_features(hello PUBLIC cxx_std_11)

target_link_libraries(hello PUBLIC example::hello-lib)

target_include_directories(hello PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)
