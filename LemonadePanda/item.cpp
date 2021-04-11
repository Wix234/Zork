#include "item.h"

Item::Item(){};

Item::Item(QString name, QString description, bool pickUp){
    this->name = name;
    this->description = description;
    this->pickUp = pickUp;
}


QString Item::getName(){

    return name;
}

QString Item::getDescription(){

    return description;
}

bool Item::getPickUp(){
    return pickUp;
}

void Item::setName(QString name){
    this -> name = name;
}

void Item::setDescription(QString description){
    this -> description = description;
}


QString Item::getFullDescription(){
    return name + "." + description + "\n";
}
