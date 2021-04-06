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
    QString waysOut;


    bool itemRequired;

    QChar roomType;

    double roomNum;

    map<string, room*> exits;

    string exitString();

    vector <Item> itemsInRoom;
    vector <Item> itemsInBag;

public:

    //room(QChar roomType, double roomNum, QString description, QString image, bool itemRequired);
    room(QChar roomType, double roomNum, QString description, QString waysOut, bool itemRequired);
    void setExits(room *north, room *east, room *south, room *west);
    QString shortDescription();
    QString longDescription();
    QString getImage();
    double getRoomNum();
    QChar getRoomType();
    room* nextRoom(string);
    bool isRequired();
    void setRequired(bool itemRequired);

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
