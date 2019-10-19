/*********************************************************************
** Program name: Source file for abstract Pokemon base class
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for our abstract Pokemon base class that we will derive from to create our individual Pokemon characters
*********************************************************************/
#include"pokemon.hpp"

Pokemon::Pokemon() //initialize all member variables with a value
{
    Attack = 0;
    Defense = 0;
    maxHealth = 0;
    Health = 0;
    pokemonType = 0;
}

bool Pokemon::checkFaint() //boolean function to check if the Pokemon character has fainted
{
    if(Health <= 0) //If health has fallen below 0, the pokemon has fainted
        return true;

    else //otherwise the pokemon is still conscious and battle ready
        return false;

}

int Pokemon::getAttack() //accessor functions for the individual member variables
{
    return Attack;
}

int Pokemon::getDefense()
{
    return Defense;
}

int Pokemon::getHealth()
{
    return Health;
}


int Pokemon::getType()
{
    return pokemonType;
}

void Pokemon::setHealth(int health) //modifier functions for individual member variables
{
    Health = health;
}

void Pokemon::inflictDamage(int Damage) //inflicts damage by adjusting the Pokemon's health variable according to the parameter amount
{
    Health = Health - Damage;
}

void Pokemon::instantDeath() //function that instantly reduces Pokemon's health to 0, resulting in instant faint/death
{
    Health = 0;
}

void Pokemon::restoreHealth(int healthAmount) //restores health by adjusting the POkemon's health variable according to the parameter amount
{

    Health = Health + healthAmount;
    if(Health>maxHealth) //prevents health from exceeding max value, even if potions restore health beyond max
        Health = maxHealth;
}

