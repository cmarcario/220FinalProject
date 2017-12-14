//
// Created by Benjamin on 11/30/17.
//

#ifndef INC_220FINALPROJECT_INVENTORY_H
#define INC_220FINALPROJECT_INVENTORY_H

#include <string>
#include "List.h"
#include "Ingredient.h"
#include "StringMap.h"

class IngredientInventory{
private:

    StringMap<Ingredient*>* inventory;

public:

    IngredientInventory();



    ~IngredientInventory();



    IngredientInventory(const IngredientInventory& inventoryToCopy);



    IngredientInventory& operator=(const IngredientInventory& inventoryToCopy);



    void addIngredient(Ingredient* ingredientToAdd);



    void addIngredient(std::string name, int have=0, int want=0);



    void removeIngredient(std::string name);



    void addVolumeOf(std::string name, int amt);



    void subtractVolumeOf(std::string name, int amt);



    void setHaveValueOf(std::string name, int amt);



    void setWantValueOf(std::string name, int amt);


    int getHaveValueOf(std::string name);


    int getWantValueOf(std::string name);


    List<Ingredient*>* listInventory();



    Ingredient* getIngredient(std::string name);



    std::string toString();
};

#endif //INC_220FINALPROJECT_INVENTORY_H
