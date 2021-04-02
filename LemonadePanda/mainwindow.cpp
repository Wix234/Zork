#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow){

    ui -> setupUi(this);
    createRooms();
    printWelcome();
    ui->textBox->setText(mainText);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::createRooms()  {

    a = new room(1, "Apple", "It's red or green, round and crunchy",":/apple.jfif" );
        a->addItem(new Item("Panda", "Dangerous when hungry", true, 70));
        a->addItem(new Item("Lemon", "Sour", true, 60));
    b = new room(2, "Banana", "Yellow long and curvy", ":/banana.jpg");
        b->addItem(new Item("Cat", "It meows", false, NULL));
    c = new room(3, "Cantalope","Is it a melon?", ":/cantalope.jfif");
    d = new room(4, "Dragon Fruit", "I was really hoping a small dragon lives inside it",":/dragon fruit.jpg");
    e = new room(5, "Elderberry", "But they aren't even that old", ":/elderberry.jfif");
    f = new room(6, "Fig", "Figures", ":/fig.jfif");
    g = new room(7, "Grape", "Purple balls of seeds", ":/grape.jfif");
    h = new room(8, "Honeydew Melon", "Salty grass with honey on top", ":/honeydew melon.jfif");
    i = new room(9, "Indian prune", " Red mini apples", ":/indian prune.jfif");
    j = new room(10, "Jalapeno", " Very very hot and painful. 10/10 would eat again", ":/jalapeno.jfif");


//             (N, E, S, W)
    a->setExits(b, c, d, e);
    b->setExits(f, NULL, a, NULL);
    c->setExits(NULL, NULL, i, a);
    d->setExits(a, NULL, h, NULL);
    e->setExits(NULL, a, NULL, NULL);
    f->setExits(NULL, NULL, b, g);
    g->setExits(j, f, NULL, NULL);
    h->setExits(d, NULL, NULL, NULL);
    i->setExits(c, NULL, NULL, NULL);
    j->setExits(NULL, NULL, g, NULL);

    currentRoom = a;
}

void MainWindow::printWelcome() {

    mainText = "Hello Welcome\n" + currentRoom->longDescription();
    mainImage = currentRoom->getImage();
    image = QPixmap(mainImage).scaled(ui->imageBox->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->imageBox->setPixmap(image);
    ui->textBox->setText(mainText);
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */

bool MainWindow::processCommand(int buttonNumber) {

    if (buttonNumber == 4){
        //map
        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Map");
        newWin->setGeometry(500,200,400,400);

        QLabel *map = new QLabel();
        map->setStyleSheet("QLabel { background-color : white; }");

        layout->addWidget(map);
        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(layout);
        newWin->show();

    } else if (buttonNumber == 5){
        //bag
        itemsInBag = getBagItems();

        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Bag");
        newWin->setGeometry(500,400,200,200);

        int x = getBagItems().size();

        QLabel *bag = new QLabel();
        bag->setStyleSheet("QLabel { background-color : white; }");

        QString itemsList;

        if (x != 0){
            for (int i = 0; i < x; i++){
                itemsList = itemsList + itemsInBag[i].getLongDescription() + "\n" ;
            }
            bag->setText(itemsList);
        } else {
            bag->setText("Bag Empty ");
        }

        layout->addWidget(bag);
        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(layout);
        newWin->show();



    } else if (buttonNumber == 6){
        //take  button
        mainText = currentRoom->longDescription();
        ui->textBox->setText(mainText);

        itemsInRoom = currentRoom->getItemsArray();
        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Items");
        newWin->setGeometry(500,400,200,200);

        int x = currentRoom->numberOfItems();

        for (int i = 0; i < x; i++){
            QPushButton *Button = new QPushButton();

            connect(Button, &QPushButton::clicked, [=]() {
                addToBag(itemsInRoom[i]);
                currentRoom-> removeItem(i);
                ui->textBox->setText(mainText + "\nYou took " + itemsInRoom[i].getShortDescription());
                newWin->hide();
            });

            Button->setText(itemsInRoom[i].getShortDescription());
            Button->setObjectName("Button" + QString::number(i));

            layout->addWidget(Button);

        }
        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(layout);
        newWin->show();

    } else if (buttonNumber == 7){
        //put item
        mainText = currentRoom->longDescription();
        ui->textBox->setText(mainText);

        itemsInBag = getBagItems();

        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Items");
        newWin->setGeometry(500,400,200,200);

        int x = itemsInBag.size();

        for (int i = 0; i < x; i++){
            QPushButton *Button = new QPushButton();

            connect(Button, &QPushButton::clicked, [=]() {
                currentRoom->addItemFromBag(itemsInBag[i]);
                removeItem(i);
                ui->textBox->setText(mainText + "\nYou dropped " + itemsInBag[i].getShortDescription());
                newWin->hide();
            });

            Button->setText(itemsInRoom[i].getShortDescription());
            Button->setObjectName("Button" + QString::number(i));

            layout->addWidget(Button);

        }
        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(layout);
        newWin->show();
    }

    return false;
}

/** COMMANDS **/

void MainWindow::go(string direction) {
    room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
        ui->errorLabel->setText("No room this way");
        ui->errorLabel->setStyleSheet("background-color:white");
        QTimer::singleShot(0, ui->errorLabel, &QLabel::show);
        QTimer::singleShot(3000, ui->errorLabel, &QLabel::hide);

    } else {
        currentRoom = nextRoom;
        mainText = currentRoom->longDescription();
        mainImage = currentRoom->getImage();
        image = QPixmap(mainImage).scaled(ui->imageBox->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->imageBox->setPixmap(image);
        ui->textBox->setText(mainText);
    }

}

void MainWindow::addToBag(Item item){
    if (itemsInBag.size() <= 5){
        itemsInBag.push_back(item);
    }
}

vector <Item> MainWindow::getBagItems(){
    return itemsInBag;
}

void MainWindow::removeItem(int placeNum){
    itemsInBag.erase(itemsInBag.begin() + placeNum);
}

/** Buttons **/

void MainWindow::on_North_clicked(){
    go("north");
}

void MainWindow::on_East_clicked(){
    go("east");
}

void MainWindow::on_South_clicked(){
    go("south");
}

void MainWindow::on_West_clicked(){
    go("west");
}
void MainWindow::on_map_clicked(){
    processCommand(4);
}
void MainWindow::on_bag_clicked(){
    processCommand(5);
}

void MainWindow::on_take_clicked(){
    processCommand(6);
}

void MainWindow::on_put_clicked(){
    processCommand(7);
}

void MainWindow::on_actionHow_To_Play_triggered(){

    QWidget *wid=new QWidget();
    QVBoxLayout *layout=new QVBoxLayout();
    wid->setWindowTitle("How To Play");
    wid->setGeometry(500,400,200,200);

    QLabel *howTo = new QLabel();
    howTo->setStyleSheet("QLabel { background-color : white; }");
    howTo->setText("Welcome to our Zork.\nThe rules are simple enough, just use the buttons on screen to try and get yourself out of the zombie apocalypse.");
    howTo->setWordWrap(true);

    layout->addWidget(howTo);

    wid->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    wid->setLayout(layout);
    wid->show();

}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}
