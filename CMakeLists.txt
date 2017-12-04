cmake_minimum_required(VERSION 3.8)
project(220FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Ingredient.cpp IngredientInventory.cpp)
add_executable(220FinalProject ${SOURCE_FILES})