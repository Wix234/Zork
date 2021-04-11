#ifndef INSPECTITEM_H
#define INSPECTITEM_H

#include "room.h"
#include "item.h"

#include <QLabel>
#include <QLayout>
#include <QWidget>

class inspectitem{

private:
    Item *item;
    room *currentRoom;
    QWidget *newWin;
    QVBoxLayout *layout;
    QGridLayout *glayout;

    vector<Item> itemsInBag;

    QString winBg = "QWidget { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 0, 255));}";
    QString lblBg = "QWidget { background-color: rgb(255, 255, 255);}";
    QString btnBg = "QWidget { background-color: rgb(255, 255, 255); font: bold }";

    QFont font = QFont("Consolas", 9);


public:
    inspectitem();
    QString ifStatementsForItems(vector<Item*> itemsInBag, room *currentRoom,Item *item);
};

#endif // INSPECTITEM_H
