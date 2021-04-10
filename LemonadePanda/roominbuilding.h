#ifndef ROOMINBUILDING_H_
#define ROOMINBUILDING_H_


#include <QMainWindow>
#include <map>
#include <string>
#include <vector>

#include "item.h"
#include "floor.h"


using namespace std;
using std::vector;

class roomInBuilding : public floor {

private:
    QChar roomType;
    double roomNum;
    QString description;
    QString name;
    QString waysOut;

    bool itemRequired;

    map<string, roomInBuilding*> exits;

    string exitString();

    vector <Item> itemsInRoom;
    vector <Item> itemsInBag;

public:

    //room(QChar roomType, double roomNum, QString description, QString image, bool itemRequired);
    roomInBuilding(QChar roomType = 'r', double roomNum = 0, QString description = "description", QString waysOut = "Exits", bool itemRequired = false)
            :roomType(roomType), roomNum(roomNum), description(description), waysOut(waysOut), itemRequired(itemRequired){};
    void setExits(roomInBuilding *north, roomInBuilding *east, roomInBuilding *south, roomInBuilding *west);
    QString shortDescription();
    QString longDescription();
    double getRoomNum();
    QChar getRoomType();
    roomInBuilding* nextRoom(string);
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
