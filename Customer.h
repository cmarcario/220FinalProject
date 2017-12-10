//
// Created by Kate on 12/10/17.
//

#ifndef INC_220FINALPROJECT_CUSTOMER_H
#define INC_220FINALPROJECT_CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string address;

public:
    Customer(std::string name, std::string address) {
        this->name = name;
        this->address = address;
    }

    std::string getName() {
        return name;
    }

    std::string getAddress() {
        return address;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setAddress(std::string newAddress) {
        address = newAddress;
    }

    std::string toString(){
        return "Name: " + name + "\nAddress: " + address + "\n";
    }
};

#endif //INC_220FINALPROJECT_CUSTOMER_H
