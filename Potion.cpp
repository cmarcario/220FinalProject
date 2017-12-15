//
// Created by Kate on 12/10/17.
//

#include <string>
#include "Potion.h"
#include "ArrayList.h"

Potion::Potion(std::string name, List<PotionRequirement*>* recipe) {
    this->name = name;
    this->recipe = recipe;
    waitList = new LinkedQueue<Customer*>();
}

Potion::Potion(const Potion& potionToCopy) {
    name = potionToCopy.name;
    recipe = new ArrayList<PotionRequirement*>();
    for (int i = 0; i < potionToCopy.recipe->itemCount(); i++) {
        PotionRequirement* toCopy = potionToCopy.recipe->getValueAt(i);
        PotionRequirement* toAdd = new PotionRequirement(toCopy->getName(), toCopy->getNumNeeded());
        recipe->insertAtEnd(toAdd);
    }
    waitList = new LinkedQueue<Customer*>();
    List<Customer*>* qToCopy = new ArrayList<Customer*>();
    while(!potionToCopy.waitList->isEmpty()) {
        qToCopy->insertAtEnd(potionToCopy.waitList->dequeue());
    }
    for (int i = 0; i < qToCopy->itemCount(); i++) {
        potionToCopy.waitList->enqueue(new Customer(qToCopy->getValueAt(i)->getName(), qToCopy->getValueAt(i)->getAddress()));
        waitList->enqueue(new Customer(qToCopy->getValueAt(i)->getName(), qToCopy->getValueAt(i)->getAddress()));
        delete qToCopy->getValueAt(i);
    }

}

Potion& Potion::operator=(const Potion& potionToCopy) {
    if (this != &potionToCopy) {
        for (int i = 0; i < recipe->itemCount(); i++) {
            delete recipe->getValueAt(i);
        }
        while(!waitList->isEmpty()) {
            delete waitList->dequeue();
        }
        delete recipe;
        delete waitList;

        name = potionToCopy.name;
        recipe = new ArrayList<PotionRequirement*>();
        for (int i = 0; i < potionToCopy.recipe->itemCount(); i++) {
            PotionRequirement* toCopy = potionToCopy.recipe->getValueAt(i);
            PotionRequirement* toAdd = new PotionRequirement(toCopy->getName(), toCopy->getNumNeeded());
            recipe->insertAtEnd(toAdd);
        }
        waitList = new LinkedQueue<Customer*>();
        List<Customer*>* qToCopy = new ArrayList<Customer*>();
        while(!potionToCopy.waitList->isEmpty()) {
            qToCopy->insertAtEnd(potionToCopy.waitList->dequeue());
        }
        for (int i = 0; i < qToCopy->itemCount(); i++) {
            potionToCopy.waitList->enqueue(new Customer(qToCopy->getValueAt(i)->getName(), qToCopy->getValueAt(i)->getAddress()));
            waitList->enqueue(new Customer(qToCopy->getValueAt(i)->getName(), qToCopy->getValueAt(i)->getAddress()));
            delete qToCopy->getValueAt(i);
        }
    }
    return *this;
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
    std::string info = name + " Recipe: \n";
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

void Potion::modifyRecipe(List<PotionRequirement*>* newRecipe) {
    for (int i = 0; i < recipe->itemCount(); i++) {
        delete recipe->getValueAt(i);
    }
    delete recipe;
    recipe = newRecipe;
}

std::string Potion::getWaitList() {
    Queue<Customer*>* tempList = new LinkedQueue<Customer*>();
    std::string waitListString = name + " Wait List:\n";
    if (waitList->isEmpty()) {
        waitListString+= "None\n";
    }
    while(!waitList->isEmpty()) {
        Customer* curr = waitList->dequeue();
        waitListString+=curr->toString();
        tempList->enqueue(curr);
    }
    delete waitList;
    waitList = tempList;
    return waitListString;
}

List<PotionRequirement*>* Potion::getRecipe(){
    return recipe;
}