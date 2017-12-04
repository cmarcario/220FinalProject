//
// Created by Benjamin on 12/3/17.
//

#include "IngredientInventory.h"
#include "ListStringMap.h"

IngredientInventory::IngredientInventory() {
    inventory = new ListStringMap<Ingredient*>();
}

IngredientInventory::~IngredientInventory() {
    delete inventory;
}

void IngredientInventory::addIngredient(Ingredient* ingredientToAdd){
    inventory->addItem(ingredientToAdd->getName(), ingredientToAdd);
}

void IngredientInventory::addIngredient(std::string name, int have, int want){
    Ingredient* newIngredient = new Ingredient(name);
    newIngredient->setWantValue(want);
    newIngredient->setHaveValue(have);

    inventory->addItem(name, newIngredient);
}

void IngredientInventory::removeIngredient(std::string name){
    Ingredient* ingredient = inventory->removeItem(name);
    delete ingredient;
}

void IngredientInventory::addVolumeOf(std::string name, int amt){
    inventory->getItem(name)->addVolume(amt);
}

void IngredientInventory::subtractVolumeOf(std::string name, int amt){
    inventory->getItem(name)->subtractVolume(amt);
}

void IngredientInventory::setHaveValueOf(std::string name, int amt){
    inventory->getItem(name)->setHaveValue(amt);
}

void IngredientInventory::setWantValueOf(std::string name, int amt){
    inventory->getItem(name)->setWantValue(amt);
}

List<Ingredient*>* IngredientInventory::listInventory(){
    return inventory->listValues();
}

Ingredient* IngredientInventory::getIngredient(std::string name){
    return inventory->getItem(name);
}

std::string IngredientInventory::toString(){
    List<Ingredient*>* ingredients = inventory->listValues();

    std::string str = "Ingredient inventory: \n";

    for(int i = 0; i < ingredients->itemCount(); i++){
        str+= ingredients->getValueAt(i)->toString();
        str+= "\n\n";
    }
    return str;
}