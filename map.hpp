/*********************************************************************
** Program name: Header file for our Map Linked-Space structure
** Author: Edward Yeow
** Date: 3/19/19
** Description: Contains declaration for our Map linked-space structure and all member functions and variables
*********************************************************************/
#ifndef MAP_HPP
#define MAP_HPP
#include"Space.hpp" //include all derived spaces since Map can consist of all different types of spaces
#include"pokemonSpace.hpp"
#include"pidgeySpace.hpp"
#include"rattataSpace.hpp"
#include"potionSpace.hpp"
#include"escapeRopeSpace.hpp"

class Map
{

private:
  Space* map[6]; //array of 6 spaces, as detailed by project requirements
  Space* currentSpace; //pointer to the current space inhabited by the main character

public:
  Map();//initialize pointers with space objects - rand() will be used randomly create different types of spaces to fill each individual space of the map
  ~Map(); //destructor clears dynamic memory
  void setCurrentSpace(Space* location); //modifier function
  Space* getCurrentSpace(); //accessor function
  void moveForward(); //move forward by using the right pointer
  void moveBackward(); //move backward by using the left pointer - not really used
}
;
#endif
