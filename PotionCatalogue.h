//
// Created by Benjamin on 11/30/17.
//

#ifndef INC_220FINALPROJECT_POTIONCATALOGUE_H
#define INC_220FINALPROJECT_POTIONCATALOGUE_H

#include <string>
#include "Potion.h"
#include "StringMap.h"

class PotionCatalogue{

private:

    StringMap<Potion*>* catalogue;

public:

    //constructor
    PotionCatalogue();

    //destructor
    ~PotionCatalogue();

    //copy constructor
    PotionCatalogue(const PotionCatalogue &potionCatalogueToCopy);

    //assignment operator
    PotionCatalogue& operator=(const PotionCatalogue& catalogueToCopy);

    //add potion to the catalogue with potion object
    void addPotion(Potion* potionToAdd);

    //add potion to the catalogue with name and recipe
    void addPotion(std::string name, List<PotionRequirement*>* recipe);

    //remove a potion from the catalogue
    void removePotion(std::string name);

    //returns string with info for given potion
    std::string getPotionInfo(std::string name);

    //returns string with info for all potions
    std::string getAllPotionInfo();

    //modify the recipe for a given potion by replacing the incredient list
    void modifyPotion(std::string name, List<PotionRequirement*>* newRecipe);

    //returns a pointer to a given potion
    Potion* getPotion(std::string name);

    //adds a customer to the wait list of the given potion
    void addCustomerToPotion(std::string potionName, Customer* customer);

    //adds customer to the wait list of a potion from name and address
    void addCustomerToPotion(std::string potionName, std::string customerName, std::string address);

    //get wait list of a given potion w/o changing it
    std::string getPotionWaitList(std::string name);

    //get all potion wait lists
    std::string getAllWaitLists();

    //get the recipe and wait list information for all potions
    std::string getAllInfoAndWaitLists();


};

#endif //INC_220FINALPROJECT_POTIONCATALOGUE_H
