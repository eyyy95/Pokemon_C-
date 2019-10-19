/*********************************************************************
** Program name: Source file for derived class Pokemon Space
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for our derived class POkemon space - contains pointer pointing to residing pokemon. This class will further be derived from for the Rattata space and Pidgey space
*********************************************************************/
#include"pokemonSpace.hpp"

pokemonSpace::pokemonSpace()
{
    spacePokemon = nullptr; //initialize member variables, including space pokemon - this will be created in derived classes
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    spaceType = 1;

}

Pokemon* pokemonSpace::getSpacePokemon() //return the pointer to the space's pokemon - will be needed for battle functions
{
        return spacePokemon;
}




