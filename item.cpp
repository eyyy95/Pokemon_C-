/*********************************************************************
** Program name: Source file for Item Object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for our object, which will serve as the individual data points in our linked-list item Container structure
*********************************************************************/
#include"item.hpp"

Item::Item()
{
    itemName = " "; //name will identify what type of item the object is
    next = nullptr; //initialize next pointer to null
}

Item::Item(string inputName) //overloaded constructor that accepts string parameter and creates object with parameter as name
{
    itemName = inputName;
}

void Item::setNext(Item* nextItem) //modifier function for the next pointer of individual item
{
    next = nextItem;
}

Item* Item::getNext() //accessor function for next pointer of individual item
{
    return next;
}
