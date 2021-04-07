#ifndef INSPECTITEMS_H
#define INSPECTITEMS_H

#include "room.h"
#include "item.h"

#include <QLabel>

class inspectItems
{
public:
    inspectItems();
    void ifStatementsForItems(room currentRoom, Item items);
};

#endif // INSPECTITEMS_H
