//
// Created by Benjamin on 12/14/17.
//

#ifndef INC_220FINALPROJECT_POTIONSHOPMODEL_H
#define INC_220FINALPROJECT_POTIONSHOPMODEL_H

#include "PotionCatalogue.h"
#include "IngredientInventory.h"
#include "PotionRequirement.h"
#include "Customer.h"

class PotionShopModel {
private:
    PotionCatalogue catalogue;
    IngredientInventory inventory;

    void updateIngredientWantValue(std::string ingredientToUpdate);

    bool checkIfCanMakePotion(std::string potionName);

public:

    PotionShopModel();

    PotionShopModel(std::string inventoryFile, std::string catalogueFile);

    std::string getPotionString(std::string potionName);

    std::string listCatalogue();

    std::string listInventory();

    void addPotion (std::string name, List<PotionRequirement*>* recipe);

    void modifyPotion(std::string potionToModify, List<PotionRequirement*>* recipe);

    bool sellPotion(std::string potionName);

    void placeOrder(std::string fileName);

    void takeDelivery(std::string fileName);

    void writeOverstockReport(std::string fileName);

    void writeAllToFile(std::string catalogueFile, std::string inventoryFile);

    void addToWaitList(std::string potionName, std::string customerName, std::string address);
};


#endif //INC_220FINALPROJECT_POTIONSHOPMODEL_H
