#ifndef ROOM_H_
#define ROOM_H_


#include <QMainWindow>
#include <map>
#include <string>
#include <vector>

#include "item.h"


using namespace std;
using std::vector;

class room {

private:
    QString description;
    QString name;
    QString image;

    int roomNum;

    map<string, room*> exits;

    string exitString();

    vector <Item> itemsInRoom;
    vector <Item> itemsInBag;

public:

    room(int roomNum, QString name, QString description, QString image);
    void setExits(room *north, room *east, room *south, room *west);
    QString shortDescription();
    QString longDescription();
    QString getImage();
    int getRoomNum();
    room* nextRoom(string);

    void addItem(Item *inItem);
    void addItemFromBag(Item inItem);
    QString displayItem();
    int numberOfItems();
    QString getItems();
    vector <Item> getItemsArray();
    void removeItem(int placeNum);
    //int isItemInRoom(string inString);

};

#endif
