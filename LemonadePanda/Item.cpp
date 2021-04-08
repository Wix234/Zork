#include "item.h"


QString Item::getShortDescription(){

    return name;
}

QString Item::getLongDescription(){

    return name + ". " + description + "\n";
}

bool Item::getPickUp(){
    return pickUp;
}

