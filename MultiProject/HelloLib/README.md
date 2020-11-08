# Include Lib from source

If this library shall be either used from source or from install location, it has to be
possible to make a 

    find_package(hello)

for it. This requires a 

    helloConfig.cmake

as well as a 

    helloTargets.cmake

file which is included by the first. In source location, there is not really a need 
for the __Targets__ file, becaus all information about the project are coming from 
the __CMakeLists.txt__ already. 

But _helloConfig.cmake__ is including it, this is its purpose at the install location. 
But it only needs to be there, so that CMake finds it. It needs no content. 

On install location a "helloTargets.cmake" is automatically created. (see [HelloLib](../../HelloLib/README.md)) 

---
This content is under the  CC BY-SA 4.0 Attribution-ShareAlike 4.0 International license
