#ifndef PIDGEY_HPP
#define PIDGEY_HPP
#include"pokemon.hpp"

class Pidgey: public Pokemon
{
public:
    Pidgey();
    void fullRestore();
    void battleAttack(Pokemon *opponent);
};
#endif // PIDGEY_HPP
