//
// Created by Kate on 12/10/17.
//

#ifndef INC_220FINALPROJECT_POTION_H
#define INC_220FINALPROJECT_POTION_H

#include "Queue.h"
#include "LinkedQueue.h"
#include "List.h"

#include "Customer.h"
#include "PotionRequirement.h"

class Potion {
private:
    std::string name;
    List<PotionRequirement*>* recipe;
    Queue<Customer*>* waitList;
public:

    //constructor
    Potion(std::string name, List<PotionRequirement *> *recipe);

    //copy constructor
    Potion(const Potion& potionToCopy);

    //assignment operator

    ~Potion();

    std::string getName();

    //returns a string with the potion information formatted
    std::string getPotionInfo();

    //enqueues customer on wait list
    void addToWaitList(Customer* newCustomer);

    //dequeues a customer from the wait list
    Customer* getFromWaitList();

};

#endif //INC_220FINALPROJECT_POTION_H

