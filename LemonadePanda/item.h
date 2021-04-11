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
    Item();
    Item(QString name, QString description, bool pickUp);
    QString getName();
    QString getDescription();
    bool getPickUp();
    void setName(QString name);
    void setDescription(QString description);

    QString getFullDescription();
};

#endif /*ITEM_H_*/
