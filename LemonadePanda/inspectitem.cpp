#include "inspectitem.h"


inspectitem::inspectitem(){

}

QString inspectitem::ifStatementsForItems(vector<Item*> itemsInBag, room *currentRoom, Item *item){
    if (item->getName() == "Plant 2" ){
        int x = itemsInBag.size();
        for(int i = 0; i < x; i++){
            if (itemsInBag[i]->getName() == "Water Bottle" && itemsInBag[i]->getDescription() == "Full water bottle."){
                currentRoom->setRequired(false);
                currentRoom->setDescription("The glass wall behind you is illluminating the main entrance of the building. There is two staircases, one to your left the other to your right. "
                            "They both lead to hallway 3. You never knew why they did two instead of once centre one, maybe "
                            " it was to have people walk up one way and walk down the other way. Infront of you is the main lecture hall of the building, the Jean Monnet, also know as room 1. There a two potted plants "
                            ", one on each side of the door. Behind you is the main exit to the building, unfortunately it's locked.");
                item->setDescription("A small looking palm tree in a pot. About a meter tall. It was watered recently.");
                itemsInBag[i]->setDescription("The water bottle is empty.");
                return "\nThe water makes a bloop bloop sound as it leaves the bottle.";
            }else{
                return "\nThe water bottle is empty.";
            }
        }
    } else  if (item->getName() == "Desk Chair" ){
        currentRoom->setDescription("The main lecture hall in the builing. As you walking in you see 200 red seats facing you. There desk chair is now in the corner on it's side."
                            " You remember how stressful it was to give presentations infront of everyone. To your right is "
                            "room 6. You know it as the Games Soc room. To your left is hallway 1.");
        item->setDescription("A desk chair with wheels laying on it's side. The letter N is written under neat it.");
        return "\nYou decided to ride the chair. You fall and underneath the chair is revealed the letter N";
    } else  if (item->getName() == "Fluffy Pencilcase" ){
        return "\nif you open the pencil case there is a letter M written on a sticky note";
    } else  if (item->getName() == "Drill" ){
        return "\nCan be powered on if the power is working";
    } else  if (item->getName()== "Project" ){
        return "\nYou get a splinter if you pick it up but it also reveals the letter E on its underside";
    } else  if (item->getName() == "Saw" ){
        return "\nIf you try to pick it you change you mind because it looks sharp";
    } else  if (item->getName() == "Student Handbook" ){
        return "\nif you open it the letter L is written inside the cover with blue marker";
    } else  if (item->getName()== "1d4 Blue Dice" ){
        return "\nyou can roll the dice and see what you get";
    } else  if (item->getName() == "Blue Marker" ){
    return "\nwhen you pick up the blue marker the cap drops under the table and you notice the gold key";
    } else  if (item->getName() == "Red Marker" ){
        return "\ndried out so it can't write";
    } else  if (item->getName() == "Maths book" ){
        return "\nthere is bookmarked page. When opened there is a graph in the shape of a letter N";
    }
    return "\nNothing else to see.";
}

/*if(nextRoom->isRequired() == true) {
        mainText = currentRoom->longDescription();
        itemText = currentRoom->displayItem();
        ui->errorLabel->setText("You need a key");
        ui-> itemTextBox->setWordWrap(true);
        ui->itemTextBox->setText(itemText);
        int x = getBagItems().size();
        for(int i = 0; i < x; i++){
            if (itemsInBag[i].getName() == "Silver Key"){
                 removeItem(i);
                 nextRoom->setRequired(false);
                ui->mainBox->setText(mainText + "\nDoor unlocked you can open it now.");
            }
        }

bool inspectitem::ifStatementsForItems(Item item){
    if (item.getShortDescription() == "Plant 2" ){
        return "\nThe water makes a bloop bloop sound as it leaves the bottle.";
    }*/
