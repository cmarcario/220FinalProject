//
// Created by Kate on 12/10/17.
//

#include "List.h"
#include "ArrayList.h"
#include "Potion.h"
#include "PotionRequirement.h"
#include "Customer.h"

List<PotionRequirement*>* makePotionRecipe(){
    List<PotionRequirement*>* potionreqs = new ArrayList<PotionRequirement*>();
    for(int i = 0; i<5; i++) {
        potionreqs->insertAtEnd(new PotionRequirement("ingredient" + std::to_string(i), i));
    }
    return potionreqs;
}

void testPotion() {
    List<PotionRequirement*>* recipe = makePotionRecipe();
    Potion* testPotion = new Potion("Potion1", recipe);
    std::cout << testPotion->getPotionInfo() << std::endl;

    testPotion->addToWaitList(new Customer("Name1", "Address1"));
    testPotion->addToWaitList(new Customer("Name2", "Address2"));
    testPotion->addToWaitList(new Customer("Name3", "Address3"));

    std::cout << testPotion->getFromWaitList()->toString() << std::endl;
    std::cout << testPotion->getFromWaitList()->toString() << std::endl;
    std::cout << testPotion->getFromWaitList()->toString() << std::endl;
}

int main() {

    testPotion();

    return 0;
}