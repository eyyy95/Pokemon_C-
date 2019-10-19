/*********************************************************************
** Program name: Header file for abstract Pokemon base class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Header file containing declarations of class and its member variables for the abstract Pokemon base class
*********************************************************************/
#ifndef POKEMON_HPP
#define POKEMON_HPP
#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

class Pokemon //base class
{
protected:
    int Attack; //stats for each individual pokemon - each derived pokemon will have their own respective stats
    int Defense;
    int maxHealth;
    int Health; //health will determine if Pokemon has fainted or not
    int pokemonType; //integer value to differentiate the different types of pokemon - will be adjusted in derived class constructors

public:
    Pokemon();
    bool checkFaint(); //boolean function to check if pokemon is fainted
    int getAttack();
    int getDefense();
    int getHealth();
    void setHealth(int health);
    void instantDeath(); //function that will instantly kill opponent
    void restoreHealth(int healthAmount); //function that can restore health
    virtual void fullRestore() = 0;
    int getType();
    void inflictDamage(int damage); //function to inflict damage to the pokemon after attack
    virtual void battleAttack(Pokemon *opponent) = 0; //conduct attack on an opponent, take pointer as parameter since we're working with polymorphic objects
//virtual function since the attack function will be modified to encode each individual pokemon's abilities within
};
#endif // POKEMON_HPP
