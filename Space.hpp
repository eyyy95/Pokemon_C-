/*********************************************************************
** Program name: Header file for Space abstract class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Header file for our abstract Space class, from which we will derive several space classes to be used in our linked space Map object
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include<cstdlib> //needed for rand() function
#include"pokemon.hpp" //needed for virtual function definition
#include"Pikachu.hpp"
#include"Pidgey.hpp"
#include"Rattata.hpp"

class Space //base class Space to be derived from
{
protected:
    Space *top; //pointers to adjacent spaces, similar to linked list nodes, but in 4 cardinal directions
    Space *bottom;
    Space *left;
    Space *right;
    int spaceType; //integer that will differentiate our individual derived space class types


public:
    Space(); //default constructor
    Space* getTop(); //return the individual pointers of a space
    Space* getBottom();
    Space* getRight();
    Space* getLeft();
    int getSpaceType();
    void setTop(Space* pointer); //functions that allow us to modify the individual pointers of each space object
    void setBottom(Space* pointer);
    void setLeft(Space* pointer);
    void setRight(Space* pointer);
    virtual Pokemon* getSpacePokemon() = 0; //virtual function that will be defined only in the derived spaces pointing to Pokemon objects


};
#endif // SPACE_HPP
