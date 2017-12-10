//
// Created by Kate on 12/10/17.
//

#include <string>
#include "Potion.h"

Potion::Potion(std::string name, List<PotionRequirement*>* recipe) {
    this->name = name;
    this->recipe = recipe;
    waitList = new LinkedQueue<Customer*>();
}

Potion::Potion(const Potion& potionToCopy) {

}

Potion::~Potion() {
    for (int i = 0; i < recipe->itemCount(); i++) {
        delete recipe->getValueAt(i);
    }
    while(!waitList->isEmpty()) {
        delete waitList->dequeue();
    }
    delete recipe;
    delete waitList;
}

std::string Potion::getName(){
    return name;
}

std::string Potion::getPotionInfo(){
    std::string info = "Name: " + name + "\n";
    for (int i = 0; i < recipe->itemCount(); i++) {
        info+=recipe->getValueAt(i)->getName();
        info+=": ";
        info+=std::to_string(recipe->getValueAt(i)->getNumNeeded());
        info+="\n";
    }
    return info;
}

void Potion::addToWaitList(Customer* newCustomer){
    waitList->enqueue(newCustomer);
}

Customer* Potion::getFromWaitList(){
    return waitList->dequeue();
}