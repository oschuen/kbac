# Starting with CMake

Guess you just want to create a simple self contained executable with CMake its not much you have to do.

In this example we have

* main.cpp
* ClassA.cpp
    * include/ClassA.h
 
now lets have a look to the CMakeLists.

    cmake_minimum_required(VERSION 3.8)

tells CMake which version your CMake shall have at least. With every new version of CMake new features are introduced. When you need a feature of
CMake that was introduced in a specific version you have to add this version here. This way CMake will fail early and not first at the
moment in time when it find this feature in one of the CMakeLists. 

    project (HelloWorld)
    
Give your project a name. You can use this name all over in your CMakeLists with the variable ${PROJECT_NAME}. This might be easier
than to exchange the name whenever you copy a CMakeLists to a new location to start a new project.

    add_executable(hello
        main.cpp
        ClassA.cpp
    ) 

This tells CMake that you want to define an executable called "hello". "hello" will be the final name of this executable after compiling and linking the project. After the executable name (CMake also speaks about a target) all compilation units belonging to it are listed. 

    target_compile_features(hello PUBLIC cxx_std_11)
    
Sets a compile feature to the target, in this case the C++ compatibility level to C++11.

    target_include_directories(hello PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

Finally the target include directories are set. The variable ${CMAKE_CURRENT_SOURCE_DIR} specifies the directory given to CMake as starting directory. This could be replaced by {CMAKE_CURRENT_LIST_DIR} which specifies the location of the current "CMakeLists.txt".

## Build the example

Open a shell in this folder:

    ~/kbac/HelloWorld $ mkdir build
    ~/kbac/HelloWorld $ cd build
    ~/kbac/HelloWorld/build $ cmake ..
    ~/kbac/HelloWorld/build $ make
    
once performed these four step the executable can be started

    ~/kbac/HelloWorld/build & ./hello
    Hello World
    ~/kbac/HelloWorld/build & _

## Extending the CMakeLists

Adding new Compilation Units to the executable target doesn't require to run CMake again. If for example a new file is added to the project 

    add_executable(hello
        main.cpp
        ClassA.cpp
        new_file.cpp
    ) 

this will be noticed during the make step and CMake will be called automatically.

## Configure an IDE

CMake has build in support for various IDEs. Configuring a project for example for eclipse is an easy thing:

    ~/kbac $ mkdir -p eclipse/HelloWorld
    ~/kbac $ cd eclipse/HelloWorld
    ~/kbac/eclipse/HelloWorld $ cmake -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=4.15 ../../HelloWorld
    
After which open Eclipse, right click on hte Project Explorer and choose Import/General/Existing Projects into Workspace. Then navigate to "~/kbac/eclipse/HelloWorld". and select "OK".

**Note: its recomended to create the Eclipse Project in a sibbling folder of your project, not in a subfolder, parent folder or even the same folder. Eclipse will cause a lot of issues in that case.** 

---
This content is under the  CC BY-SA 4.0 Attribution-ShareAlike 4.0 International license 