//
// Created by Kate on 12/10/17
//

#ifndef INC_220FINALPROJECT_QUEUE_H
#define INC_220FINALPROJECT_QUEUE_H

#include <string>
#include <stdexcept>

/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
template <class T>
class Queue {
public:

    //default destructor, declared virtual to ensure that child destructors are called
    virtual ~Queue(){};
    
    //adds an item to the end of the queue
    virtual void enqueue(T item)=0;

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    virtual T dequeue()=0;

    //returns true if the queue has no items, false otherwise
    virtual bool isEmpty()=0;

};

#endif //INC_220FINALPROJECT_QUEUE_H
