/*********************************************************************
** Program name: Header file for Item Object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Header file for Item object that constitutes our item linked-list container
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include<string>
using std::string;

class Item
{
protected:
    string itemName; //string member for the item's name
    Item* next; //next pointer to the next item - item container will be in the style of a single linked-list for simplicity

public:
    Item();
    Item(string inputName);
    void setNext(Item* nextItem);
    Item* getNext();

};
#endif // ITEM_HPP
