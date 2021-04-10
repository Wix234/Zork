#ifndef CHARACTER_H
#define CHARACTER_H

#include <QMainWindow>

class character{
private:
    QString name;
    int id;

public:
    character(QString name = "name", int id = 16437907): name(name), id(id){}
};

#endif // CHARACTER_H
