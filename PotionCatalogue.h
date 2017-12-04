//
// Created by Benjamin on 11/30/17.
//

#ifndef INC_220FINALPROJECT_POTIONCATALOGUE_H
#define INC_220FINALPROJECT_POTIONCATALOGUE_H

#include <string>

class PotionCatalogue{
public:

    void addPotion(Potion* potionToAdd);

    void removePotion(std::string name);

    std::string getPotionInfo(std::string name);

    std::string* getAllPotionInfo();

    void modifyPotion(std::string name, Potion* newPotion);

    Potion* getPotion(std::string name);
};

#endif //INC_220FINALPROJECT_POTIONCATALOGUE_H
