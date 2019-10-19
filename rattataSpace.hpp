/*********************************************************************
** Program name: Header file for derived Rattata Space Object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Header file for our derived Rattata space object. Defines our derived class and any associated member functions
*********************************************************************/
#ifndef RATTATASPACE_HPP
#define RATTATASPACE_HPP
#include"pokemonSpace.hpp" //base class
#include"Rattata.hpp" //include for pokemon object that the space will point to

class rattataSpace: public pokemonSpace //derived from another base class
{ //does not require any unique private variables
public:
    rattataSpace(); //constructor will initialize member variables with appropriate values/objects
    ~rattataSpace(); //destructor to clear dynamic memory
};

#endif // RATTATASPACE_HPP
