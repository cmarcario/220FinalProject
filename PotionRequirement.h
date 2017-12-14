//
// Created by Kate on 12/10/17.
//

#ifndef INC_220FINALPROJECT_POTIONREQUIREMENT_H
#define INC_220FINALPROJECT_POTIONREQUIREMENT_H

#include <string>

class PotionRequirement {
private:
    std::string name;
    int numNeeded;

public:
    PotionRequirement(std::string name, int numNeeded) {
        this->name = name;
        this->numNeeded = numNeeded;
    }

    std::string getName() {
        return name;
    }

    int getNumNeeded() {
        return numNeeded;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setNumNeeded(int newAmount) {
        numNeeded = newAmount;
    }
};

#endif //INC_220FINALPROJECT_POTIONREQUIREMENT_H
