//
// Created by Kate on 12/10/17
//

#ifndef INC_220FINALPROJECT_LINKED_QUEUE_H
#define INC_220FINALPROJECT_LINKED_QUEUE_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"
#include "Queue.h"


/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
template <class T>
class LinkedQueue : public Queue<T> {
private:

    LinkedNode<T>* front;
    LinkedNode<T>* end;
    int count;

public:
    
    //Creates an empty queue
    LinkedQueue();

    //Copy Constructor
    LinkedQueue(const LinkedQueue& queueToCopy);

    //assignment operator
    LinkedQueue& operator=(const LinkedQueue& queueToCopy);

    //Destructor
    ~LinkedQueue();
    
    //adds an item to the end of the queue
    void enqueue(T item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    T dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

    //gets the number of items in the queue
    int getCount();

};

#include "LinkedQueue.inl"

#endif //INC_220FINALPROJECT_LINKED_QUEUE_H
