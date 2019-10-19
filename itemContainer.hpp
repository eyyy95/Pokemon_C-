/*********************************************************************
** Program name: Header file for Item Container Linked-List Structure
** Author: Edward Yeow
** Date: 3/19/19
** Description: The item container structure is similar to single-linked list structure, in that each individual item has a pointer pointing to the next item only.
*********************************************************************/
#ifndef ITEMCONTAINER_HPP
#define ITEMCONTAINER_HPP
#include<iostream>
#include"item.hpp"
using std::cout;
using std::endl;

class itemContainer
{
private:
    Item* headItem; //pointer to the head of the list
    Item* tailItem; //pointer to the tail of the list. Not really used in this program

public:
    itemContainer();
    void setTail(Item* itemPtr); //modifiers
    void setHead(Item* itemPtr);
    Item* getHead(); //accessors
    Item* getTail();
    void addPotion(); //add item with potion name
    void addEscapeRope(); //add item with escape rope name
    void removeItem(); //remove item from list structure
    bool isEmpty(); //check if list is empty
};
#endif // ITEMCONTAINER_HPP
