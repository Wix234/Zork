#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QMainWindow>

class Item {
private:
    QString description;
    QString name;
    bool isWeapon;
    int DMG;

public:
    Item (QString name, QString description);
    Item (QString name, QString description, bool isWeapon, int DMG);
    void setWeaponCheck(bool isWeaapon, int DMG);

    QString getShortDescription();
    QString getLongDescription();
};

#endif /*ITEM_H_*/

