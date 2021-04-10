#include "floor.h"

QChar floor::getRoomType(){
    return roomType;
}
double floor::getFloorNum(){
    return floorNum;
}
int floor::getNumRooms(){
    return numRooms;
}
QString floor::getDescription(){
    return description;
}
QString floor::getLongDescription(){
    QString temp = "";
    temp += roomType;
    return "You're currently on floor: " + temp + QString::number(floorNum) + ".\nThe number of rooms: " + QString::number(numRooms) + "\n" + description;
}

void floor::setNumRooms(int numRooms){
    this-> numRooms = numRooms;
}

void floor::setFloorNum(int floorNum){
    this-> floorNum = floorNum;
}

void floor::addRoomToFloor(){
    int temp = getNumRooms();
    temp += 1;
    setNumRooms(temp);
}
