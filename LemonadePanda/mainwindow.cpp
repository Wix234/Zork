#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow){

    ui -> setupUi(this);
    createRooms();
    printWelcome();
    ui-> mainBox->setWordWrap(true);
    ui->mainBox->setText(mainText);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::createRooms()  {


    s = new room('s', 0, "The glass wall behind you is eluminating the main entrance of the building. There is two staircases, one to your left the other to your right. "
                            "They both lead to hallway 3. You never knew why they did two instead of once centre one, maybe "
                            " it was to have people walk up one way and walk down the other way. Infront of you is the main lecture hall of the building, the Jean Monnet, also know as room 1. "
                            "Behind you is the main exit to the building, unfortunately it's locked with a 10 letter passkey. Maybe if you look around you'll see it written down somewhere", false);
    r1 = new room('r', 1, "The main lecture hall in the builing. As you walking in you see 200 red seats facing you. You remember how stressful it was to give presentations infront of everyone. To your right is "
                            "room 6. You know it as the Games Soc room. To your left is hallway 1. On the back back wall you notice theres is a letter O written in blue marker.", false);
        r1->addItem(new Item("letter o", "its a letter", false, NULL));
    r2 = new room('r', 2, "As you enter the room you see a nice view of the little garden, the weather looks great to just go out and have a picnic. The room itself is fairly empty just a few couches that"
                            " students used to take up. To your left is an elevator however it appears as if the power isn't working. Seeing as its so nice outside you didn't notice that all the lights aren't working.", false);
    r3 = new room('r', 3, "Room 3 is an empty, as you enter it you are met with empty desk and chairs. Written on the white board is stay at 127.0.0.1 wear a 255.255.255.0, guess a comp sci student was here before lockdown. "
                            "On the wall infront of you, you notice another letter written in blue marker. Maybe you should start taking them down and see what it spells??", false);
        r3->addItem(new Item("letter a", "its a letter", false, NULL));
    r4 = new room('r', 4, "The smell of saw dust and wood, hits you as you walk into room 4. There are a few unfinished projects left around the room on the desk tops. At the back of the room there is a door with a staircase "
                            " behind it. The stairs lead to hallway 4.", false);
    r5 = new room('r', 5, "h5, NULL, NULL, NULL", false);
         r5->addItem(new Item("key1", "key", false, NULL));
    r6 = new room('r', 6, "r9, h2, r6_3, r1", false);
    r7 = new room('r', 7, "h3, h6, NULL, h4", false);
    r8 = new room('r', 8, "h4, NULL, NULL, NULL", false);
    r9 = new room('r', 9, "h4, NULL, NULL, NULL", false);
    r10 = new room('r', 10, "r9, NULL, NULL /*12*/, NULL", false);
    r11 = new room('r', 11, "h10, NULL/*secret*/, NULL, NULL", false);
    h1 = new room('h', 1, "r4, r1, r2, r3", false);
    h2 = new room('h', 2, "h7, NULL, NULL, r6", false);
    h3 = new room('h', 3, "NULL, s, r7, s", false);
    h4 = new room('h', 4, "r4, r7, r8, h5", false);
    h5 = new room('h', 5, "NULL, h4, r5, NULL", false);
    h6 = new room('h', 6, "NULL, NULL, NULL, r7", false);
    h7 = new room('h', 7, "h2, NULL/*h11*/, NULL, r9", false);
    h8 = new room('h', 8, "NULL/*15*/, h10, NULL, NULL/*14*/", false);
    h9 = new room('h', 9, "NULL/*23*/, NULL, NULL, NULL", false);
    h10 = new room('h', 10, "h8, NULL/*h15*/, r11, NULL/*h15*/", false);
    r6_3 = new room('r', 6.3, "r6, NULL, NULL, NULL", false);
        r6_3->addItem(new Item("key1", "key", false, NULL, false));
    
    h11 = new room ('h', 11, "There is a staircase north, leading downn to hallway 7, To your left there is a door to room 12.", false);
    r12 = new room ('r', 12, "There is a staircase south, leading you to room 10. There is hallway 12 to your left, and hallway 11 to your right. Hallway 11 has a staircase leading down to hallway 7.", false);
    h12 = new room ('h', 12, "North is room 13, To your right is room 12 and to your left is hallway 13.", false);
    h13 = new room ('h', 13, "To your right is hallway 12 and to your left is hallway 14.", false);
    h14 = new room ('h', 14, "To your right is hallway 13 and to your left is room 14.", false);
    r14 = new room ('r', 14, "To your right there is hallway 14, south is a staircase leading to hallway 8. North you can see another staircase leading to a room but there is no access to the staircase from this room.", false);
    r15 = new room ('r', 15, "To the right is a staircase leading to hallway 8.", false);
    h21 = new room ('h', 21, "North is a staircase leading to hallway 23. South is a staircase leading to hallway 9 which has the exit to stables.", false);
    h15 = new room ('h', 15, "Right is an elevator that goes to up to hallway 24, if you take north, and down to hallway 10. To your left are stairs that lead to up to hallway 24 and down to hallway 10. South leadss to hallway 17.", false);
    h17 = new room ('h', 17, "North leads to hallway 15. To your right, at the end of the hallway, you can see another staircase to the right and a room south, but they aren't acessble as there is some construction blocking your way.", false);
    h16 = new room ('h', 16, "To your right is a staircase leading to hallway 25. South is room 16. To your left is the rest of the hallway but it's blocked with construction, however you can see a door north of the hallway.", false);
    r16 = new room ('r', 16, "North is teh exit to halway 16.", false);
    h18 = new room ('h', 18, "North is room 17. To your right is hallway 19.", false);
    h19 = new room ('h', 19, "North is room 18. To your left is room 20. South is elevator to room 2.", false);
    r20 = new room ('r', 20, "North is hallway 20. South is hallway 22. To your right is hallway 19.", false);
    h20 = new room ('h', 20, "South is room 20.", false);
    h22 = new room ('h', 20, "North is room 20. To the right is room 21. South is room 24.", false);
    r21 = new room ('r', 21, "North is room 22. South is room 23.", false);
    r22 = new room ('r', 22, "South is room 21.", false);
    r23 = new room ('r', 23, "North is room 21.", false);
    r24 = new room ('r', 24, "North is hallway 22. Left is hallway 23. South is room 25.", false);
    h23 = new room ('h', 23, "North is a staircase that takes you to hallway 21. South is room 27.", false);
    r27 = new room ('r', 27, "North is hallway 23.", false);
    r25 = new room ('r', 25, "North is room 24. South is hallway 24.", false);
    h24 = new room ('h', 24, "Left is a staircase to hallway 15. Right is an elevator to hallway 15. North is room 25. South is hallway 25.", false);
    h25 = new room ('h', 25, "North is hallway 24. South is room 26. To the right as the end of the hallway is a staircase that leads to hallway to 16.", false);
    r26 = new room ('r', 26, "North is hallway 25.", false);




//             (N, E, S, W)
    //a->setExits(b, c, d, e);
    s->setExits(NULL, h3, r1, h3);
    r1->setExits(s, r6, NULL, h1);
    r2->setExits(h1, h19, NULL, NULL);
    r3->setExits(NULL, h1, NULL, NULL);
    r4->setExits(h4, NULL, h1, NULL);
    r5->setExits(h5, NULL, NULL, NULL);
    r6->setExits(r9, h2, r6_3, r1);
    r7->setExits(h3, h6, NULL, h4);
    r8->setExits(h4, NULL, NULL, NULL);
    r9->setExits(r6, h7, r10, NULL);
    r10->setExits(r9, NULL, r12, NULL);
    r11->setExits(h10, NULL/*secret*/, NULL, NULL);
    h1->setExits(r4, r1, r2, r3);
    h2->setExits(h7, NULL, NULL, r6);
    h3->setExits(NULL, s, r7, s);
    h4->setExits(r4, r7, r8, h5);
    h5->setExits(NULL, h4, r5, NULL);
    h6->setExits(NULL, NULL, NULL, r7);
    h7->setExits(h2, h11, NULL, r9);
    h8->setExits(r15, h10, NULL, r14);
    h9->setExits(r23, NULL, NULL, NULL);
    h10->setExits(h8, h15, r11, h15);
    r6_3->setExits(r6, NULL, NULL, NULL);

    h11 -> setExits(h7, NULL, NULL, r12);
    r12 -> setExits(NULL, h11, r10, h12);
    h12 -> setExits(r13, r12, NULL, h13);
    h13 -> setExits(NULL, h12, NULL, h14);
    h14 -> setExits(NULL, h13, NULL, r14);
    r14 -> setExits(NULL, h14, h8, NULL);
    r15 -> setExits(NULL, NULL, NULL, h8);
    h21 -> setExits(h23, NULL, h9, NULL);
    h15 -> setExits(h24, h10, h17, h10);
    h17 -> setExits(h15, NULL, NULL, NULL);
    h16 -> setExits(NULL, h25, r16, NULL);
    r16 -> setExits(h16, NULL, NULL, NULL);
    h18 -> setExits(r17, NULL, NULL, h19);
    h19 -> setExits(r18, h18, r2, r20);
    r20 -> setExits(h20, h19, h22, NULL);
    h20 -> setExits(NULL, NULL, r20, NULL);
    h22 -> setExits(r20, NULL, r24, r21);
    r21 -> setExits(r22, h22, r23, NULL);
    r22 -> setExits(NULL, NULL, r21, NULL);
    r23 -> setExits(r21, NULL, NULL, NULL);
    r24 -> setExits(h22, NULL, r25, h23);
    h23 -> setExits(h21, r24, r27, NULL);
    r27 -> setExits(h23, NULL, NULL, NULL);
    r25 -> setExits(r24, NULL, h24, NULL);
    h24 -> setExits(r25, h15, h25, h15);
    h25 -> setExits(h24, h16, r26, NULL);
    r26 -> setExits(h25, NULL, NULL, NULL);

    currentRoom = s;
}

