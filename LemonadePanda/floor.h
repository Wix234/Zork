#ifndef FLOOR_H
#define FLOOR_H

#include <QMainWindow>

class floor{
private:
    QChar roomType;
    double floorNum;
    int numRooms;
    QString description;

public:
    floor(QChar roomType = 'f', double floorNum = 0, int numRooms = 0, QString description = "description")
        :roomType(roomType), floorNum(floorNum),numRooms(numRooms), description(description){};
    virtual QChar getRoomType();
    virtual double getFloorNum();
    virtual int getNumRooms();
    virtual QString getDescription();
    virtual void setNumRooms(int numRooms);
    virtual void setFloorNum(int floorNum);
    QString getLongDescription();
    void addRoomToFloor();

};

#endif // FLOOR_H
