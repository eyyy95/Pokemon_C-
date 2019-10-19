/*********************************************************************
** Program name: Source file for derived Potion space class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for derived potion space class. Only modified value is the space type identifier integer - driver program will add potion to container accordingly if this type of space is encountered
*********************************************************************/
#include"potionSpace.hpp"

potionSpace::potionSpace()
{
    spaceType = 4; //change identifier type to respective value; driver program will carry out the respective functions
}

Pokemon* potionSpace::getSpacePokemon()
{
    return nullptr; //this space doesn't contain any pokemon, so this will return a nullptr
}
