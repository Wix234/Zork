#include "mainwindow.h"
#include "ui_mainwindow.h"

//add background color to popup windows
//add font to pop up windows with QLabels

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

    //add weight/size to items
    //add outside

    s = new room('s', 0, "The glass wall behind you is illluminating the main entrance of the building. There is two staircases, one to your left the other to your right. "
                            "They both lead to hallway 3. You never knew why they did two instead of once centre one, maybe "
                            " it was to have people walk up one way and walk down the other way. Infront of you is the main lecture hall of the building, the Jean Monnet, also know as room 1. There a two potted plants "
                            ", one on each side of the door. Behind you is the main exit to the building, unfortunately it's locked.",
                            "Exits: North leads outside [locked]. South is room 1. West and East both lead to hallway 3 [floor 2].", true);
        //Can't be put in bag
        s->addItem(new Item("Plant 1", "A small looking palm tree in a pot. About a meter tall."));
        //can't be put in bag
        //plant 2 can be watered have a water bottle in your bag. The water makes a bloop bloop sound as it comes out of the bottle
        s->addItem(new Item("Plant 2", "A small looking palm tree in a pot. About a meter tall. It looks a bit wilted."));

    r1 = new room('r', 1, "The main lecture hall in the builing. As you walking in you see 200 red seats facing you. You remember how stressful it was to give presentations infront of everyone. To your right is "
                            "room 6. You know it as the Games Soc room. To your left is hallway 1. On the back back wall you notice theres is a letter O written in blue marker.",
                            "North is room s0. West is hallway 1. East is room 6 [locked]. ",false);
        //can't be put in bag
        //When you ride the chair you fall and undearneath the chair is revealed the letter N
        r1->addItem(new Item("Desk Chair","A desk chair with wheels."));

    r2 = new room('r', 2, "As you enter the room you see a nice view of the little garden, the weather looks great to just go out and have a picnic. The room itself is fairly empty just a few couches that"
                            " students used to take up. On the couch there is a sticky note. To your left is an elevator however it appears as if the power isn't working. Seeing as its so nice outside you "
                            "didn't notice that all the lights aren't working.",
                            "Exits: North is hallway 1.",false);
        r2->addItem(new Item("Sticky note","There's a letter O written on it."));

    r3 = new room('r', 3, "Room 3 is an empty classroom, as you enter it you are met with empty desks and chairs. Written on the white board is stay at 127.0.0.1 wear a 255.255.255.0, "
                            "guess a comp sci student was here before lockdown. There appears to be a pink fluffy pencil case left on one of the desks.",
                            "Exits: East is hallway 1.", false);
        //if you open the pencil case there is a letter M written on a sticky note
        r3->addItem(new Item("Fluffy Pencilcase ", "The fluffy pink pencilcase appears to be full of stationary to a point where there is a little whole starting to tear at the seam of the zip."));

    r4 = new room('r', 4, "The smell of saw dust and wood, hits you as you walk into room 4. All the tools are neatly put away in their proper places. It's shame that the power isn't working you were alway interested in"
                            " trying to use some of them. Actually thinking about it maybe it's better that way, you could hurt yourself or accidentally burn the building down. There are a few unfinished "
                            "projects left around the room on the desk tops. At the back of the room there is a door with a staircase behind it. The stairs lead to hallway 4.",
                            "Exits: North is stairs to hallway 4 [floor 2]. South is hallway 1.", false);
        //Can't be put in bag
        //Can be powered on if the power is working
        r4->addItem(new Item("Drill", "It a blue drill by some good brand. There is no drill bits in it though. It's locked to the wall by an extenable wire"));
        //Can't be put in bag
        //You get a splinter if you pick it up but it also reveals the letter E on its underside
        r4->addItem(new Item("Project", "It looks like a silloutte of a guitar. The edges appear to be rough and not sanded down."));
        //Can't be put in bag
        //If you try to pick it you change you mind because it looks sharp
        r4->addItem(new Item("Saw", "The blade looks very sharp and dangerous."));
        r4->addItem(new Item("Sandpaper", "Its rough just like being on 3 hours of sleep and 4 coffees."));

    r5 = new room('r', 5, "The room is an empty office admin looking room. There's a stack of student guidebooks and handbooks in the left corner of the room. There is also some UL merch, propabaly left over from an open "
                            "day. Most of the drawers and cupboards are locked shut however there is one drawer left open with a silver key in it.",
                            "Exits: North is stairs to hallway 5 [floor 2] ", false);
         r5->addItem(new Item("Silver Key", "A small silver key. It has a tag with number 6 written on it."));
         r5->addItem(new Item("Student Guidebook", "It has some basic information about the buildings, an FAQ with questions regarding admin things such as fees, accommodation. It also has contact information for year heads"
                            " and fees office etc."));
         //if you open it the letter L is written inside the cover with blue marker
         r5->addItem(new Item("Student Handbook", "Outlines the rules of conduct in UL."));

    r6 = new room('r', 6, "Room 6 is a large open room. You originally remember it from the open day when you went back in 6th year of secondary school. This is where you found the stall for computer science."
                            " A more later mememory of the room would be back in 1st year of college when you played DND for the first time. The room was buzzing with Games Soc members all trying to set up their "
                            "board games, campaigns and or views just standing around and watching the games unfold. As you look around you notice a blue dice on the ground by the large wall of windows."
                            " South is room 6.3 the room you used sit in every Monday evening for four hours to play DND with your friends. East is a door leading to hallway 2.",
                            "Exits: North are stairs to room 9 [floor 2]. South is an open door to room 6.3. West is room 1. East is hallway 2.", true);
        //you can roll the dice and see what you get
        r6->addItem(new Item("1d4 Blue Dice", "Its a pyramid shaped dice. Its main color is blue and the numbers are painted on with white However the number 1 is tipex over with to make it look like an A."));

    r6_3 = new room('r', 6.3, "The nostaligia hits you as you enter the small room. The memories of fighting dire wolfs, golblins, spending too much gold bits on beer after a successful adventure all flood your mind. "
                            "To describe the room - there is 2 large desks in the centre forming a small looking dinner table. There are 2 chairs on each side of the table. To the right is a clean white board. "
                            "There is 2 markers on the little shelf, a blue and a red one.",
                            "Exits: North is room 6.",false);
        //not visible until blue marker picked up
        r6_3->addItem(new Item("Gold key", "Its a small gold key with a tag on it. The tag has s written on it"));
        //when you pick up the blue marker the cap drops under the table and you notice the gold key
        r6_3->addItem(new Item("Blue Marker", "It's a white boards marker thats blue."));
        //dried out so can't write
        r6_3->addItem(new Item("Red Marker", "It's a white boards marker thats red."));

    r7 = new room('r', 7, "Another lecture theatre this one is much smaller and looks like a classroom with extra seats. It has a blackboard which is rare to see since a lot of the other classroom and lecture halls use"
                            " whiteboards with projectors. You notice there is a maths book for discrete mathematics left on the lecturer's desk.",
                            "Exits: North is hallway 3. East is hallway 6 and west is hallway 4.", false);
        //there is bookmarked page. When opened there is a graph in the shape of a letter N
        r7->addItem(new Item("Maths book", "Discrete Mathematics: An Open Introduction by Oscar Levin."));

    r8 = new room('r', 8, "Room 8 is another empty classroom. This time all the chairs are stacked up against the left wall and the desks as all next to each other against the back wall. "
                            " "
                            "guess a comp sci student was here before lockdown. There appears to be a pink fluffy pencil case left on one of the desks.",
                            "Exits: North hallway 4", false);
    r9 = new room('r', 9, "h4, NULL, NULL, NULL",
                                    "Exits: North is stairs to room 6. South is room 10. East is hallway 7.", false);
    r10 = new room('r', 10, "r9, NULL, 12, NULL",
                                    "Exits: North is room 9.", true);

    h1 = new room('h', 1, "A short hallway with a door on each wall",
                            "Exits: North is room 4. South is room 2. West is room 3. East is room 1.", false);
    h2 = new room('h', 2, "It's just a small stairwell leading to hallway 7.",
                            "Exits: North is hallway 7 [floor 2]. West is room 6.", false);
    h3 = new room('h', 3, "The glass wall from the room below extends to this level. There is a small balcony space allowing you to look down onto room S. Infront of the balcony wall there is a few couches.",
                            "Exits: East and West both lead to room S [floor 1]. South leads to room 7. ", false);
    h4 = new room('h', 4, "It's a long L shaped hallway. There are stairs leading to room 4 at one end of it. At the other end is the door to room 7. Door to hallway 5 is across from the door to room 7. "
                            "Stairs to room 4 are across from the door to room 8 ",
                            "Exits: North is room 4 [floor1]. South is room 8. West is hallway 5. East is room 7.", false);
    h5 = new room('h', 5, "Another L shaped. At one end of the L are the stairs down to room 5",
                            "Exits: East is hallway 4. South are stairs leading to room 5 [floor 1].", false);
    h6 = new room('h', 6, "A small dead end hallway. It's filled with a bunch of sealed boxes and some spare desks and chairs.",
                            "Exits: West is room 7", false);
    h7 = new room('h', 7, "It's just a small stairwell leading to hallway 2.",
                            "Exits: North is hallway 2 [floor 1].", false);
