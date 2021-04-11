#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QWidget>
#include <QDir>
#include <QTimer>
#include <QLayout>
#include <QStackedWidget>
#include <stdio.h>
#include <ctime>



#include "widget.h"
#include "room.h"
#include "inspectitem.h"
#include "floor.h"

//friend inspectItems.h

#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_North_clicked();
    void on_South_clicked();
    void on_East_clicked();
    void on_West_clicked();

    void on_take_clicked();
    void on_bag_clicked();
    void on_map_clicked();
    void on_put_clicked();

    void on_actionHow_To_Play_triggered();
    void on_actionQuit_triggered();

    void on_inspect_clicked();

private:

    //main
    Ui::MainWindow *ui;

    //variables (grouped by type)
    int temp;

    QDir dir;

    QString mainText;
    QString itemText;
    //QString mainImage;
    QString itemsList;
    QString winBg = "QWidget { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 0, 255));}";
    QString lblBg = "QWidget { background-color: rgb(255, 255, 255);}";
    QString btnBg = "QWidget { background-color: rgb(255, 255, 255); font: bold }";
    QString objInteract;

    QFont font = QFont("Consolas", 9);

    QPixmap image;

    struct date{ unsigned int d : 5, m : 4; };

    room *s,*r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *r6_3;
    room *h1, *h2, *h3, *h4, *h5, *h6, *h7, *h8, *h9, *h10;
    floor *f1, *f2;

    room *currentRoom;
    room *nextRoom;

    vector <Item*> itemsInRoom;
    vector <Item*> itemsInBag;

    QString mapImages[2]{":/floor1.jpg", ":/floor2.jpg"};
    floor floorsArr[2];

    QWidget *newWin;
    QVBoxLayout *layout;
    QGridLayout *glayout;

    //methods (in order of layout in cpp class)
    void createRooms();
    void printWelcome();
    bool processCommand(int);
    void go(string);
    void addToBag(Item *item);
    vector <Item*> getBagItems();
    void removeItem(int placeNum);


};

#endif // MAINWINDOW_H
