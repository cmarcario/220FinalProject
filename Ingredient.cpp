//
// Created by Benjamin on 12/3/17.
//

#include "Ingredient.h"

Ingredient::Ingredient(std::string nameIn) {
    name = nameIn;
    have = 0;
    want = 0;
}

void Ingredient::addVolume(int amt){
    have += amt;
}

void Ingredient::subtractVolume(int amt){
    have -= amt;
}

void Ingredient::setWantValue(int amt){
    want = amt;
}

void Ingredient::setHaveValue(int amt){
    have = amt;
}

std::string Ingredient::getName(){
    return name;
}

int Ingredient::getWantValue(){
    return want;
}

int Ingredient::getHaveValue(){
    return have;
}

std::string Ingredient::toString(){
    std::string str = name + "\nAmount in stock: " + std::to_string(have) +"\nIdeal Stock: "+std::to_string(want);
    return str;
}