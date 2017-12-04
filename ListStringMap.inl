//
// Created by Benjamin on 12/3/17.
//

#include "ListStringMap.h"
#include "ArrayList.h"

template <class T>
ListStringMap<T>::ListStringMap(){
    keys = new ArrayList<std::string>();
    values = new ArrayList<T>();
}

template <class T>
ListStringMap<T>::~ListStringMap(){
    delete keys;
    delete values;
}


template <class T>
int ListStringMap<T>::findSortIndex(std::string key) {
    if (keys->isEmpty()){
        return 0;
    }

    for (int i = 0; i < keys->itemCount(); i++){
        int check = keys->getValueAt(i).compare(key);
        if (check >= 0){
            return i;
        }
    }
    return keys->itemCount();
}

template <class T>
void ListStringMap<T>::addItem(std::string key, const T value){
    int idx = findSortIndex(key);

    keys->insertAt(key, idx);
    values->insertAt(value, idx);
}

template <class T>
T ListStringMap<T>::getItem(std::string key){
    int idx = findSortIndex(key);

    return values->getValueAt(idx);
}

template <class T>
T ListStringMap<T>::removeItem(std::string key){

    int idx = findSortIndex(key);

    keys->removeValueAt(idx);
    return values->removeValueAt(idx);
}

template <class T>
List<std::string>* ListStringMap<T>::listKeys(){
    List<std::string>* strLi =  keys;
    return strLi;
}

template <class T>
List<T>* ListStringMap<T>::listValues(){
    List<T>* tLi =  values;
    return tLi;
}

template <class T>
int ListStringMap<T>::itemCount(){
    return keys->itemCount();
}

