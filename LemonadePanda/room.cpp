#include "room.h"

room::room(QChar roomType, double roomNum, QString description, QString waysOut, bool itemRequired){
    this -> roomType = roomType;
    this -> roomNum = roomNum;
    this -> description = description;
    this -> itemRequired = itemRequired;
    this -> waysOut = waysOut;
}

void room::setExits(room *north, room *east, room *south, room *west){
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

QString room::shortDescription() {
    return description;
}

QString room::longDescription() {
    QString roomID = "";
    QChar tempChar = roomType;
    roomID += tempChar;
    return "Your currently in " + roomID + "" + QString::number(roomNum)  + ".\n" + description + "\n\n" + waysOut;

}

QString room::getImage(){
    return image;
}

double room::getRoomNum(){
    return roomNum;
}

QChar room::getRoomType(){
    return roomType;
}

room* room::nextRoom(string direction) {
    map<string, room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

bool room::isRequired(){
    return itemRequired;
}

void room::setRequired(bool itemRequired){
    this-> itemRequired = itemRequired;
}

void room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

void room::addItemFromBag(Item inItem){
    itemsInRoom.push_back(inItem);
}

QString room::displayItem() {
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

int room::numberOfItems() {
    return itemsInRoom.size();
}

QString room:: getItems(){
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

vector <Item> room::getItemsArray(){
    return itemsInRoom;
}


void room::removeItem(int placeNum){
    itemsInRoom.erase(itemsInRoom.begin() + placeNum);
}


/*int room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}*/
