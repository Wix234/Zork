#ifndef MAIN_H
#define MAIN_H

#include "roominbuilding.h"

#include <iostream>
#include <string>
using namespace std;

class Zork {
private:
    roomInBuilding *currentRoom;
    void createRooms();



public:
    Zork();
    void play();
    string go(string direction);
    roomInBuilding* getRoom();
};

#endif // MAIN_H
