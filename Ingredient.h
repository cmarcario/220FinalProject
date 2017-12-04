//
// Created by Benjamin on 12/3/17.
//

#ifndef INC_220FINALPROJECT_INGREDIENT_H
#define INC_220FINALPROJECT_INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string name;
    int have;
    int want;

public:
    Ingredient(std::string nameIn);

    void addVolume(int amt);

    void subtractVolume(int amt);

    void setWantValue(int amt);

    void setHaveValue(int amt);

    std::string getName();

    int getWantValue();

    int getHaveValue();

    std::string toString();
};


#endif //INC_220FINALPROJECT_INGREDIENT_H
