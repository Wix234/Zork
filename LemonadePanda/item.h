#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QMainWindow>
//make key be an inheritence class of items
class Item {
private:
    QString name;
    QString description;
    bool pickUp;
public:
    //Initializer List
    Item (QString name = "Room name", QString description = "description", bool pickUp = true):name(name), description(description), pickUp(pickUp){};

    QString getShortDescription();
    QString getLongDescription();
    bool getPickUp();
};

#endif /*ITEM_H_*/
