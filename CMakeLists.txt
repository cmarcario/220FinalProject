cmake_minimum_required(VERSION 3.8)
project(220FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES CMakeLists.txt Ingredient.cpp IngredientInventory.cpp PotionCatalogue.cpp PotionShopModel.cpp PotionShopModelTest.cpp Potion.cpp)

add_executable(220FinalProject ${SOURCE_FILES})