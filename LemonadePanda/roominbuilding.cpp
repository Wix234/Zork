#include "roominbuilding.h"


void roomInBuilding::setExits(roomInBuilding *north, roomInBuilding *east, roomInBuilding *south, roomInBuilding *west){
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

QString roomInBuilding::shortDescription() {
    return description;
}

QString roomInBuilding::longDescription() {
    QString roomID = "";
    QChar tempChar = roomType;
    roomID += tempChar;
    return "Your currently in " + roomID + "" + QString::number(roomNum)  + ".\n" + description + "\n\n" + waysOut;

}


double roomInBuilding::getRoomNum(){
    return roomNum;
}

QChar roomInBuilding::getRoomType(){
    return roomType;
}

roomInBuilding* roomInBuilding::nextRoom(string direction) {
    map<string, roomInBuilding*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

bool roomInBuilding::isRequired(){
    return itemRequired;
}

void roomInBuilding::setRequired(bool itemRequired){
    this-> itemRequired = itemRequired;
}

void roomInBuilding::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

void roomInBuilding::addItemFromBag(Item inItem){
    itemsInRoom.push_back(inItem);
}

QString roomInBuilding::displayItem() {
    QString tempString = "\nItems in room: \n";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "\nNo items in room.";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
}

int roomInBuilding::numberOfItems() {
    return itemsInRoom.size();
}

QString roomInBuilding:: getItems(){
    QString tempString;
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "\nNo items in room.";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
}

vector <Item> roomInBuilding::getItemsArray(){
    return itemsInRoom;
}


void roomInBuilding::removeItem(int placeNum){
    itemsInRoom.erase(itemsInRoom.begin() + placeNum);
}

