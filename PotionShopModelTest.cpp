//
// Created by Benjamin on 12/14/17.
//

#include <iostream>
#include "PotionShopModelTest.h"
#include "PotionShopModel.h"
#include "List.h"
#include "ArrayList.h"

int main(){
    PotionShopModel model;

    List<PotionRequirement*>* recipe1 = new ArrayList<PotionRequirement*>;
    List<PotionRequirement*>* recipe2 = new ArrayList<PotionRequirement*>;
    List<PotionRequirement*>* recipe3 = new ArrayList<PotionRequirement*>;
    List<PotionRequirement*>* recipe4 = new ArrayList<PotionRequirement*>;

    recipe1->insertAtEnd(new PotionRequirement("Lacewing flies", 2));
    recipe1->insertAtEnd(new PotionRequirement("jungle juice", 7));
    recipe1->insertAtEnd(new PotionRequirement("marijuana", 1));

    recipe2->insertAtEnd(new PotionRequirement("Voldemort's armpit", 1));
    recipe2->insertAtEnd(new PotionRequirement("the devil", 7));
    recipe2->insertAtEnd(new PotionRequirement("Ron Weasly", 4));
    recipe2->insertAtEnd(new PotionRequirement("marijuana", 1));

    recipe3->insertAtEnd(new PotionRequirement("Hard drive", 1));
    recipe3->insertAtEnd(new PotionRequirement("Bryan", 3));
    recipe3->insertAtEnd(new PotionRequirement("Kate", 1));
    recipe3->insertAtEnd(new PotionRequirement("Chiara marijuana", 9));
    recipe3->insertAtEnd(new PotionRequirement("Benjamin's tears", 1000000));

    recipe4->insertAtEnd(new PotionRequirement("trolololol", 1));
    recipe4->insertAtEnd(new PotionRequirement("Bacon", 3));
    recipe4->insertAtEnd(new PotionRequirement("A Burgundy lock of Toby Dragon's hair", 1));
    recipe4->insertAtEnd(new PotionRequirement("LSD", 100));

    model.addPotion("PolyJuice", recipe1);
    model.addPotion("Yummyjumba", recipe2);
    model.addPotion("Herpes", recipe3);

    model.modifyPotion("Herpes", recipe4);

    model.addToWaitList("Herpes", "Devan Rosen", "The woods");

    std::cout<<model.listInventory()<<std::endl;

    std::cout<<model.listCatalogue()<<std::endl;

    std::cout<<model.getPotionString("Herpes")<<std::endl;

    PotionShopModel* model1 = new PotionShopModel("test.txt", "modelSetupTest.txt");

    std::cout<<model1->listInventory()<<std::endl;

    std::cout<<model1->listCatalogue()<<std::endl;
    return 0;
}