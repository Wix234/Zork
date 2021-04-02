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

private:

    //main
    Ui::MainWindow *ui;

    //variables (grouped by type)
    int temp;

    QDir dir;

    QString mainText;
    QString mainImage;
    QString itemsList;

    QPixmap image;



    room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    room *currentRoom;
    room *nextRoom;

    vector <Item> itemsInRoom;
    vector <Item> itemsInBag;

    QWidget *newWin;
    QVBoxLayout *layout;

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
