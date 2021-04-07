#include "inspectItems.h"
#

inspectItems::inspectItems(){

}


void inspectItems::ifStatementsForItems(room currentRoom, Item items){
    if (currentRoom.shortDescription() == "r1" && items.getShortDescription() == "Plant 1" ){
        QLabel *lable = new QLabel;
        lable->setText("bloop boop bloop");
    }

}
