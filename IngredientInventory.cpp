//
// Created by Benjamin on 12/3/17.
//

#include "IngredientInventory.h"
#include "ListStringMap.h"

IngredientInventory::IngredientInventory() {
    inventory = new ListStringMap<Ingredient*>();
}

IngredientInventory::~IngredientInventory() {
    List<std::string>* toDelete = inventory->listKeys();

    for (int i = 0; i < toDelete->itemCount(); i++){
        removeIngredient(toDelete->getValueAt(i));
    }

    delete toDelete;

    delete inventory;
}

IngredientInventory::IngredientInventory(const IngredientInventory& inventoryToCopy){

    inventory = new ListStringMap<Ingredient*>();

    List<std::string>* keys = inventoryToCopy.inventory->listKeys();
    List<Ingredient*>* values = inventoryToCopy.inventory->listValues();

    for (int i = 0; inventoryToCopy.inventory->itemCount(); i++){
        addIngredient(new Ingredient(*(values->getValueAt(i))));
    }

    delete keys;
    delete values;
}

IngredientInventory& IngredientInventory::operator=(const IngredientInventory& inventoryToCopy) {
    if (this != &inventoryToCopy){

        List<Ingredient*>* toDelete = inventory->listValues();

        for (int i = 0; i < toDelete->itemCount(); i++){
            delete toDelete->getValueAt(i);
        }

        delete toDelete;
        toDelete = nullptr;

        delete inventory;

        inventory = new ListStringMap<Ingredient*>();

        List<std::string>* keys = inventoryToCopy.inventory->listKeys();
        List<Ingredient*>* values = inventoryToCopy.inventory->listValues();

        for (int i = 0; inventoryToCopy.inventory->itemCount(); i++){
            addIngredient(new Ingredient(*(values->getValueAt(i))));
        }

        delete keys;
        delete values;
    }
    return *this;
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