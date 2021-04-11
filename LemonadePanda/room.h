#ifndef ROOM_H_
#define ROOM_H_


#include <QMainWindow>
#include <map>
#include <string>
#include <vector>

#include "item.h"
#include "keys.h"


//set bag to array

using namespace std;
using std::vector;

class room {

private:

    QChar roomType;
    double roomNum;
    QString description;
    QString name;
    QString image;
    QString waysOut;

    bool itemRequired; 

    map<string, room*> exits;

    vector <Item*> itemsInRoom;
    vector <Item*> itemsInBag;
    vector <keys*> keysInRoom;


public:
    room();
    room(QChar roomType = 'r', double roomNum = 0, QString description = "description78678678", QString waysOut = "Exits", bool itemRequired = false)
        :roomType(roomType), roomNum(roomNum), description(description), waysOut(waysOut), itemRequired(itemRequired){};



    void setExits(room *north, room *east, room *south, room *west);
    QString shortDescription();
    QString longDescription();
    QString getImage();
    double getRoomNum();
    QChar getRoomType();
    room* nextRoom(string);
    bool isRequired();
    void setRequired(bool itemRequired);

    void setDescription(QString description);

    void addItem(Item *inItem);
    void addItemFromBag(Item *inItem);
    QString displayItem();
    int numberOfItems();
    QString getItems();
    vector <Item*> getItemsArray();
    void removeItem(int placeNum);



};

#endif
