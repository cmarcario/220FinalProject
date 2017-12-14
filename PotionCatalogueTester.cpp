//
// Created by Kate on 12/10/17.
//

#include "List.h"
#include "ArrayList.h"
#include "PotionCatalogue.h"
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

void testPotions() {
    List<PotionRequirement*>* recipe = makePotionRecipe();
    Potion* testPotion = new Potion("Potion1", recipe);
    std::cout << testPotion->getPotionInfo() << std::endl;

    testPotion->addToWaitList(new Customer("Name1", "Address1"));
    testPotion->addToWaitList(new Customer("Name2", "Address2"));
    testPotion->addToWaitList(new Customer("Name3", "Address3"));

    std::cout << testPotion->getFromWaitList()->toString() << std::endl;
    std::cout << testPotion->getFromWaitList()->toString() << std::endl;
    std::cout << testPotion->getFromWaitList()->toString() << std::endl;

    List<PotionRequirement*>* recipe2 = makePotionRecipe();
    List<PotionRequirement*>* recipe3 = makePotionRecipe();
    List<PotionRequirement*>* recipe4 = makePotionRecipe();

    Potion* test2 = new Potion("Potion2", recipe2);
    Potion* test3 = new Potion("Potion3", recipe3);
    //Potion* test4 = new Potion("Potion4", recipe4);

    PotionCatalogue* catalogue = new PotionCatalogue();
    catalogue->addPotion(testPotion);
    catalogue->addPotion("Potion4", recipe4);
    catalogue->addPotion(test2);
    catalogue->addPotion(test3);

    catalogue->removePotion("Potion2");

    //std::cout << catalogue->getPotionInfo("Potion3") << std::endl;

    std::cout << catalogue->getAllPotionInfo() << std::endl;

    catalogue->addCustomerToPotion("Potion4", "Name4", "address4");
    catalogue->addCustomerToPotion("Potion4", new Customer("Name5", "address5"));

    std::cout << catalogue->getPotionWaitList("Potion4") << std::endl;
    std::cout << catalogue->getPotionWaitList("Potion4") << std::endl;

//    List<PotionRequirement*>* potionreqs = new ArrayList<PotionRequirement*>();
//    for(int i = 5; i<10; i++) {
//        potionreqs->insertAtEnd(new PotionRequirement("ingredient" + std::to_string(i), i));
//    }
//
//    catalogue->modifyPotion("Potion3", potionreqs);

    std::cout << catalogue->getAllPotionInfo() << std::endl;

    std::cout << catalogue->getAllWaitLists() << std::endl;

    std::cout << catalogue->getAllInfoAndWaitLists() << std::endl;

}

void testCopyConstructor() {
    List<PotionRequirement*>* recipe = makePotionRecipe();
    Potion* testPotion = new Potion("Potion1", recipe);

    testPotion->addToWaitList(new Customer("Name1", "Address1"));
    testPotion->addToWaitList(new Customer("Name2", "Address2"));
    testPotion->addToWaitList(new Customer("Name3", "Address3"));

    Potion* copyPotion = new Potion(*testPotion);

    std::cout << testPotion->getPotionInfo() << std::endl;
    std::cout << testPotion->getWaitList() << std::endl;

    std::cout << copyPotion->getPotionInfo() << std::endl;
    std::cout << copyPotion->getWaitList() << std::endl;

    List<PotionRequirement*>* potionreqs = new ArrayList<PotionRequirement*>();
    for(int i = 5; i<10; i++) {
        potionreqs->insertAtEnd(new PotionRequirement("ingredient" + std::to_string(i), i));
    }
    testPotion->modifyRecipe(potionreqs);
    testPotion->addToWaitList(new Customer("Name4", "Address4"));

    std::cout << testPotion->getPotionInfo() << std::endl;
    std::cout << testPotion->getWaitList() << std::endl;

    std::cout << copyPotion->getPotionInfo() << std::endl;
    std::cout << copyPotion->getWaitList() << std::endl;

}

int main() {

    //testPotions();

    //testCopyConstructor();

    return 0;
}