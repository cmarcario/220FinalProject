//
// Created by Benjamin on 12/3/17.
//
#include <iostream>
#include "ArrayLib.h"
#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
    currCapacity = initialCapacity;
    currItemCount = 0;
    array = new T[currCapacity];
}


template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy) {
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    array = new T[currCapacity];

    for (int i = 0; i < currItemCount; i++){
        array[i] = new T(arrayListToCopy.array[i]);
    }
}


//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    if (this != &arrayListToCopy) {

        delete[] array;

        currCapacity = arrayListToCopy.currCapacity;
        currItemCount = arrayListToCopy.currItemCount;
        array = new T[currCapacity];

        for (int i = 0; i < currItemCount; i++){
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}


//Destructor
template <class T>
ArrayList<T>::~ArrayList(){
    delete[] array;
}


template <class T>
void ArrayList<T>::doubleCapacity(){
    currCapacity *= 2;
    T* temp = array;

    array = new T[currCapacity];
    for (int i = 0; i < currItemCount; i++){
        array[i] = temp[i];
    }
    delete[] temp;
    temp = nullptr;
}


template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
    insertAt(itemToAdd, currItemCount);
}


template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd){
    insertAt(itemToAdd,0);
}


template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index){
    if (index < 0 || index > currItemCount){
        throw std::out_of_range("<Index out of bounds>");
    }
    if (currItemCount + 1 > currCapacity){
        doubleCapacity();
    }

    int count = 0;

    for (int i = currItemCount; i > index; --i){
        array[i] = array[i-1];
    }
    array[index] = itemToAdd;
    currItemCount++;
}


template <class T>
T ArrayList<T>::getValueAt(int index){
    if (index < 0 || index >= currItemCount){
        throw std::out_of_range("<Index out of bounds>");
    }
    return array[index];
}


template <class T>
T ArrayList<T>::removeValueAt(int index){
    if (index < 0 || index >= currItemCount){
        throw std::out_of_range("<Index out of bounds>");
    }
    int count = 0;

    T item = array[index];

    currItemCount--;

    for (int i = index; i < currItemCount; i++) {
        array[i] = array[i+1];
    }
    return item;
}


template <class T>
bool ArrayList<T>::isEmpty(){
    return currItemCount == 0;
}


template <class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}


template <class T>
void ArrayList<T>::clearList(){
    currItemCount = 0;
}


template <class T>
std::string ArrayList<T>::toString(){
    std::string str = "";
    return str;
}


template <class T>
int ArrayList<T>::find(T itemToFind){
    int count = 0;
    return -1;
}

