# Using a library

The [HelloWorld example](../HelloWorld/README.md) shall use the library from [HelloLib](../HelloLib/README.md) 
now.

With

    find_package(hello REQUIRED)

all Targets from the package _hello_ are known within this project.

    target_link_libraries(hello PUBLIC example::hello-lib)

links the hello-lib library to this executable. All Include folders from the library are automatically 
added to the search path of the executable target.

That's it. 

## Build the example

    ~/kbac/LibUsage $ mkdir build
    ~/kbac/LibUsage $ cd build
    ~/kbac/LibUsage/build $ cmake -DCMAKE_PREFIX_PATH=../../local/lib/cmake ..
    ~/kbac/LibUsage/build $ make

The environment variable CMAKE_PREFIX_PATH tells CMake where to search for \*Config.cmake 
files. 
 