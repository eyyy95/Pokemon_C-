/*********************************************************************
** Program name: Source file for Space abstract class
** Author: Edward Yeow
** Date: 3/19/19
** Description:Source file for Space abstract class, which we will use to derive 2 pokemon space objects and 2 item space objects. Contains four space pointers pointing to adjacent spaces in 4 cardinal directions
*********************************************************************/
#include"Space.hpp"

Space::Space() //initialize all four space pointers to nullptrs; that way they start off as null and do not require further adjustments unless they are being used
{
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    spaceType = 0; //initialize space type to 0 - will be used to identify space types in derived classes

}



Space* Space::getBottom() //accessor functions for the member pointer values. Returns space pointer
{
    return bottom;
}

Space* Space::getTop()
{
    return top;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getLeft()
{
    return left;
}

int Space::getSpaceType()
{
    return spaceType;
}


void Space::setTop(Space* pointer) //modifier functions for the space pointer values- needed to adjust variables when creating linked list/map structure of spaces
{
    top = pointer;

}

void Space::setBottom(Space* pointer)
{
    bottom = pointer;
}

void Space::setLeft(Space* pointer)
{
    left = pointer;
}

void Space::setRight(Space* pointer)
{
    right = pointer;
}
