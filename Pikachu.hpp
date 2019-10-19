#ifndef PIKACHU_HPP
#define PIKACHU_HPP
#include"pokemon.hpp"

class Pikachu: public Pokemon
{

public:
    Pikachu();
    void fullRestore();
    void battleAttack(Pokemon *opponent);
};
#endif // PIKACHU_HPP
