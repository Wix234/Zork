#include "inspectitem.h"


inspectitem::inspectitem(){

}

void inspectitem::ifStatementsForItems(QString itemName){
    if (itemName == "Plant 1" ){
        newWin = new QWidget();
        layout = new QVBoxLayout();
        newWin->setWindowTitle("Map");
        newWin->setStyleSheet(winBg);
        newWin->setGeometry(900,400,200,200);

        QLabel *text = new QLabel();
        text->setStyleSheet(lblBg);
        text->setWordWrap(true);
        text->setText("Water goes bloop bloop bloop.");
        layout->addWidget(text);


        newWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        newWin->setLayout(layout);
        newWin->show();
    }

}
