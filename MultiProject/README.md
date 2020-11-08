# Multiple projects in one Aggregate

Splitting up software into multipr sub-projects is always a good idea. This allows 
you to easily reuse parts of it in other projects and forces you to think about interfaces 
between different parts of your software. Setting up a multi project with CMake is 
an easy thing, one understood how it works. Many articles on the internet show solutions 
for it. These are my 20ct for it:

## Aggregate CMakeLists.txt 

    set(hello_DIR ${CMAKE_CURRENT_LIST_DIR}/HelloLib)

The CMakeLists.txt in __HelloExe__ does a 

    find_package 

for the package __hello__. There are two ways how to tell CMake where to find the package. 
The first way is shown in [LibUsage](../LibUsage/README.md)(Set the CMAKE_PREFIX_PATH 
to the install location). The other way is to define a variable

    package_name_DIR

CMake will look in the specified folder and tries to find a 

    helloConfig.cmake

file there. 

Next 

    add_subdirectory(HelloLib)
    add_subdirectory(HelloExe)

the two sub-projects are included in their dependency order. This is important, because 
this way all targets from __HelloLib__ are already known to CMAKE when it reads the 
__HelloExe__ sub-project. Hence it doesn't matter when CMake reads the Config from 
__HelloLib__ which includes an empty __helloTargets.cmake__ file during the find_package 
.call in __HelloExe__ CMakeLists.txt
 
see [HelloLib](HelloLib/README.md)

---
This content is under the  CC BY-SA 4.0 Attribution-ShareAlike 4.0 International license 