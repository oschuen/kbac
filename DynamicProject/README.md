# Dynamic Package exploration

Ordering the sub-projects in their dependency order like in [MuliProject](../MultiProject/README.md) 
isn't always an easy thing. Can't CMake do this for us? It can.

In this projects CMakeLists.txt only the Dir-Variable for the library is set and the 
__add\_subdirectory__ for the top-most project of the dependency tree.

    set(hello_DIR ${CMAKE_CURRENT_LIST_DIR}/HelloLib)

    add_subdirectory(HelloExe)  

But when is CMake including the __CMakeLists.txt__ in  __HelloLib__?

The solution is hidden in the __*Targets.cmake__ file in the __HelloLib__ folder.
in [MuliProject](../MultiProject/README.md) this was an empty file. 

In this solution it includes the __CMakeLists.txt__ in the __CMAKE\_CURRENT\_LIST\_DIR__ (The folder 
containing the __helloTargets.cmake__) when the package wasn't found/included yet.


    if (NOT DEFINED "${CMAKE_FIND_PACKAGE_NAME}_FOUND")
        message (STATUS "READ Package Information for ${CMAKE_FIND_PACKAGE_NAME}")
        add_subdirectory (${CMAKE_CURRENT_LIST_DIR} "${CMAKE_FIND_PACKAGE_NAME}_bin")
    endif()

${CMAKE_FIND_PACKAGE_NAME}_FOUND doesn't need to be set. It is automatically done by 
CMake once it read this file.  
---

This content is under the  CC BY-SA 4.0 Attribution-ShareAlike 4.0 International license 