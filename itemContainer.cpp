/*********************************************************************
** Program name: Source file for Item Container
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file that contains functions definitions for our item container data structure. Has accessor functions, modifier functions, constructor, and functions to add and delete items
*********************************************************************/
#include"itemContainer.hpp"

itemContainer::itemContainer() //constructor that initializes unused pointers to null, which will symbolize empty container
{
    headItem = nullptr;
    tailItem = nullptr;
}

Item* itemContainer::getHead() //accessor function for the container's head pointer
{
    return headItem;
}

Item* itemContainer::getTail() //accessor function for the container's tail pointer
{
    return tailItem;
}

void itemContainer::setHead(Item* itemPtr) //modifier function for the container's head pointer
{
    headItem = itemPtr;
}

void itemContainer::setTail(Item* itemPtr) //modifier function for the container's head pointe
{
    tailItem = itemPtr;
}

void itemContainer::addPotion() //create potion object and add to container
{

    Item* newItem = new Item("Potion"); //use constructor to create item with name "potion"

    newItem->setNext(headItem); //set the previous head to come after the new object
    headItem = newItem; //make the new object the new head of the list

}

void itemContainer::addEscapeRope() //create escape rope object and add to container
{

    Item* newItem = new Item("Escape Rope"); //use constructor to create item with name "Escape rope"

    newItem->setNext(headItem);
    headItem = newItem;
}

void itemContainer::removeItem()
{
    if(headItem == nullptr) //do not allow deletion if bag is empty - this will result in segfault
        cout << "The bag is empty!" << endl; //confirm bag is empty

    else //delete item from memory if bag is not empty
    {
        Item* temp = headItem;
        headItem = headItem->getNext();
        delete temp;
    }
}

bool itemContainer::isEmpty() //boolean function to check if container is empty
{
    if(headItem==nullptr) //if the head is null, the container is empty, so return true
        return true;

    else //otherwise the container is not empty
        return false;
}
