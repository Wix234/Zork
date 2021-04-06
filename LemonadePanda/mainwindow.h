#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QWidget>
#include <QDir>
#include <QTimer>
#include <QLayout>
#include <QStackedWidget>

#include "widget.h"
#include "room.h"

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



    QPixmap image;

    room *s, *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *h1, *h2, *h3, *h4, *h5, *h6, *h7, *h8, *h9, *h10, *r6_3;
    room *h11, *h12, *h13, *h14, *h15, *h16, *h17, *h21, *r12, *r13, *r14, *r15, *r16;
    room *h18, *h19, *h20, *h22, *h23, *h24, *h25, *r17, *r18, *r20, *r21, *r22, *r23, *r24, *r25, *r26, *r27;
    //idk what happened to room 19 its not on the map oops
    room *currentRoom;
    room *nextRoom;

    vector <Item> itemsInRoom;
    vector <Item> itemsInBag;

    vector<QString> mapImages;

    QWidget *newWin;
    QVBoxLayout *layout;
    QGridLayout *glayout;

    //methods (in order of layout in cpp class)
    void createRooms();
    void printWelcome();
    bool processCommand(int);
    void go(string);
    void addToBag(Item item);
    vector <Item> getBagItems();
    void removeItem(int placeNum);

};

#endif // MAINWINDOW_H
