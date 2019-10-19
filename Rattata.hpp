#ifndef RATTATA_HPP
#define RATTATA_HPP
#include"pokemon.hpp"

class Rattata: public Pokemon
{
public:
    Rattata();
    void fullRestore();
    void battleAttack(Pokemon *opponent);
};
#endif // RATTATA_HPP
