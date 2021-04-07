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
    int size;
public:
    //Initializer List
    Item (QString name = "Room name", QString description = "description", int size = 0):name(name), description(description), size(size){};

    QString getShortDescription();
    QString getLongDescription();
    int getSize();
};

#endif /*ITEM_H_*/
