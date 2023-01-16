# Using GTest within a CMake project.

Integrating GTest into a CMake project is demonstrated within this project. It is configured in the way that GTest is not cloned within this project but downloaded during the build step from [github.com](https://github.com/google/googletest).

## GTest CMakeLists.txt 

The [CMakeLists.txt](https://github.com/oschuen/kbac/blob/master/UseGTest/ext/googletest/CMakeLists.txt) within the [ext/googletest](https://github.com/oschuen/kbac/tree/master/UseGTest/ext/googletest) folder downloads the GTest, builds it and automatically makes all targets from the project available to be used in other projects.


## The library for test

The folder [my_library](https://github.com/oschuen/kbac/tree/master/UseGTest/my_library) contains a small library that shall be tested using GTest. The tests are organized in a separate folder [test](https://github.com/oschuen/kbac/tree/master/UseGTest/my_library/test) parallel to the sources of the library.

The tests are part of a [test executable](https://github.com/oschuen/kbac/blob/master/UseGTest/my_library/test/CMakeLists.txt#L6) which is configured in the
[CMakeLists.txt](https://github.com/oschuen/kbac/blob/master/UseGTest/my_library/test/CMakeLists.txt) of the test project. 

	add_executable(my_library_test  
	                src/my_fancy_library_class_test.cpp
	)

The test executable links against the 

	target_link_libraries(my_library_test PUBLIC
                GTest::gtest_main
                examples::my_library
	) 

__gtest_main__ target which contains already the standard main function for unit tests with all GTest comand line arguments and it links againes the library under test.

Finally it configures all tests that are contained within executable for later test executions:

	gtest_discover_tests(my_library_test)
	
## Configure CMake to support tests

Finally CMake must know that the project contains tests at all. This is done in the main [CMakeLists.txt](	https://github.com/oschuen/kbac/blob/master/UseGTest/CMakeLists.txt#L7)

	enable_testing()
	
With this configuration there are two ways to do testing.

After building the example

	~/kbac/UseGTest $ mkdir build
	~/kbac/UseGTest $ cd build
	~/kbac/UseGTest/build $ cmake ..
	~/kbac/UseGTest/build $ make 
	
the test can be started with 

	~/kbac/UseGTest/build $ make test
	
or you can use ctest the test utility coming with cmake.

	~/kbac/UseGTest/build $ ctest
	
Using ctest you can also generate an XUnit report for any reporting tooling.

	~/kbac/UseGTest/build $ ctest --output-junit report.xml