//             (N, E, S, W)
    //a->setExits(b, c, d, e);
    s->setExits(NULL, h3, r1, h3);
    r1->setExits(s, r6, NULL, h1);
    r2->setExits(h1, h19, NULL, NULL);
    r3->setExits(NULL, h1, NULL, NULL);
    r4->setExits(h4, NULL, h1, NULL);
    r5->setExits(h5, NULL, NULL, NULL);
    r6->setExits(r9, h2, r6_3, r1);
    r6_3->setExits(r6, NULL, NULL, NULL);
    r7->setExits(h3, h6, NULL, h4);
    r8->setExits(h4, NULL, NULL, NULL);
    r9->setExits(r6, h7, r10, NULL);
    r10->setExits(r9, NULL, NULL, NULL);

    h1->setExits(r4, r1, r2, r3);
    h2->setExits(h7, NULL, NULL, r6);
    h3->setExits(NULL, s, r7, s);
    h4->setExits(r4, r7, r8, h5);
    h5->setExits(NULL, h4, r5, NULL);
    h6->setExits(NULL, NULL, NULL, r7);
    h7->setExits(h2, NULL, NULL, r9);

    currentRoom = s;
}

void MainWindow::printWelcome() {

    mainText = "Hello Welcome\n" + currentRoom->longDescription();
    itemText = currentRoom->displayItem();

    ui-> mainBox->setWordWrap(true);
    ui->mainBox->setText(mainText);

    ui-> itemTextBox->setWordWrap(true);
    ui->itemTextBox->setText(itemText);
    QTimer::singleShot(0, ui->errorLabel, &QLabel::hide);

    //change map to fit new layout
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

            connect(Button, &QPushButton::clicked, this, [=] {
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
        itemText = currentRoom->displayItem();
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);

        itemsInRoom = currentRoom->getItemsArray();
        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Items");
        newWin->setGeometry(500,400,200,200);

        int x = currentRoom->numberOfItems();

        if (getBagItems().size() < 5 ){
            for (int i = 0; i < x; i++){
                QPushButton *Button = new QPushButton();

                connect(Button, &QPushButton::clicked, this, [=]() {
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

        } else {
            ui->errorLabel->setText("No space in bag. Put something down first. " );
            ui->errorLabel->setWordWrap(true);
            QTimer::singleShot(0, ui->errorLabel, &QLabel::show);
            QTimer::singleShot(3000, ui->errorLabel, &QLabel::hide);
        }

    } else if (buttonNumber == 7){
        //put item
        mainText = currentRoom->longDescription();
        ui->mainBox->setText(mainText);
        itemText = currentRoom->displayItem();
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);

        itemsInBag = getBagItems();

        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Items");
        newWin->setGeometry(500,400,200,200);

        int x = itemsInBag.size();

        for (int i = 0; i < x; i++){
            QPushButton *Button = new QPushButton();

            connect(Button, &QPushButton::clicked, this, [=]() {
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

    } else if (buttonNumber == 8){
    //inspect item
        mainText = currentRoom->longDescription();
        ui->mainBox->setText(mainText);
        itemText = currentRoom->displayItem();
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);

        itemsInRoom = currentRoom->getItemsArray();
        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Inspect");
        newWin->setGeometry(500,400,200,200);

        int x = currentRoom->numberOfItems();

        for (int i = 0; i < x; i++){
            QPushButton *Button = new QPushButton();

            connect(Button, &QPushButton::clicked, this, [=]() {
                QWidget *newWin2 = new QWidget();
                newWin2->setStyleSheet("QWidget { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 0, 255));}");
                QVBoxLayout *layout2 = new QVBoxLayout();
                newWin2->setGeometry(500,400,200,200);
                newWin2 -> setWindowTitle(itemsInRoom[i].getShortDescription());
                QLabel *label = new QLabel();
                label->setStyleSheet("QLabel { background-color : white; }");

                label -> setText(itemsInRoom[i].getLongDescription());

                layout2 -> addWidget(label);
                newWin2->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
                newWin2->setLayout(layout2);
                newWin2->show();
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
        QTimer::singleShot(0, ui->errorLabel, &QLabel::show);
        QTimer::singleShot(3000, ui->errorLabel, &QLabel::hide);

    } else if(nextRoom->isRequired() == true) {
        mainText = currentRoom->longDescription();
        itemText = currentRoom->displayItem();
        ui->errorLabel->setText("You need a key");
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);
        int x = getBagItems().size();
        for(int i = 0; i < x; i++){
            if (itemsInBag[i].getShortDescription() == "Silver Key"){
                 removeItem(i);
                 nextRoom->setRequired(false);
                ui->mainBox->setText(mainText + "\nDoor unlocked you can open it now.");
            }
        }

    } else {
        currentRoom = nextRoom;
        mainText = currentRoom->longDescription();
        itemText = currentRoom->displayItem();

        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);
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

void MainWindow::on_inspect_clicked(){
    processCommand(8);
}

void MainWindow::on_actionHow_To_Play_triggered(){

    QWidget *wid=new QWidget();
    QVBoxLayout *layout=new QVBoxLayout();
    wid->setWindowTitle("How To Play");
    wid->setGeometry(500,400,200,200);

    QLabel *howTo = new QLabel();
    howTo->setStyleSheet("QLabel { background-color : white; }");
    howTo->setText("Welcome to our Zork.\nThe rules are simple enough, just use the buttons on screen to move around the building.");
    howTo->setWordWrap(true);

    layout->addWidget(howTo);

    wid->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    wid->setLayout(layout);
    wid->show();

}

void MainWindow::on_actionQuit_triggered(){
    exit(0);
}

