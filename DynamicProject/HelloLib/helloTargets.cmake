
cmake_minimum_required(VERSION 3.8)

if (NOT DEFINED "${CMAKE_FIND_PACKAGE_NAME}_FOUND")
message (STATUS "READ Package Information for ${CMAKE_FIND_PACKAGE_NAME}")
add_subdirectory (${CMAKE_CURRENT_LIST_DIR} "${CMAKE_FIND_PACKAGE_NAME}_bin")
endif() 
