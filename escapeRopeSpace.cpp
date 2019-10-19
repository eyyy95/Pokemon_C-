/*********************************************************************
** Program name: Source file for derived Escape Rope Space
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for derived Escape Rope space class. Similar logic to the potion space, where the only unique adjustment is the space type - driver program handles all other functions for the game
*********************************************************************/
#include"escapeRopeSpace.hpp"

escapeRopeSpace::escapeRopeSpace() //adjust the space's identifier integer. Driver program will call on respective functions for gameplay when this space is encountered
{
    spaceType = 5;
}

Pokemon* escapeRopeSpace::getSpacePokemon()
{
    return nullptr;
}
