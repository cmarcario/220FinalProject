//
// Created by Benjamin on 12/14/17.
//

#include "PotionShopModel.h"
#include <fstream>
#include "IOLib.h"

/*
 * @post inventory will be modifed to contain all the ingredients listed in the specified file
 */
void addIngredientsFromFile(std::string fileName, IngredientInventory& inventory){
    std::ifstream testFile;
    testFile.open(fileName);

    std::string line;

    List<std::string>* data;

    if (testFile.is_open()){

        while (std::getline(testFile, line)){

            data = parseLine(line, ',');
            inventory.addIngredient(data->getValueAt(0), atoi(data->getValueAt(1).c_str()), atoi(data->getValueAt(2).c_str()));
        }
        testFile.close();
    }
    else {
        std::cout<<"Could not open file"<<std::endl;
    }
    delete data;
    data = nullptr;
}

void addPotionsFromFile(std::string fileName, PotionCatalogue& catalogue){
    std::ifstream testFile;
    testFile.open(fileName);

    if (testFile.is_open()) {

        std::string line;

        List<std::string>* potions = nullptr;

        List<std::string>* customers = nullptr;

        List<std::string>* ingredients = nullptr;

        std::string name;

        while (std::getline(testFile, line)) {

            potions = parseLine(line, '@');

            name = potions->getValueAt(0);

            ingredients = parseLine(potions->getValueAt(2), '&');
            customers = parseLine(potions->getValueAt(1), '&');

            List<std::string>* ingredient;

            List<PotionRequirement *> *requirements = new ArrayList<PotionRequirement *>();

            for (int i = 0; i < ingredients->itemCount(); i++) {
                ingredient = parseLine(ingredients->getValueAt(i), ',');

                PotionRequirement *require = new PotionRequirement(ingredient->getValueAt(0),
                                                                   atoi(ingredient->getValueAt(1).c_str()));

                requirements->insertAtEnd(require);
            }
            delete ingredient;
            ingredient = nullptr;

            catalogue.addPotion(name, requirements);

            List<std::string>* customer;

            for (int i = 0; i < customers->itemCount(); i++) {
                customer = parseLine(customers->getValueAt(i), ',');

                catalogue.addCustomerToPotion(name, customer->getValueAt(0), customer->getValueAt(1));
            }
            delete customer;
            customer = nullptr;
        }
        testFile.close();

        delete potions;
        delete customers;
        delete ingredients;
    }
    else {
        std::cout<<"Could not open file"<<std::endl;
    }
}

PotionShopModel::PotionShopModel(){}

PotionShopModel::PotionShopModel(std::string inventoryFile, std::string catalogueFile){
    ::addIngredientsFromFile(inventoryFile, inventory);
    ::addPotionsFromFile(catalogueFile, catalogue);
}

void PotionShopModel::updateIngredientWantValue(std::string ingredientToUpdate){
    if (!(inventory.checkIfIngredientExists(ingredientToUpdate))){
        inventory.addIngredient(ingredientToUpdate);
    }

    try {
        inventory.setWantValueOf(ingredientToUpdate, 10);
    } catch (std::out_of_range){
        std::cout<<"Ya done fucked up son"<<std::endl;
    }
}

std::string PotionShopModel::getPotionString(std::string potionName){
    return catalogue.getPotionInfo(potionName);
}

std::string PotionShopModel::listCatalogue(){
    return catalogue.getAllInfoAndWaitLists();
}

std::string PotionShopModel::listInventory(){
    return inventory.toString();
}

void PotionShopModel::addPotion(std::string name, List<PotionRequirement *> *recipe) {
    catalogue.addPotion(name, recipe);

    for (int i = 0; i < recipe->itemCount(); i++){
        updateIngredientWantValue(recipe->getValueAt(i)->getName());
    }
}

void PotionShopModel::modifyPotion(std::string potionToModify, List<PotionRequirement*>* recipe){
    catalogue.modifyPotion(potionToModify, recipe);

    for (int i = 0; i < recipe->itemCount(); i++){
        updateIngredientWantValue(recipe->getValueAt(i)->getName());
    }
}


bool PotionShopModel::checkIfCanMakePotion(std::string potionName) {
    Potion* potionToSell = catalogue.getPotion(potionName);

    List<PotionRequirement*>* recipe = potionToSell->getRecipe();

    for (int i = 0; i < recipe->itemCount(); i++){
        PotionRequirement* ingredient = recipe->getValueAt(i);

        if(ingredient->getNumNeeded() > inventory.getHaveValueOf(ingredient->getName())){
            return false;
        }
    }
    return true;
}


bool PotionShopModel::sellPotion(std::string potionName){
    if (checkIfCanMakePotion(potionName)){
        Potion* potionToSell = catalogue.getPotion(potionName);

        List<PotionRequirement*>* recipe = potionToSell->getRecipe();

        for (int i = 0; i < recipe->itemCount(); i++){
            PotionRequirement* ingredient = recipe->getValueAt(i);

            inventory.subtractVolumeOf(ingredient->getName(), ingredient->getNumNeeded());
        }
        return true;
    }
    else {
        return false;
    }
}

void PotionShopModel::addToWaitList(std::string potionName, std::string customerName, std::string address){
    catalogue.addCustomerToPotion(potionName, customerName, address);
}

void PotionShopModel::placeOrder(std::string fileName){

}

void PotionShopModel::takeDelivery(std::string fileName){
    ::addIngredientsFromFile(fileName, inventory);
}

void PotionShopModel::writeOverstockReport(std::string fileName){

}

void PotionShopModel::writeAllToFile(std::string catalogueFile, std::string inventoryFile){

}
