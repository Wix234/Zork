#include "item.h"


QString Item::getShortDescription(){

    return name;
}

QString Item::getLongDescription(){

    return name + ". " + description + ".\n";
}

int Item::getSize(){
    return size;
}
