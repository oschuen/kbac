cmake_minimum_required(VERSION 3.8)

project (hello-lib)

add_library(hello-lib STATIC 
	ClassA.cpp
	)

target_include_directories(hello-lib PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include/hello-lib>
	)

install(TARGETS hello-lib EXPORT helloTargets 
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
	)

install (DIRECTORY include/ DESTINATION include/hello-lib FILES_MATCHING PATTERN "*.h")
install (DIRECTORY include/ DESTINATION include/hello-lib FILES_MATCHING PATTERN "*.hpp") 

install (EXPORT helloTargets 
    FILE helloTargets.cmake
    NAMESPACE example::
    DESTINATION lib/cmake/hello
    )

install (FILES "helloConfig.cmake"
	DESTINATION lib/cmake/hello
	)

add_library(example::hello-lib ALIAS hello-lib)