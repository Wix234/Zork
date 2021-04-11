#ifndef PLUSHIES_H
#define PLUSHIES_H

#include "item.h"
#include "keys.h"
#include "character.h"

class plushies: public Item, public character{
private:
    QString name;
    QString description;
    bool interactable;

public:
    plushies (QString name = "Room name", QString description = "description", bool interactable = true)
        :name(name), description(description), interactable(interactable){};;
};

#endif // PLUSHIES_H
