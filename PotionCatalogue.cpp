//
// Created by Kate on 12/10/17.
//

#include "PotionCatalogue.h"
#include "ListStringMap.h"

PotionCatalogue::PotionCatalogue() {
    catalogue = new ListStringMap<Potion*>();
}

PotionCatalogue::~PotionCatalogue() {
    delete catalogue;
}

void PotionCatalogue::addPotion(Potion* potionToAdd){
    catalogue->addItem(potionToAdd->getName(), potionToAdd);
}

void PotionCatalogue::removePotion(std::string name){
    Potion* potionToRemove = catalogue->removeItem(name);
    delete potionToRemove;
}

std::string PotionCatalogue::getPotionInfo(std::string name){
    return catalogue->getItem(name)->getPotionInfo();
}

std::string* PotionCatalogue::getAllPotionInfo(){
    std::string allInfo = "All Potion Info:\n";
    List<Potion*>* allPotions = catalogue->listValues();
    for (int i = 0; i < allPotions->itemCount(); i++) {
        allInfo+=allPotions->getValueAt(i)->getPotionInfo();
        allInfo+="\n";
    }
}

void PotionCatalogue::modifyPotion(std::string name, Potion* newPotion){
    Potion* potionToModify = catalogue->getItem(name);
    delete potionToModify;
    potionToModify = newPotion;
}

Potion* PotionCatalogue::getPotion(std::string name){
    return catalogue->getItem(name);
}

void PotionCatalogue::addCustomerToPotion(std::string potionName, Customer* customer) {
    catalogue->getItem(potionName)->addToWaitList(customer);
}