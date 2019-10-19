/*********************************************************************
** Program name: Source file for Derived Rattata Space Object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for our derived Rattata Space object. One of our derived classes that contains pointer to Rattata object
*********************************************************************/
#include"rattataSpace.hpp"

rattataSpace::rattataSpace()
{
    spacePokemon = new Rattata(); //dynamically create Rattata object for the space to point to; this will be opponent for the main character
    spaceType = 3; //mark the space type with unique number. Will be essential in determining what type of functions will be called to represent the main character's interaction
}

rattataSpace::~rattataSpace() //destructor to clear the dynamically allocated object after runtime
{
    delete spacePokemon;
}
