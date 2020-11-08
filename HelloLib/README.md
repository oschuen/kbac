# Install a library

Now lets say, we think that our ClassA saying "Hello World" is that awesome that everybody 
should use it. The common way is than to put it in a library than and make it available 
via CMake. 

## CMakeLists.txt

First of all the library must be declared:

    add_library(hello-lib STATIC 
        ClassA.cpp
    )

This statement defines a static library "hello-lib" with one Compilation unit "ClassA.cpp". 
Next it is necessary to tell CMake where to find the library headers

    target_include_directories(hello-lib PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/hello-lib>
    )

The target_include_directories has two locations defined
<style>
th, td {
padding: 5px
}
</style>
<table>
<tr><td>BUILD_INTERFACE</td><td>defines the location of the headers in the source location</td></tr>
<tr><td>INSTALL_INTERFACE</td><td>defines the location of the headers when library is installed</td></tr>
</table>

    install(TARGETS hello-lib EXPORT helloTargets 
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )

Configures how CMake shall install the library/target. This configuration is required 
for the \'*target.cmake file, which is created at the install location in the lib/cmake 
folder.

One word to packages and targets.

<table>
<tr><td>hello-lib</td><td>is a target. Other targets can be executables, pure header libraries or shared libraries</td></tr>
<tr><td>hello</td><td>The prefix in helloTargets is a package. A package can contain multiple targets. Per package one Config and one Targets files is necessary.</td></tr>
</table>
 

    install (DIRECTORY include DESTINATION include/hello-lib FILES_MATCHING PATTERN "*.h")
    install (DIRECTORY include DESTINATION include/hello-lib FILES_MATCHING PATTERN "*.hpp")

installs all header to the install-location. The folder must be the same as in target_include_directories.

    install (EXPORT helloTargets 
        FILE helloTargets.cmake
        NAMESPACE example::
        DESTINATION lib/cmake/hello
    )

installs the Targets file for this package to the install-location.

    install (FILES "helloConfig.cmake"
        DESTINATION lib/cmake/hello
    )

installs the Config file to the install location.

## Config.txt

    include (CMakeFindDependencyMacro)

includes CMake-Macros, that supports CMage to resolve dependencies for this project

    include("${CMAKE_CURRENT_LIST_DIR}/helloTargets.cmake")

Includes the generated Targets file, containing all configuration about the package 
at the install-location.

## Build the example

Open a shell in this folder:

    ~/kbac/HelloLib $ mkdir build
    ~/kbac/HelloLib $ cd build
    ~/kbac/HelloLib/build $ cmake -DCMAKE_INSTALL_PREFIX=../../local ..
    ~/kbac/HelloLib/build $ make install

this installs the library to the "local" folder within the root folder of the knowledge 
base:

    ~/kbac/local$ tree
    .
    ├── include
    │   └── hello-lib
    │       └── include
    │           └── ClassA.h
    └── lib
        ├── cmake
        │   └── hello
        │       ├── helloConfig.cmake
        │       ├── helloTargets-noconfig.cmake
        │       └── helloTargets.cmake
        └── libhello-lib.a


This content is under the  CC BY-SA 4.0 Attribution-ShareAlike 4.0 International license 