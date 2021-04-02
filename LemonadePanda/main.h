#ifndef MAIN_H
#define MAIN_H

#include "room.h"

#include <iostream>
#include <string>
using namespace std;

class Zork {
private:
    room *currentRoom;
    void createRooms();



public:
    Zork();
    void play();
    string go(string direction);
    room* getRoom();
};

#endif // MAIN_H
