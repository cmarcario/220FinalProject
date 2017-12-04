//
// Created by Benjamin on 12/3/17.
//

#ifndef INC_220FINALPROJECT_LISTSTRINGMAP_H
#define INC_220FINALPROJECT_LISTSTRINGMAP_H

#include "StringMap.h"

template <class T>
class ListStringMap : public StringMap<T> {
private:
    List<std::string>* keys;
    List<T>* values;

    int findSortIndex(std::string key);

public:
    ListStringMap();

    ~ListStringMap();

    void addItem(std::string key, const T value);

    T getItem(std::string key);

    T removeItem(std::string key);

    List<std::string>* listKeys();

    List<T>* listValues();

    int itemCount();
};

#include "ListStringMap.inl"

#endif //INC_220FINALPROJECT_LISTSTRINGMAP_H
