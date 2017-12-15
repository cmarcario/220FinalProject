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

    std::string line;

    List<std::string>* potions;



    if (testFile.is_open()){

        while (std::getline(testFile, line)){

            potions = parseLine(line, '@');


        }
        testFile.close();
    }
    else {
        std::cout<<"Could not open file"<<std::endl;
    }
    delete potions;
    potions = nullptr;
}

PotionShopModel::PotionShopModel(std::string inventoryFile, std::string catalogueFile){
    ::addIngredientsFromFile(inventoryFile, inventory);
}

std::string PotionShopModel::getPotionString(std::string potionName){
    return catalogue.getPotionInfo(potionName);
}

std::string PotionShopModel::listCatalogue(){
    return catalogue.getAllPotionInfo();
}

std::string PotionShopModel::listInventory(){
    return inventory.toString();
}

void PotionShopModel::modifyPotion(std::string potionToModify, List<PotionRequirement*>* recipe){
    catalogue.modifyPotion(potionToModify, recipe);
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

void PotionShopModel::placeOrder(std::string fileName){

}

void PotionShopModel::takeDelivery(std::string fileName){

}

void PotionShopModel::writeOverstockReport(std::string fileName){

}

void PotionShopModel::writeAllToFile(std::string fileName){

}
