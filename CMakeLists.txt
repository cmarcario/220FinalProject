cmake_minimum_required(VERSION 3.8)
project(220FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/220FinalProject.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        cmake-build-debug/220FinalProject
        cmake-build-debug/220FinalProject.cbp
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/lib220FinalProject.a
        cmake-build-debug/Makefile
        cmake-build-debug/test.txt
        ArrayLib.cpp
        ArrayLib.h
        ArrayList.h
        ArrayList.inl
        CMakeLists.txt
        Ingredient.cpp
        Ingredient.h
        IngredientInventory.cpp
        IngredientInventory.h
        List.h
        ListStringMap.h
        ListStringMap.inl
        main.cpp
        PotionCatalogue.h
        StringMap.h)

add_executable(220FinalProject ${SOURCE_FILES})