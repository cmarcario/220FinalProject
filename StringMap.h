//
// Created by Benjamin on 12/3/17.
//

#ifndef INC_220FINALPROJECT_STRINGMAP_H
#define INC_220FINALPROJECT_STRINGMAP_H

#include <string>
#include "List.h"

template <class T>
class StringMap {
public:

    virtual ~StringMap(){};

    virtual void addItem(std::string key, const T value)=0;

    virtual T getItem(std::string key)=0;

    virtual T removeItem(std::string key)=0;

    virtual List<std::string>* listKeys()=0;

    virtual List<T>* listValues()=0;

    virtual int itemCount()=0;
};

#endif //INC_220FINALPROJECT_STRINGMAP_H
