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

    PotionCatalogue();

    //copy constructor

    //assignment operator

    ~PotionCatalogue();

    void addPotion(Potion* potionToAdd);

    void removePotion(std::string name);

    //returns string with info for given potion
    std::string getPotionInfo(std::string name);

    //returns string with info for all potions
    std::string* getAllPotionInfo();

    //replace a potion in the map with a new potion
    void modifyPotion(std::string name, Potion* newPotion);

    //returns a pointer to a given potion
    Potion* getPotion(std::string name);

    //adds a customer to the wait list of the given potion
    void addCustomerToPotion(std::string potionName, Customer* customer);


};

#endif //INC_220FINALPROJECT_POTIONCATALOGUE_H
