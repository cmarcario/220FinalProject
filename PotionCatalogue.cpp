//
// Created by Kate on 12/10/17.
//

#include "PotionCatalogue.h"
#include "Ingredient.h"
#include "ListStringMap.h"
#include "List.h"

PotionCatalogue::PotionCatalogue() {
    catalogue = new ListStringMap<Potion*>();
}

PotionCatalogue::PotionCatalogue(const PotionCatalogue& catalogueToCopy) {
    catalogue = new ListStringMap<Potion*>;
    List<std::string>* keys = catalogueToCopy.catalogue->listKeys();
    List<Potion*>* values = catalogueToCopy.catalogue->listValues();
    for (int i = 0; i < keys->itemCount(); i++) {
        //catalogue->addItem(keys->getValueAt(i), );
    }

    //catalogue->addItem(catalogue->)
}

PotionCatalogue& PotionCatalogue::operator=(const PotionCatalogue& catalogueToCopy) {
    if (this != &catalogueToCopy) {

    }
    return *this;
}

PotionCatalogue::~PotionCatalogue() {
    List<std::string>* keys = catalogue->listKeys();
    for (int i = 0; i < keys->itemCount(); i++) {
        Potion* toDelete = catalogue->getItem(keys->getValueAt(i));
        delete toDelete;
    }
    delete catalogue;
    delete keys;
}

void PotionCatalogue::addPotion(Potion* potionToAdd){
    catalogue->addItem(potionToAdd->getName(), potionToAdd);
}

void PotionCatalogue::addPotion(std::string name, List<PotionRequirement*>* recipe){
    addPotion(new Potion(name, recipe));
}

void PotionCatalogue::removePotion(std::string name){
    Potion* potionToRemove = catalogue->removeItem(name);
    delete potionToRemove;
}

std::string PotionCatalogue::getPotionInfo(std::string name){
    return catalogue->getItem(name)->getPotionInfo();
}

std::string PotionCatalogue::getAllPotionInfo(){
    std::string allInfo = "All Potion Info:\n";
    List<Potion*>* allPotions = catalogue->listValues();
    for (int i = 0; i < allPotions->itemCount(); i++) {
        allInfo+=allPotions->getValueAt(i)->getPotionInfo();
        allInfo+="\n";
    }
    return allInfo;
}

void PotionCatalogue::modifyPotion(std::string name, List<PotionRequirement*>* newRecipe){
    catalogue->getItem(name)->modifyRecipe(newRecipe);
}

Potion* PotionCatalogue::getPotion(std::string name){
    return catalogue->getItem(name);
}

void PotionCatalogue::addCustomerToPotion(std::string potionName, Customer* customer) {
    catalogue->getItem(potionName)->addToWaitList(customer);
}

void PotionCatalogue::addCustomerToPotion(std::string potionName, std::string customerName, std::string address) {
    addCustomerToPotion(potionName, new Customer(customerName, address));
}

std::string PotionCatalogue::getPotionWaitList(std::string name){
    return catalogue->getItem(name)->getWaitList();
}

std::string PotionCatalogue::getAllWaitLists() {
    std::string allInfo = "All Potion Wait Lists:\n";
    List<Potion*>* allPotions = catalogue->listValues();
    for (int i = 0; i < allPotions->itemCount(); i++) {
        allInfo+=allPotions->getValueAt(i)->getWaitList();
        allInfo+="\n";
    }
    return allInfo;
}

std::string PotionCatalogue::getAllInfoAndWaitLists() {
    std::string allInfo = "All Potion Information and Wait Lists:\n";
    List<Potion*>* allPotions = catalogue->listValues();
    for (int i = 0; i < allPotions->itemCount(); i++) {
        allInfo+=allPotions->getValueAt(i)->getPotionInfo();
        allInfo+=allPotions->getValueAt(i)->getWaitList();
        allInfo+="\n";
    }

    return allInfo;
}