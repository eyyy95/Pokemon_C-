/*********************************************************************
** Program name: Header file for Potion Space derived class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Header file for Potion space derived class.
*********************************************************************/
#ifndef POTIONSPACE_HPP
#define POTIONSPACE_HPP
#include"Space.hpp" //include abstract base class

class potionSpace: public Space //inheriting from abstract Space base class
{
public:
    potionSpace(); //default constructor initializes member variables, and modifies space type to identify itself as space containing potion
    Pokemon* getSpacePokemon(); //accessor function that will return nullptr since this isn't a pokemon space
};
#endif // POTIONSPACE_HPP
