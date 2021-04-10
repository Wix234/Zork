#include "inspectitem.h"


inspectitem::inspectitem(){

}

QString inspectitem::ifStatementsForItems(Item item){
    if (item.getShortDescription() == "Plant 2" ){
        return "\nThe water makes a bloop bloop sound as it leaves the bottle.";
    } else  if (item.getShortDescription() == "Desk Chair" ){
        return "\nWhen you ride the chair you fall and undearneath the chair is revealed the letter N";
    } else  if (item.getShortDescription() == "Fluffy Pencilcase" ){
        return "\nif you open the pencil case there is a letter M written on a sticky note";
    } else  if (item.getShortDescription() == "Drill" ){
        return "\nCan be powered on if the power is working";
    } else  if (item.getShortDescription() == "Project" ){
        return "\nYou get a splinter if you pick it up but it also reveals the letter E on its underside";
    } else  if (item.getShortDescription() == "Saw" ){
        return "\nIf you try to pick it you change you mind because it looks sharp";
    } else  if (item.getShortDescription() == "Student Handbook" ){
        return "\nif you open it the letter L is written inside the cover with blue marker";
    } else  if (item.getShortDescription() == "1d4 Blue Dice" ){
        return "\nyou can roll the dice and see what you get";
    } else  if (item.getShortDescription() == "Blue Marker" ){
    return "\nwhen you pick up the blue marker the cap drops under the table and you notice the gold key";
    } else  if (item.getShortDescription() == "Red Marker" ){
        return "\ndried out so it can't write";
    } else  if (item.getShortDescription() == "Maths book" ){
        return "\nthere is bookmarked page. When opened there is a graph in the shape of a letter N";
    }
    return "\nNothing else to see.";
}

/*bool inspectitem::ifStatementsForItems(Item item){
    if (item.getShortDescription() == "Plant 2" ){
        return "\nThe water makes a bloop bloop sound as it leaves the bottle.";
    }*/
