/*********************************************************************
** Program name: Source file for derived PIdgey Space class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Derived class from Space abstract class for Pidgey space. Contains pointer pointing to Pidgey object
*********************************************************************/
#include"pidgeySpace.hpp"

pidgeySpace::pidgeySpace()
{
    spacePokemon = new Pidgey(); //creates PIdgey object for member pointer to point to
    spaceType = 2; //adjusts identifier integer to unique value
}

pidgeySpace::~pidgeySpace() //destructor removes dynamically created Pidgey object to prevent memory leaks
{
    delete spacePokemon;
}