void MainWindow::printWelcome() {

    mainText = "Hello Welcome\n" + currentRoom->longDescription();
    itemText = currentRoom->displayItem();
    //mainImage = currentRoom->getImage();
    //image = QPixmap(mainImage).scaled(ui->imageBox->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //ui->imageBox->setPixmap(image);

    ui-> mainBox->setWordWrap(true);
    ui->mainBox->setText(mainText);

    ui-> itemTextBox->setWordWrap(true);
    ui->itemTextBox->setText(itemText);

    mapImages.push_back(":/floor1.jpg");
    mapImages.push_back(":/floor2.jpg");
    mapImages.push_back(":/floor3.jpg");
    mapImages.push_back(":/floor4.jpg");
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
        glayout = new QGridLayout();
        newWin->setWindowTitle("Map");
        newWin->setGeometry(300,200,600,500);

        QLabel *map = new QLabel();
        map->setStyleSheet("QLabel { background-color : white; }");
        int x = mapImages.size();

        for (int i = 0; i < x; i++){
            QPushButton *Button = new QPushButton();

            connect(Button, &QPushButton::clicked, [=]() {
                image = QPixmap(mapImages[i]).scaled(map->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                map->setPixmap(image);
            });

            Button->setText("Floor" + QString::number(i + 1));
            Button->setObjectName("Button" + QString::number(i));

            glayout->addWidget(Button, 0, i);

        }

        glayout->addWidget(map, 5, 0, 5, 0);
        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(glayout);
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
        ui->mainBox->setText(mainText);

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
                ui->mainBox->setText(mainText + "\nYou took " + itemsInRoom[i].getShortDescription());
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
        ui->mainBox->setText(mainText);

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
                ui->mainBox->setText(mainText + "\nYou dropped " + itemsInBag[i].getShortDescription());
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
        
    } else if(nextRoom->isRequired() == true) {
        mainText = currentRoom->longDescription();
        ui->textBox->setText(mainText +"\nYou need a key");
        int x = getBagItems().size();
        for(int i; i < x; i++){
            if (itemsInBag[i].getShortDescription() == "key1"){
                 removeItem(i);
                 nextRoom->setRequired(false);
                ui->textBox->setText(mainText + "\nDoor unlocked you can open it now.");
            }
        }

    } else {
        currentRoom = nextRoom;
        mainText = currentRoom->longDescription();
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);
        //mainImage = currentRoom->getImage();
        //image = QPixmap(mainImage).scaled(ui->imageBox->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        //ui->imageBox->setPixmap(image);
        ui-> mainBox->setWordWrap(true);
        ui->mainBox->setText(mainText);
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
