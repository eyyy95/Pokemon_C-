#ifndef POKEMONSPACE_HPP
#define POKEMONSPACE_HPP
#include"Space.hpp"


class pokemonSpace: public Space
{
protected:
    Pokemon* spacePokemon; //pointer variable that will point to the space's respective Pokemon character/object

public:
    pokemonSpace(); //randomly create a Pokemon object to fill the space
    Pokemon* getSpacePokemon(); //return the Pokemon within the space

};
#endif // POKEMONSPACE_HPP
