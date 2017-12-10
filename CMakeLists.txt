cmake_minimum_required(VERSION 3.8)
project(220FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
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