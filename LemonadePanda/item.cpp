#include "item.h"

Item::Item (QString name, QString description) {
    this -> name = name;
    this -> description = description;
}

Item::Item (QString name, QString description, bool isWeapon, int DMG) {
    this -> name = name;
    this -> description = description;
    this -> DMG = DMG;
    this -> isWeapon = isWeapon;
    setWeaponCheck(isWeapon, DMG);
}

void Item::setWeaponCheck(bool isWeapon, int DMG){

    if(isWeapon != true){
        this -> DMG = 0;
    } else {
        this -> DMG = DMG;
    }

}

QString Item::getShortDescription(){

    return name;
}

QString Item::getLongDescription(){

    if (isWeapon == false){
        return name + ". " + description + ".\n";
    } else {
        return name + " " + description + ". It's a weapon that does " + QString::number(DMG) + " damage.\n";
    }
}

