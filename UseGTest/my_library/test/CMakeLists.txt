cmake_minimum_required(VERSION 3.22)

project (my_library_test)
include(GoogleTest)

add_executable(my_library_test  
                src/my_fancy_library_class_test.cpp
)

target_link_libraries(my_library_test PUBLIC
                GTest::gtest_main
                examples::my_library
) 
                
gtest_discover_tests(my_library_test)