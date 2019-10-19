/*********************************************************************
** Program name: Source file for Map object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for Map object, which is our linked-space object. Constructor will dynamically create polymorphic objects randomly then use for loops to link the pointers together and make any unused pointers point to null
*********************************************************************/
#include"map.hpp"

Map::Map() //constructor that will randomly generate different types of spaces for the map each time the game is run
{
    int randomNumber;
    randomNumber = rand()%2 + 1; //the first space will either have a Pidgey or Rattata

    if(randomNumber == 2)
        map[0] = new pidgeySpace();
    else
        map[0] = new rattataSpace();

    randomNumber = rand()%100 + 1;
    if(randomNumber == 100) //1% chance that we find the escape rope early. If the escape rope is found now, the player automatically wins the game without having to fight the remaining pokemon
        map[1] = new escapeRopeSpace();
    else if(randomNumber%2 == 0) //49% chance that the second space will have a potion for the player
        map[1] = new potionSpace();
    else //51% chance that the player will encounter another opponent
        map[1] = new pidgeySpace();

    randomNumber = rand()%3 + 1; //generate either a potion or another pokemon - skewed towards generating a pokemon
    if(randomNumber == 3) //33% chance of generating potion space
        map[2] = new potionSpace();
    else if(randomNumber == 2) //otherwise create space containing pokemon. 33% each of creating Rattata or Pidgey
        map[2] = new rattataSpace();
    else
        map[2] = new pidgeySpace();


    randomNumber = rand()%3 + 1; //generate either a potion or a pokemon - skewed towards generating a pokemon
    if(randomNumber == 3)
        map[3] = new potionSpace();
    else if(randomNumber == 2)
        map[3] = new rattataSpace();
    else
        map[3] = new pidgeySpace();

    randomNumber = rand()%3 + 1; //generate either a potion or a pokemon - skewed towards generating a pokemon
    if(randomNumber == 3)
        map[4] = new potionSpace();
    else if(randomNumber == 2)
        map[4] = new rattataSpace();
    else
        map[4] = new pidgeySpace();

    if(map[1]->getSpaceType()==5) //if the escape rope was found early, create a space with a pokemon for the final step
        map[5] = new rattataSpace();
    else
        map[5] = new escapeRopeSpace(); //otherwise the final step will have the escape rope, which guarantees victory


  for(int i=0; i<6; ++i) //our map is a linear train structure, so there are no spaces above or below any spaces. Set these to null using for-loop
    {
      map[i]->setTop(nullptr);
      map[i]->setBottom(nullptr);
    }

   map[0]->setLeft(nullptr); //set our left and right edges to null so that we don't go across bounds
  map[5]->setRight(nullptr);

  for(int i=0; i<5; ++i) //use loop to link all of our current spaces together. Do 5, because 6+ 1 will access out of the bounds of the array
    {
      map[i]->setRight(map[i+1]); //link the second space to come after the first space
      map[i+1]->setLeft(map[i]); //link the first space to come before the second space
    }

    currentSpace = map[0]; //set our current space at the first space of the map
}

Map::~Map() //destructor to clear all dynamically created spaces in our map, to prevent memory leaks
{

  for(int i = 0; i<6; ++i) //for loop to go through and delete each individual element
    delete map[i];


}

void Map::setCurrentSpace(Space* location) //modifier function for current location - accepts Space pointer as argument
{
    currentSpace = location;
}

Space* Map::getCurrentSpace() //accessor function for current location. Returns pointer to the current space
{
    return currentSpace;
}

void Map::moveBackward() //function to move backwards on the map. Ended up not using
{
    if(currentSpace->getLeft() == nullptr)
    {
        cout << "You cannot move backward!" << endl;
    }

    else
    {
        currentSpace = currentSpace->getLeft();
    }
}

void Map::moveForward() //function to move forward on the map
{
    if(currentSpace->getRight() == nullptr) //prevent user from moving forward if the next space is null, or non-existent
    {
      cout << "You cannot move forward!" << endl;
    }

    else //otherwise, allow user to move forward by accessing the right space pointer
    {
        currentSpace = currentSpace->getRight(); //make the space after the current space become the new current space
    }
}
